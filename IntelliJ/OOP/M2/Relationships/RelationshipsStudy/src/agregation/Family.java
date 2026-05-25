package agregation;

import java.util.ArrayList;

public class Family {
    ArrayList<FamilyMember> members;

    public Family(FamilyMember man, FamilyMember woman) {
        members = new ArrayList<>();
        members.add(man);
        members.add(woman);
    }


    public ArrayList<FamilyMember> getMembers() {
        return members;
    }

    public void addMember(FamilyMember member) {
        members.add(member);
    }
    public void removeMember(FamilyMember member) {
        members.remove(member);
    }
    @Override
    public String toString() {
        String s = "";
        for (FamilyMember member : members) {
            s += member.toString();
        }
    }
}
