public class Window : Gtk.ApplicationWindow {
    private Gtk.Application app = null;
    private Clipboard clipboard;
    private ClipboardList list;
    private Gtk.Statusbar status;
    private Menu menu;
    private HeaderBar header;
    private Gtk.ScrolledWindow scroll;
    private Gtk.Dialog dia;

    public signal void on_clip_select( string value );
    public signal void on_search ( string value );
    public signal void on_clear_data ();

    public Window ( Gtk.Application application ) {
        Object (
            application: application
        );

        this.app = application;
    }

    construct {
        title = "First Vala App";
        window_position = Gtk.WindowPosition.CENTER;
        set_default_size( 800,600 );

        header = new HeaderBar( );
        list = new ClipboardList();
        clipboard = new Clipboard();
        status = new Gtk.Statusbar();
        menu = new Menu();
        scroll = new Gtk.ScrolledWindow( null,null );

        //Settings button click handler, opens a settings dialog
        //whDialogich in turn may or may not open sub dialogs if something inside is clicekd.
        header.on_settings_clicked.connect( () => {
            //Create all of the Dialogs used within the preferences window.
            dia = new Gtk.Dialog.with_buttons( "TEST", this, Gtk.DialogFlags.MODAL, Gtk.Stock.OK, Gtk.ResponseType.OK, null );
            dia.set_default_size( 400,400 );
            dia.title = "Settings";

            //BEGIN MAIN SETTINGS DIALOG
            Gtk.Box content = dia.get_content_area();
            content.set_border_width( 10 );
            content.set_spacing( 10 );

            Gtk.Label general = new Gtk.Label( "General" );
            general.set_xalign( 0 );

            content.add( general );
            content.add( new Gtk.Separator( Gtk.Orientation.HORIZONTAL ) );

            Gtk.Switch notif_toggle = new Gtk.Switch();
            Gtk.Label notif_label = new Gtk.Label( "Show Notificaiton when clip copied." );
            notif_label.set_xalign( 0 );
            Gtk.Box notif_box = new Gtk.Box( Gtk.Orientation.HORIZONTAL,1 );
            notif_box.pack_start( notif_label );
            notif_box.add( notif_toggle );
            content.add( notif_box );

            notif_toggle.state_set.connect(( state ) => {
                GLib.Settings settings = new GLib.Settings("com.github.Maxx730.kcopy");
            });

            Gtk.Label imp = new Gtk.Label( "Data Management" );
     GLib.Settings settings = new GLib.Settings("com.github.Maxx730.kcopy");       imp.set_xalign( 0 );
            imp.set_yalign( -10 );
            imp.set_justify( Gtk.Justification.LEFT );

            content.add( imp );
            content.add( new Gtk.Separator( Gtk.Orientation.HORIZONTAL ) );

            Gtk.Box impbox = new Gtk.Box( Gtk.Orientation.VERTICAL,1 );
            impbox.set_spacing( 10 );
            Gtk.Button import = new Gtk.Button.with_label( "Import" );
            Gtk.Button export = new Gtk.Button.with_label( "Export" );

            Gtk.Box clearBox = new Gtk.Box( Gtk.Orientation.HORIZONTAL,1 );
            Gtk.Button clear = new Gtk.Button.with_label("Clear Records");

            clear.clicked.connect ( ( event ) => {
                //SHOW A CONFIRM DIALOG BOX TO CLEAR DATABASE.
                CreateClearDialog().show_all();
            });

            impbox.set_border_width( 10 );

            Gtk.Box importBox = new Gtk.Box( Gtk.Orientation.HORIZONTAL,1 );
            importBox.set_spacing( 10 );
            importBox.add( import );
            Gtk.Label import_explain = new Gtk.Label("Import previously exported clips file.");
            import_explain.set_xalign( 0 );
            importBox.pack_end( import_explain );

            impbox.pack_start( importBox );

            Gtk.Box exportBox = new Gtk.Box( Gtk.Orientation.HORIZONTAL,1 );
            exportBox.set_spacing( 10 );
            exportBox.add( export );
            Gtk.Label export_label = new Gtk.Label("Export clipboard data into file.");
            export_label.set_xalign( 0 );
            exportBox.add( export_label );

            impbox.add( exportBox );
            clearBox.add( clear );
            content.add( impbox );

            clearBox.set_spacing( 10 );
            Gtk.Label clear_label = new Gtk.Label( "Clears out the clipboard history (cannot be undone)." );
            clearBox.add( clear_label );

            content.add( clearBox );

            Gtk.Label about_label = new Gtk.Label( "About" );
            about_label.set_xalign( 0 );
            content.add( about_label );
            content.add( new Gtk.Separator( Gtk.Orientation.HORIZONTAL ) );
            content.add( new Gtk.Label( "Created by John Kinghorn" ) );

            dia.add_button( "Save",1 );

            dia.show_all();
            //END MAIN SETTINGS DIALOG.
        });

        var search_entry = new Gtk.Entry();
        var lay = new Gtk.Layout();
        var box = new Gtk.Box( Gtk.Orientation.VERTICAL,0 );

        list.set_valign( Gtk.Align.FILL );

        search_entry.set_icon_from_icon_name( Gtk.EntryIconPosition.PRIMARY,"system-search" );
        search_entry.set_hexpand( true );
        lay.set_hexpand( true );

        set_titlebar( header );

        search_entry.set_margin_bottom( 10 );
        search_entry.set_margin_top( 10 );
        search_entry.set_margin_left( 10 );
        search_entry.set_margin_right( 10 );
        search_entry.activate.connect(( event ) => {
            list.ResetList();
            on_search( search_entry.get_text() );
        });

        scroll.add( list );

        box.add( search_entry );
        box.add( new Gtk.Separator( Gtk.Orientation.HORIZONTAL ) );
        box.pack_start( scroll );

        status.push( status.get_context_id("com.github.Maxx730.kcopy"),"Idle..." );

        add( box );

        clipboard.Start();

        list.on_select.connect( ( val ) => {
            on_clip_select( val );
        });

        this.check_resize.connect(( event ) => {
            int width,height;
            get_size( out width,out height );
        });

        show_all();
    }

    //Method used to easily create a dialog asking if the user is sure they
    //would like to
    public Gtk.Dialog CreateClearDialog () {
            Gtk.Dialog conf = new Gtk.Dialog.with_buttons( "TEST", dia, Gtk.DialogFlags.MODAL, Gtk.Stock.YES, Gtk.ResponseType.ACCEPT, Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL );
            conf.response.connect(( response ) => {
                switch ( response ) {
                    case -3:
                        on_clear_data();
                        conf.close();
                    break;
                    default:
                        conf.close();
                    break;
                }
            });

            //BEGIN CLEAR DATABASE DIALOG.
            conf.set_border_width( 20 );
            Gtk.Box confirm = conf.get_content_area();
            confirm.add( new Gtk.Label("Are you sure you would like to clear out the clipboard database?") );
            //END CLEAR DATABASE DIALOG.
            return conf;
    }

    public void DisplayClips( Clip[] clips ) {
        print("CLIP LENGTH:  " + clips.length.to_string() + "\n");
        list.DisplayList( clips );
    }

    public void ResetClips () {
        list.ResetList();
    }
}