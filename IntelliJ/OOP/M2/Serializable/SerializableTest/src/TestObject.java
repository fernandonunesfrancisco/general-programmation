import java.io.Serilizable;
public class TestObject implements Serializable{
    private String name;
    private double number;

    public TestObject(String name, double number) {
        this.name = name;
        this.number = number;
    }
}
