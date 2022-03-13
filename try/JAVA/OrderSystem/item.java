package JAVA.OrderSystem;

public class item {
    private int id;
    private String name;
    private long date;
    private String address;
    public item() {}
    public void new_id(int i) {
        id=i;
    }
    public void new_name(String n) {
        name=n;
    }
    public void new_date(long d) {
        date=d;
    }
    public void new_address(String add) {
        address=add;
    }
    public int look_id() {
        return id;
    }
    public String look_name() {
        return name;
    }
    public long look_date() {
        return date;
    }
    public String look_address() {
        return address;
    }
}
