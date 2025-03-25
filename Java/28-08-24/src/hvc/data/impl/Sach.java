package hvc.data.impl;

import hvc.data.ITaiLieu;
import java.util.Scanner;

public class Sach implements ITaiLieu {
    private int id;
    private String tenSach;
    private String tenTacGia;
    private float gia;

    // Constructor không có tham số
    public Sach() {}

    // Constructor với đầy đủ tham số
    public Sach(int id, String tenSach, String tenTacGia, float gia) {
        this.id = id;
        this.tenSach = tenSach;
        this.tenTacGia = tenTacGia;
        this.gia = gia;
    }

    // Getter và Setter cho từng thuộc tính
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTenSach() {
        return tenSach;
    }

    public void setTenSach(String tenSach) {
        this.tenSach = tenSach;
    }

    public String getTenTacGia() {
        return tenTacGia;
    }

    public void setTenTacGia(String tenTacGia) {
        this.tenTacGia = tenTacGia;
    }

    public float getGia() {
        return gia;
    }

    public void setGia(float gia) {
        this.gia = gia;
    }

    // Triển khai phương thức từ ITaiLieu
    @Override
    public void nhap() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập ID: ");
        this.id = scanner.nextInt();
        scanner.nextLine(); // Đọc bỏ dòng trống
        System.out.print("Nhập tên sách: ");
        this.tenSach = scanner.nextLine();
        System.out.print("Nhập tên tác giả: ");
        this.tenTacGia = scanner.nextLine();
        System.out.print("Nhập giá: ");
        this.gia = scanner.nextFloat();
    }

    @Override
    public void hienThi() {
        System.out.println("ID: " + id);
        System.out.println("Tên sách: " + tenSach);
        System.out.println("Tên tác giả: " + tenTacGia);
        System.out.println("Giá: " + gia);
    }
}
