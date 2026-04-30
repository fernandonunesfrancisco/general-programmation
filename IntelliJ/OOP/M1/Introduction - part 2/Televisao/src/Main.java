//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Televisão t= new Televisão(5, 7, false);
        t.toString();
        t.subirCanal();

        t.ligar();
        t.descerCanal();
        t.subirCanal();
        t.aumentarVolume();
        System.out.println(t.toString());
    }
}