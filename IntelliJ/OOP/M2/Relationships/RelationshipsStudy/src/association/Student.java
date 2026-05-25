package association;

import identity.Address;
import identity.Person;

public class Student extends Person {

    private String major;
    private String registrationNumber;
    public Student(String fullName, String birthday, Address address, String major, String registrationNumber) {
        super(fullName, birthday, address);
        setMajor(major);
        setRegistrationNumber(registrationNumber);
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    @Override
    public String toString() {
        return super.toString()+ "Student{" +
                "major='" + major + '\'' +
                ", registrationNumber='" + registrationNumber + '\'' +
                '}';
    }
}
