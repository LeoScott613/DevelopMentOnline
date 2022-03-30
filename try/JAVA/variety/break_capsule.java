public class break_capsule {
    public static void main(String args[]) {
        encapsule breaker=new encapsule("Initialization");
        DataArea getId=breaker.BadGetId();
        getId.setId(514);//this has caused an mistake, which is changing the data that should be unchangable directly
        //getId.setId() has changed the private data of breaker without the ¸ü¸ÄÆ÷
        System.out.println(getId.getId());
        System.out.println(breaker.BadGetId().getId());

        getId.setId(114);//set it back;
        getId=null;

        getId=breaker.GoodGetId();
        getId.setId(514);
        System.out.println(getId.getId());
        System.out.println(breaker.GoodGetId().getId());

        //String object doesn't have this problem.
        String outside=breaker.getName();
        outside="hhh you've changed.";
        System.out.println(outside+' '+breaker.getName());
    }
}
class DataArea {
    private int id;
    public DataArea(int i) {
        id=i;
    }
    public void setId(int i) {
        id=i;
    }
    public int getId() {
        return id;
    }
    protected Object clone() {
        DataArea cloneId=new DataArea(this.id);
        return cloneId;
    }
}
class encapsule {
    private String name;
    private DataArea id;
    public encapsule(String n) {
        name=n;
        id=new DataArea(114);
    }
    public DataArea BadGetId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public DataArea GoodGetId() {
        return (DataArea)id.clone();
    }
}