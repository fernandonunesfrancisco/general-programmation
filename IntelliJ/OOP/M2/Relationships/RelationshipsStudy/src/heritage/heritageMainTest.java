package heritage;

import java.util.Scanner;

public class heritageMainTest
{
    public static void main(String args[])
    {
        Fryer fryer= new Fryer(200, "Sony");
        fryer.setTemperature(2);
        System.out.println(fryer);
        fryer.turnOn();
        fryer.turnOff();
        fryer.setTime(88);
        System.out.println(fryer);
        fryer.open();
        fryer.turnOn();
        System.out.println(fryer);
        fryer.close();
        fryer.turnOn();
        fryer.setTemperature(5);
        fryer.setTime(30);
        System.out.println(fryer);
    }
}
