import java.io.*;
import java.util.ArrayList;
import java.util.regex.Pattern;

public class ClubManager {
    private ArrayList<Member> members;

    public ClubManager() {
        members = new ArrayList<>();
    }

    // Phương thức để thêm thành viên
    public void addMember(Member member) {
        members.add(member);
    }

    // Phương thức để xác thực memberID
    private boolean isValidMemberID(String memberID) {
        String regex = "^[TVA](MB|MT|MN)\\d{5}$";
        return Pattern.matches(regex, memberID);
    }

    // Phương thức nhập thông tin thành viên từ bàn phím
    public void inputMembers() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            System.out.print("Nhập ID Thành viên (định dạng: ABBCCCCC): ");
            String memberID = reader.readLine();
            if (!isValidMemberID(memberID)) {
                System.out.println("ID không hợp lệ. Vui lòng thử lại.");
                continue;
            }

            System.out.print("Nhập Tên Thành viên: ");
            String memberName = reader.readLine();

            System.out.print("Nhập Địa chỉ: ");
            String address = reader.readLine();

            Member member = new Member(memberID, memberName, address);
            addMember(member);

            System.out.print("Bạn có muốn thêm thành viên khác không? (y/n): ");
            String choice = reader.readLine();
            if (!choice.equalsIgnoreCase("y")) {
                break;
            }
        }
    }

    // Phương thức để tuần tự hóa (ghi) danh sách thành viên vào file
    public void serializeMembers(String filename) {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(filename))) {
            out.writeObject(members);
            System.out.println("Danh sách thành viên đã được ghi vào " + filename);
        } catch (IOException e) {
            System.out.println("Lỗi khi ghi thành viên: " + e.getMessage());
        }
    }

    // Phương thức để đọc danh sách thành viên từ file
    public void deserializeMembers(String filename) {
        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(filename))) {
            ArrayList<Member> deserializedMembers = (ArrayList<Member>) in.readObject();
            System.out.println("Danh sách Thành viên đã được đọc từ file:");
            for (Member member : deserializedMembers) {
                System.out.println(member);
            }
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi khi đọc danh sách thành viên: " + e.getMessage());
        }
    }

    public static void main(String[] args) throws IOException {
        ClubManager clubManager = new ClubManager();

        // Nhập thông tin thành viên
        clubManager.inputMembers();

        // Ghi danh sách thành viên vào file
        clubManager.serializeMembers("member_of_club.txt");

        // Đọc và hiển thị danh sách thành viên từ file
        clubManager.deserializeMembers("member_of_club.txt");
    }
}
