package association;

import identity.Address;
import identity.Person;

public class Teacher extends Person {
    private String subject;
    private String registrationNumber;


    public Teacher(String fullName, String birthday, Address address, String subject, String registrationNumber) {
        super(fullName, birthday, address);
        setSubject(subject);
        setRegistrationNumber(registrationNumber);
    }
    public void setSubject(String subject) {
        this.subject = subject;
    }
    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }
    public String getSubject() {return subject;}
    public String getRegistrationNumber() {return registrationNumber;}

    @Override
    public String toString() {
        return "Teacher{" + "subject=" + subject + ", registrationNumber=" + registrationNumber + '}';
    }
}
