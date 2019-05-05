public class Application : Gtk.Application {
    private Clip[] clips = {};

    public Application () {
        Object (
            application_id: "com.github.maxx730.test",
            flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
        var window = new Window( this );
        Data dat = new Data();
        GLib.Settings settings = new GLib.Settings("com.github.Maxx730.kcopy");

        //Listens for the callback from the data object to display the clips
        //in the TreeView, this needs to be initialized BEFORE we run the original get clips method;
        dat.row_callback.connect(( newClips ) => {
            print("ABOUT TO DISPLAY CLIPS\n");

            window.DisplayClips( newClips );
        });

        //BEGIN INITIALIZATIONS HERE.
        //Build our database if its the first time running the application.
        bool first_run = settings.get_boolean( "initial-run" );
        //Once the table has been created set the setting for initial run to false;
        dat.callback_event.connect( ( val ) => {
            print(val.to_string() + "\n");
            settings.set_boolean( "initial-run",val );
            first_run = val;
        });

        if ( !first_run ) {
            dat.CreateTable();
        } else {
            //If it is not the first time running then just try and pull clips from the database.
            dat.GetClips();
        }

        //BEGINNING OF INSERT LOGIC

        //Initialize our clipboard object and begin listening to when the data in the clipboard has changed.
        Gtk.Clipboard clipboard = Gtk.Clipboard.get_for_display( Gdk.Display.get_default(),Gdk.SELECTION_CLIPBOARD );
        clipboard.owner_change.connect( ( event ) => {
            //Grab the value of the clipboard.
            string value = clipboard.wait_for_text().replace("'","\'");

            //Insert the new clip into the database.
            dat.InsertClip( value );

            //Notify the user.
            Notify( "Clip Added","'" + value + "' has been saved into your history.");
        });

        //When the database has had a clip inserted, this callback event is fired.
        dat.insert_callback.connect( ( clip ) => {
            print("INSERT CALLBACK\n");

            //After inserting the new clip we want to rebuild the clip list.
            //First we need to clear out the clip list.
            window.ResetClips();
            //Now re-render the list with updated clips.
            dat.GetClips();
        });

        //END OF INSERT LOGIC

        //Listens to the TreeView for a double click, when it happens it sets
        //the new value to the clipboard which in turn causes all previous events
        //to fire.
        window.on_clip_select.connect(( value ) => {
            clipboard.set_text( value,value.char_count() );
        });

        //When a user hits yes to clear the data in the settings we want to run
        //a clearing method from the data object.
        window.on_clear_data.connect(() => {
           dat.DropTable();
           Notify( "History Cleared","Clipboard history has been cleared out." );
           window.ResetClips();
        });

        window.on_search.connect(( value ) => {
            window.ResetClips();
            dat.SearchClips( value );
        });

        //Add our new window to the application.
        add_window ( window );
    }

    //Method used to create and show a notification.
    public void Notify ( string title,string message ) {
        Notification notif = new Notification( title );
        notif.set_body( message );
        notif.set_icon( new GLib.ThemedIcon( "process-completed" ) );
        send_notification( "kcopy.app", notif );
    }
}
