package hvc.library.test;

import hvc.library.manager.QuanLySach;
import java.util.Scanner;

public class KiemTra {
    public static void main(String[] args) {
        QuanLySach quanLy = new QuanLySach();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("----- MENU -----");
            System.out.println("1. Thêm tài liệu mới");
            System.out.println("2. Xóa tài liệu theo mã");
            System.out.println("3. Hiển thị thông tin tài liệu");
            System.out.println("4. Tìm kiếm tài liệu theo loại");
            System.out.println("5. Thoát");
            System.out.print("Lựa chọn của bạn: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Đọc bỏ dòng trống

            switch (choice) {
                case 1:
                    quanLy.themTaiLieu();
                    break;
                case 2:
                    System.out.print("Nhập mã tài liệu cần xóa: ");
                    String maTaiLieu = scanner.nextLine();
                    quanLy.xoaTaiLieu(maTaiLieu);
                    break;
                case 3:
                    quanLy.hienThiTaiLieu();
                    break;
                case 4:
                    System.out.print("Nhập loại tài liệu cần tìm (1: Sách, 2: Tạp chí, 3: Báo): ");
                    int loai = scanner.nextInt();
                    quanLy.timKiemTaiLieu(loai);
                    break;
                case 5:
                    System.out.println("Kết thúc chương trình.");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ, vui lòng chọn lại.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
