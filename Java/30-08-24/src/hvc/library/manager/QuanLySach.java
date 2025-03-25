package hvc.library.manager;

import hvc.library.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QuanLySach {
    private List<TaiLieu> danhSachTaiLieu = new ArrayList<>();

    public void themTaiLieu() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Chọn loại tài liệu để thêm (1: Sách, 2: Tạp chí, 3: Báo): ");
        int loai = scanner.nextInt();
        scanner.nextLine(); // Đọc bỏ dòng trống

        System.out.print("Nhập mã tài liệu: ");
        String maTaiLieu = scanner.nextLine();
        System.out.print("Nhập tên nhà xuất bản: ");
        String tenNXB = scanner.nextLine();
        System.out.print("Nhập số bản phát hành: ");
        int soBanPhatHanh = scanner.nextInt();
        scanner.nextLine(); // Đọc bỏ dòng trống

        switch (loai) {
            case 1:
                System.out.print("Nhập tên tác giả: ");
                String tenTacGia = scanner.nextLine();
                System.out.print("Nhập số trang: ");
                int soTrang = scanner.nextInt();
                danhSachTaiLieu.add(new Sach(maTaiLieu, tenNXB, soBanPhatHanh, tenTacGia, soTrang));
                break;
            case 2:
                System.out.print("Nhập số phát hành: ");
                int soPhatHanh = scanner.nextInt();
                System.out.print("Nhập tháng phát hành: ");
                int thangPhatHanh = scanner.nextInt();
                danhSachTaiLieu.add(new TapChi(maTaiLieu, tenNXB, soBanPhatHanh, soPhatHanh, thangPhatHanh));
                break;
            case 3:
                System.out.print("Nhập ngày phát hành: ");
                String ngayPhatHanh = scanner.nextLine();
                danhSachTaiLieu.add(new Bao(maTaiLieu, tenNXB, soBanPhatHanh, ngayPhatHanh));
                break;
            default:
                System.out.println("Loại tài liệu không hợp lệ.");
                break;
        }
    }

    public void xoaTaiLieu(String maTaiLieu) {
        danhSachTaiLieu.removeIf(taiLieu -> taiLieu.getMaTaiLieu().equals(maTaiLieu));
    }

    public void hienThiTaiLieu() {
        for (TaiLieu taiLieu : danhSachTaiLieu) {
            taiLieu.hienThi();
            System.out.println("-------------------------");
        }
    }

    public void timKiemTaiLieu(int loai) {
        for (TaiLieu taiLieu : danhSachTaiLieu) {
            switch (loai) {
                case 1:
                    if (taiLieu instanceof Sach) taiLieu.hienThi();
                    break;
                case 2:
                    if (taiLieu instanceof TapChi) taiLieu.hienThi();
                    break;
                case 3:
                    if (taiLieu instanceof Bao) taiLieu.hienThi();
                    break;
                default:
                    System.out.println("Loại tài liệu không hợp lệ.");
                    return;
            }
        }
    }
}
