import java.util.Scanner;

public class EmployeeManagement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập thông tin nhân viên
        System.out.print("Nhập mã số nhân viên: ");
        String employeeID = scanner.nextLine();

        System.out.print("Nhập tên nhân viên: ");
        String employeeName = scanner.nextLine();

        System.out.print("Nhập chức vụ: ");
        String designation = scanner.nextLine();

        System.out.print("Nhập lương cơ bản: ");
        double basicSalary = scanner.nextDouble();

        System.out.print("Nhập doanh số bán hàng: ");
        double sales = scanner.nextDouble();

        // Tính hoa hồng
        double commission = 0;
        if (sales >= 10000) {
            commission = basicSalary * 0.30;
        } else if (sales >= 8000) {
            commission = basicSalary * 0.25;
        } else if (sales >= 6000) {
            commission = basicSalary * 0.20;
        } else if (sales >= 4000) {
            commission = basicSalary * 0.10;
        }

        // Tính tổng lương
        double totalSalary = basicSalary + commission;

        // Hiển thị thông tin chi tiết của nhân viên
        System.out.println("\nChi tiết nhân viên:");
        System.out.println("Mã số nhân viên: " + employeeID);
        System.out.println("Tên nhân viên: " + employeeName);
        System.out.println("Chức vụ: " + designation);
        System.out.println("Lương cơ bản: " + basicSalary);
        System.out.println("Doanh số bán hàng: " + sales);
        System.out.println("Tổng lương: " + totalSalary);
    }
}
