import java.util.Scanner;

public class Part2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập một ký tự: ");
        char ch = scanner.next().toLowerCase().charAt(0);

        // Kiểm tra ký tự nhập vào
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            System.out.println(ch + " là nguyên âm.");
        } else if ((ch >= 'a' && ch <= 'z')) {
            System.out.println(ch + " là phụ âm.");
        } else {
            System.out.println(ch + " không phải là ký tự alphabet.");
        }
    }
}
