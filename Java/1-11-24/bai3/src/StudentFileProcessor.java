import java.io.*;
import java.util.ArrayList;

public class StudentFileProcessor {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();

        // Đọc dữ liệu từ file input.txt
        try (BufferedReader reader = new BufferedReader(new FileReader("input.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String name = line.trim();

                // Đọc tuổi
                line = reader.readLine();
                int age;
                try {
                    age = Integer.parseInt(line.trim());
                    if (age <= 0) throw new NumberFormatException("Tuổi phải là số nguyên dương.");
                } catch (NumberFormatException e) {
                    System.out.println("Dữ liệu không hợp lệ cho tuổi: " + line);
                    skipInvalidRecord(reader);  // Bỏ qua bản ghi không hợp lệ
                    continue;
                }

                // Đọc số điện thoại
                line = reader.readLine();
                String phone = line.trim();

                // Thêm đối tượng Student vào danh sách
                students.add(new Student(name, age, phone));

                // Bỏ qua dòng ngăn cách nếu có
                reader.readLine();
            }

        } catch (IOException e) {
            System.out.println("Lỗi khi đọc file: " + e.getMessage());
        }

        // Ghi danh sách sinh viên vào file Persons.obj
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Persons.obj"))) {
            for (Student student : students) {
                oos.writeObject(student);
            }
            System.out.println("Ghi thành công danh sách sinh viên vào file Persons.obj.");
        } catch (IOException e) {
            System.out.println("Lỗi khi ghi file: " + e.getMessage());
        }
    }

    // Phương thức bỏ qua một bản ghi không hợp lệ
    private static void skipInvalidRecord(BufferedReader reader) throws IOException {
        reader.readLine();  // Bỏ qua dòng số điện thoại
        reader.readLine();  // Bỏ qua dòng ngăn cách
    }
}
