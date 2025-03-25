import java.util.Scanner;

public class Part3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập số tiền gửi: ");
        double amount = scanner.nextDouble();
        double interestRate;

        // Xác định lãi suất dựa trên số tiền gửi
        if (amount <= 2000) {
            interestRate = 0.04;
        } else if (amount <= 7000) {
            interestRate = 0.045;
        } else {
            interestRate = 0.05;
        }

        // Tính lãi suất thu được trong một năm
        double interest = amount * interestRate;
        System.out.println("Số tiền lãi trong một năm: " + interest);
    }
}
