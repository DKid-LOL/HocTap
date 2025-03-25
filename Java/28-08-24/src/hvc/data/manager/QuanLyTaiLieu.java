package hvc.data.manager;

import hvc.data.impl.Sach;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QuanLyTaiLieu {
    private List<Sach> danhSachSach = new ArrayList<>();

    public void themTaiLieu() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập số lượng sách cần lưu trữ: ");
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println("Nhập thông tin sách thứ " + (i + 1) + ":");
            Sach sach = new Sach();
            sach.nhap();
            danhSachSach.add(sach);
        }
    }

    public void hienThiTatCaTaiLieu() {
        for (Sach sach : danhSachSach) {
            sach.hienThi();
            System.out.println("-------------------------");
        }
    }

    public void timKiemTheoTacGia(String tenTacGia) {
        boolean timThay = false;
        for (Sach sach : danhSachSach) {
            if (sach.getTenTacGia().equalsIgnoreCase(tenTacGia)) {
                sach.hienThi();
                System.out.println("-------------------------");
                timThay = true;
            }
        }
        if (!timThay) {
            System.out.println("Không tìm thấy sách của tác giả: " + tenTacGia);
        }
    }
}
