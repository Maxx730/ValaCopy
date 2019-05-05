public class Settings : Gtk.Window {

    public Settings() {
        print("SETTINGS WINDOW\n");

        set_default_size( 400,600 );
        set_title( "Settings" );

        show();
    }

    public bool CloseSettings( bool resetValue ) {
        return !resetValue;
    }
}