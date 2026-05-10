package agregation;

public class Address {
    private String street;
    private String city;
    private String state;
    private String cep;
    private String complement;

    public Address(String street, String city, String state, String cep){
        setStreet(street);
        setCity(city);
        setState(state);
        setCep(cep);
        setComplement("");
    }

    public Address(String street, String city, String state, String cep, String complement) {
        setStreet(street);
        setCity(city);
        setState(state);
        setCep(cep);
        setComplement(complement);
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getComplement() {
        return complement;
    }

    public void setComplement(String complement) {
        this.complement = this.complement;
    }
}
