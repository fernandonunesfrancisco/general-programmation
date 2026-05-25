package identity;

public abstract class Person {
    private String fullName;
    private String birthDate;
    private Address address;

    public Person(String fullName, String birthDate, Address address) {
        setFullName(fullName);
        setBirthDate(birthDate);
        setAddress(address);
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Person{" +
                "fullName='" + fullName + '\'' +
                ", birthDate='" + birthDate + '\'' +
                ", address=" + address +
                '}';
    }
}
