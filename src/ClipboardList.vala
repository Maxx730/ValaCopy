public class ClipboardList : Gtk.TreeView {

    private Gtk.ListStore list;
    private Gtk.TreeIter iter;
    private Gtk.TreePath path;
    private Gtk.TreeViewColumn column;

    public signal void on_select( string value );

    public ClipboardList () {
        list = new Gtk.ListStore( 3,typeof ( string ),typeof ( string ),typeof ( string ));
        set_model( list );
        set_fixed_height_mode( false );

        Gtk.TreeViewColumn id_top = new Gtk.TreeViewColumn();
        id_top.set_title("ID");

        Gtk.CellRendererText cell = new Gtk.CellRendererText();
        cell.set ("weight_set", true);
        cell.set ("weight", 700);

        Gtk.CellRendererText contents_rend = new Gtk.CellRendererText();
        contents_rend.set( "wrap_mode",true );
        contents_rend.set( "width_chars",100 );

        insert_column_with_attributes( -1,"ID",cell,"text",0 );
        insert_column_with_attributes( -1,"Contents",contents_rend,"text",1 );
        insert_column_with_attributes( -1,"Date",new Gtk.CellRendererText(),"text",2 );

        row_activated.connect( ( path,column ) => {
             if ( this.model.get_iter( out iter,path ) ) {
                string value = null;
                this.model.get( iter,1,out value );
                this.on_select( value );
             }
        });
    }

    public void DisplayList ( Clip[] clips ) {
        for ( int i = ( clips.length - 1 );i > -1;i-- ) {
            list.append( out iter );
            list.set( iter,0,i.to_string() + ".",1,clips[i].get_value(),2,clips[i].get_date() );
        }
    }

    public void ResetList () {
        list.clear();
    }
}
