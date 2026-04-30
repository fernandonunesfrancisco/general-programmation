//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Produto p=new Produto("banana", 13.00);
        System.out.println(p);
        p.atualizaPreco(10);
        System.out.println(p);

        p.fazerPromocao();
        System.out.println(p);
    }
}