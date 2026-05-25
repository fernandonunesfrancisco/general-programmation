package composition;

public class Car {
    private String brand;
    private String model;

    private Engine engine;

    public Car(String brand, String model, String type, int power){
        this.brand=brand; this.model=model;

        engine= new Engine(type, power);
    }