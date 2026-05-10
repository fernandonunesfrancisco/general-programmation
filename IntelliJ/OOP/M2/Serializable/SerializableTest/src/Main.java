import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        String name;
        double bw, height;
        ArrayList<Object> person= Packaging.readBinFile("data.dat");
        while(true){
            System.out.printf("Registration number: %d.\n", (person.size()+1));
            System.out.printf("Enter the name of the person, 'END' to end the task:\n");
            name = input.nextLine();
            if(name.equals("END")){
                break;
            }
            System.out.printf("\nEnter body weight (kg): ");
            bw = input.nextDouble();
            System.out.printf("\nEnter height (m)......: ");
            height = input.nextDouble();
            person.add(new TestObject(name, bw, height));

            input.nextLine();
            System.out.printf("\n");
        }
    Packaging.readBinFile(person, "data.dat");
    }
}