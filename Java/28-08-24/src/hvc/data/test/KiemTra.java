package hvc.data.test;

import hvc.data.manager.QuanLyTaiLieu;
import java.util.Scanner;

public class KiemTra {
    public static void main(String[] args) {
        QuanLyTaiLieu quanLy = new QuanLyTaiLieu();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("----- MENU -----");
            System.out.println("1. Thêm sách mới");
            System.out.println("2. Hiển thị tất cả sách");
            System.out.println("3. Tìm kiếm sách theo tên tác giả");
            System.out.println("4. Thoát");
            System.out.print("Lựa chọn của bạn: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Đọc bỏ dòng trống

            switch (choice) {
                case 1:
                    quanLy.themTaiLieu();
                    break;
                case 2:
                    quanLy.hienThiTatCaTaiLieu();
                    break;
                case 3:
                    System.out.print("Nhập tên tác giả cần tìm: ");
                    String tenTacGia = scanner.nextLine();
                    quanLy.timKiemTheoTacGia(tenTacGia);
                    break;
                case 4:
                    System.out.println("Kết thúc chương trình.");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ, vui lòng chọn lại.");
            }
        } while (choice != 4);

        scanner.close();
    }
}
