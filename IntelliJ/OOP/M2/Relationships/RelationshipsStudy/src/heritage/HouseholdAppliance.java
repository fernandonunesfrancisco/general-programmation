package heritage;

public abstract class HouseholdAppliance {
    private String brandModel;
    private boolean on;

    public void setBrandModel(String brandModel) {
        this.brandModel = brandModel;
    }

    public HouseholdAppliance(){
        on=false;
    }
    public void turnOn(){
        on=true;
    }
    public void turnOff(){
        on=false;
    }

    public boolean isOn(){ return on; }
    @Override
    public String toString(){
        return brandModel+". Turned on? "+on;
    }
}
