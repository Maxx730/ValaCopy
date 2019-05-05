public class Clip {
    private int id;
    private string value;
    private string date;

    public Clip ( ) {

    }

    public int get_id () {
        return this.id;
    }

    public string get_value() {
        return this.value;
    }

    public string get_date() {
        return this.date;
    }

    public void set_value ( string value ) {
        this.value = value;
    }

    public void set_date ( string date ) {
        this.date = date;
    }
}