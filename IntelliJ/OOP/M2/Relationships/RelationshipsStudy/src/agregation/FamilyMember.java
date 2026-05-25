package agregation;

import identity.Address;
import identity.Person;

import java.util.ArrayList;

public class FamilyMember extends Person {
    ArrayList<Family> families;
    public FamilyMember(String fullName, String birthday, Address address) {
        super(fullName, birthday, address);
        this.families = new ArrayList<>();
    }
}
