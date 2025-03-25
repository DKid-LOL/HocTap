import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;
import java.util.Comparator;

class Account {
    String username;
    String password;
    String userType;
    int registerYear;
    String cookie;
    float price;

    public Account(String username, String password, String userType, int registerYear, String cookie, float price) {
        this.username = username;
        this.password = password;
        this.userType = userType;
        this.registerYear = registerYear;
        this.cookie = cookie;
        this.price = price;
    }

    @Override
    public String toString() {
        return String.format("%s\t%s\t%s\t%d\t%s\t%.2f", username, password, userType, registerYear, cookie, price);
    }
}

public class AccountManagement {
    static ArrayList<Account> accounts = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String choice;
        do {
            showMenu();
            choice = scanner.next();
            switch (choice) {
                case "1":
                    inputAccounts();
                    break;
                case "2":
                    sortAccountsByName();
                    break;
                case "3":
                    sortAccountsByPrice();
                    break;
                case "4":
                    analyzeAccounts();
                    break;
                case "5":
                    searchAccountsByTypeAndMinPrice();
                    break;
                case "6":
                    exitProgram();
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ, vui lòng thử lại.");
            }
        } while (!choice.equals("6"));
    }

    static void showMenu() {
        System.out.println("\nChương trình quản lý tài khoản:");
        System.out.println("|-------------------------------------------------------------------------------------------------------------------|");
        System.out.println("| 1. Nhap lieu |2. Sap xep username theo ten |3. Sap xep theo gia  |4. Phan tich  |5. Tim user theo ten | |62. Thoat |");
        System.out.println("|-------------------------------------------------------------------------------------------------------------------|");
        System.out.print("Lựa chọn của bạn: ");
    }

    static void inputAccounts() {
        System.out.print("Nhập tổng số tài khoản cần nhập: ");
        int total = scanner.nextInt();
        scanner.nextLine(); // Đọc bỏ dòng thừa sau khi nhập số

        for (int i = 0; i < total; i++) {
            System.out.println("Nhập vào thông tin tài khoản [" + (i + 1) + "]: ");
            System.out.print("Username: ");
            String username = scanner.nextLine();
            System.out.print("Password: ");
            String password = scanner.nextLine();
            System.out.print("User type: ");
            String userType = scanner.nextLine();
            System.out.print("Register year: ");
            int registerYear = scanner.nextInt();
            System.out.print("Price: ");
            float price = scanner.nextFloat();
            scanner.nextLine(); // Đọc bỏ dòng thừa

            if (price >= 0 && price <= 100000 && registerYear >= 2018) {
                accounts.add(new Account(username, password, userType, registerYear, "randomcookie", price));
            } else {
                System.out.println("Thông tin không hợp lệ. Vui lòng thử lại.");
                i--; // Lùi lại một lần lặp
            }
        }
    }

    static void sortAccountsByName() {
        Collections.sort(accounts, Comparator.comparing(a -> a.username));
        System.out.println("Danh sách tài khoản sau khi sắp xếp theo tên:");
        printAccounts();
    }

    static void sortAccountsByPrice() {
        accounts.sort((a1, a2) -> Float.compare(a2.price, a1.price));
        System.out.println("Danh sách tài khoản sau khi sắp xếp theo giá:");
        printAccounts();
    }

    static void analyzeAccounts() {
        int facebookCount = 0, twitterCount = 0, linkedinCount = 0;
        for (Account acc : accounts) {
            switch (acc.userType.toLowerCase()) {
                case "facebook":
                    facebookCount++;
                    break;
                case "twitter":
                    twitterCount++;
                    break;
                case "linkedin":
                    linkedinCount++;
                    break;
            }
        }
        System.out.println("Số lượng tài khoản:");
        System.out.println("Facebook: " + facebookCount);
        System.out.println("Twitter: " + twitterCount);
        System.out.println("LinkedIn: " + linkedinCount);
    }

    static void searchAccountsByTypeAndMinPrice() {
        System.out.print("Nhập loại tài khoản (user type) cần tìm: ");
        String userType = scanner.next();
        System.out.print("Nhập giá thấp nhất: ");
        float minPrice = scanner.nextFloat();

        System.out.println("Tài khoản thỏa mãn:");
        for (Account acc : accounts) {
            if (acc.userType.equalsIgnoreCase(userType) && acc.price >= minPrice) {
                System.out.println(acc);
            }
        }
    }

    static void printAccounts() {
        for (Account acc : accounts) {
            System.out.println(acc);
        }
    }

    static void exitProgram() {
        System.out.println("Thoát chương trình.");
        System.exit(0);
    }
}
