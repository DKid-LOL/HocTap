import java.io.Serializable;

public class Member implements Serializable {
    private String memberID;
    private String memberName;
    private String address;

    // Hàm tạo có tham số
    public Member(String memberID, String memberName, String address) {
        this.memberID = memberID;
        this.memberName = memberName;
        this.address = address;
    }

    // Hàm tạo mặc định
    public Member() {}

    // Getter và Setter cho memberID
    public String getMemberID() {
        return memberID;
    }

    public void setMemberID(String memberID) {
        this.memberID = memberID;
    }

    // Getter và Setter cho memberName
    public String getMemberName() {
        return memberName;
    }

    public void setMemberName(String memberName) {
        this.memberName = memberName;
    }

    // Getter và Setter cho address
    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    // Ghi đè phương thức toString
    @Override
    public String toString() {
        return "MemberID: " + memberID + ", Name: " + memberName + ", Address: " + address;
    }
}
