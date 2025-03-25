package hvc.library;

public class Bao extends TaiLieu {
    private String ngayPhatHanh;

    public Bao(String maTaiLieu, String tenNhaXuatBan, int soBanPhatHanh, String ngayPhatHanh) {
        super(maTaiLieu, tenNhaXuatBan, soBanPhatHanh);
        this.ngayPhatHanh = ngayPhatHanh;
    }

    public String getNgayPhatHanh() {
        return ngayPhatHanh;
    }

    public void setNgayPhatHanh(String ngayPhatHanh) {
        this.ngayPhatHanh = ngayPhatHanh;
    }

    @Override
    public void hienThi() {
        System.out.println("Báo: [Mã tài liệu: " + getMaTaiLieu() + ", Tên NXB: " + getTenNhaXuatBan() + ", Số bản phát hành: " + getSoBanPhatHanh() +
                ", Ngày phát hành: " + ngayPhatHanh + "]");
    }
}
