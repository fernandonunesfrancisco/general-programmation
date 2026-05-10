package heritage;

public class Fryer extends HouseholdAppliance{
    private int temperature;
    private final int MAXtemperature;
    private int time;
    private boolean closed;
    public Fryer(int MAXtemperature, String brandModel){
        super(); //not needed
        setBrandModel(brandModel);
        this.MAXtemperature = MAXtemperature;
        temperature=0;
        time=0;
        closed=true;
    }
    public void open(){
        closed=false;
    }
    public void close(){
        closed=true;
    }
    public void setTemperature(int temperature){
        if(isOn()){
            this.temperature=temperature;
        }
    }
    public void setTime(int time){
        if(isOn()){
            this.time=time;
        }
    }
    public boolean getClosed(){ return closed;}
    @Override
    public void turnOn(){
        if(closed){
            super.turnOn();
        }
    }
    @Override
    public String toString(){
        return super.toString()+" Temperature:"+temperature+" Maxtemp:"+MAXtemperature+" Time:"+time+" Closed:"+closed;
    }
}
