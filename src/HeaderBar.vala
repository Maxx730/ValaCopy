public class HeaderBar : Gtk.HeaderBar {
    private bool settings_open = false;
    public signal void on_settings_clicked();

    public HeaderBar ( ) {
        set_title( "Clipboard" );
        set_show_close_button( true );

        Gtk.Button setting = new Gtk.Button.with_label( "Settings" );
        setting.clicked.connect( () => {
            this.on_settings_clicked();
        });


        pack_end( setting );
    }
}