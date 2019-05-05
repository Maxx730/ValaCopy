public class Clipboard : GLib.Object {
    private Gtk.Clipboard board = null;
    public signal void OnTextCopied( string val );

    construct {

    }

    public Clipboard() {

    }

    public virtual void Start() {

    }

    public string GetContents(){
        return "";
    }

    private void OnClipboardEvent( Gdk.EventOwnerChange event ){
        print("CLIP CHANGED\n");
    }
}

