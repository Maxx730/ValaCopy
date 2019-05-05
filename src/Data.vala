using Sqlite;

public class Data : GLib.Object {
    private Sqlite.Database db = null;
    private string errmsg;
    private int current = 0;
    private Clip[] clips;

    public signal void callback_event( bool value );
    public signal void row_callback( Clip[] clips );
    public signal void insert_callback( Clip clip );

    //Construct the class and make sure the sqlite database exists, if not create it.
    public Data(){
        print("INIT DATABASE\n");

        int ec = Sqlite.Database.open( "kcopy_data.db",out db );

        if ( ec != Sqlite.OK ) {
            print("ERROR OPENING DATABASE\n");
        }
    }

    public void DropTable () {
        if ( db != null ) {
            string query = "DELETE FROM clips";

            var ec = db.exec ( query,null,out errmsg );

            if ( ec != Sqlite.OK ) {
                print( "ERROR DROPPING TABLE\n" );
            } else {
                print( "TABLE DROPPED\n" );
            }

            callback_event( false );
        }
    }

    //If it is the first time opening the application make sure to create the clip table
    //in the sqlite database.
    public void CreateTable ( ) {
        if ( db != null ) {
            string query = "CREATE TABLE clips (
                id INTEGER PRIMARY KEY NOT NULL,
                value TEXT NOT NULL,
                date TEXT NOT NULL
            )";

            var ec = db.exec ( query,null,out errmsg );

            if ( ec != Sqlite.OK ) {
                print ( "ERROR CREATING DATABASE\n" );
            } else {
                print( "CREATED TABLE SUCCESSFULLY\n" );
            }

            callback_event( true );
        }
    }

    //Takes in the value of the new Clip we want to create, adds it to the database
    //sends a callback to the main application with the new clip.
    public void InsertClip ( string value ) {
        if ( db != null ) {
            string query = "INSERT INTO clips (value,date) VALUES('" + value + "',DATETIME('now')) ";

            var ec = db.exec( query,null,out errmsg );

            if ( ec != Sqlite.OK ) {
                print( "ERROR ADDING CLIP TO TABLE\n" );
                print( errmsg + "\n" );
            } else {
                print( "SUCCESS ADDING CLIP\n" );
                clips = {};

                //Create the new clip and set its value
                Clip newClip = new Clip();
                newClip.set_value( value );

                //Callback to main application
                insert_callback( newClip );
            }
        }
    }

    public void GetClips () {
        if ( db != null ) {
            print("PULLING CLIPS FROM DATABASE\n");
            string query = "SELECT * FROM clips";
            Sqlite.Statement stmt;
            clips = {};

            var ec = db.prepare_v2( query,query.length,out stmt );

            while ( stmt.step() == Sqlite.ROW ){
                Clip clip = new Clip();

                for ( int i = 0;i < stmt.column_count();i++ ) {
                    if ( stmt.column_name(i) == "value" ) {
                        clip.set_value( stmt.column_value( i ).to_text() );
                    }

                    if ( stmt.column_name( i ) == "date" ) {
                        clip.set_date( stmt.column_value( i ).to_text() );
                    }
                }

                clips += clip;
            }

            print("LIST BUILT: " + clips.length.to_string() + "\n");
            row_callback( clips );

            if ( ec != Sqlite.OK ) {
                print( "ERROR PULLING DATA FROM TABLE\n" );
            }
        }
    }

    public void SearchClips ( string term ) {
        if ( db != null ) {
            string query = "SELECT * FROM clips WHERE value LIKE '" + term + "%'";
            Sqlite.Statement stmt;

            var ec = db.prepare_v2( query,query.length,out stmt );

            while ( stmt.step() == Sqlite.ROW ){
                Clip clip = new Clip();

                for ( int i = 0;i < stmt.column_count();i++ ) {
                    if ( stmt.column_name(i) == "value" ) {
                        clip.set_value( stmt.column_value( i ).to_text() );
                    }

                    if ( stmt.column_name( i ) == "date" ) {
                        clip.set_date( stmt.column_value( i ).to_text() );
                    }
                }
            }

            row_callback( clips );

            if ( ec != Sqlite.OK ) {
                print( "ERROR PULLING DATA FROM TABLE\n" );
            }
        }
    }
}