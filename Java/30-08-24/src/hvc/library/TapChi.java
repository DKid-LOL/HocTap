package hvc.library;

public class TapChi extends TaiLieu {
    private int soPhatHanh;
    private int thangPhatHanh;

    public TapChi(String maTaiLieu, String tenNhaXuatBan, int soBanPhatHanh, int soPhatHanh, int thangPhatHanh) {
        super(maTaiLieu, tenNhaXuatBan, soBanPhatHanh);
        this.soPhatHanh = soPhatHanh;
        this.thangPhatHanh = thangPhatHanh;
    }

    public int getSoPhatHanh() {
        return soPhatHanh;
    }

    public void setSoPhatHanh(int soPhatHanh) {
        this.soPhatHanh = soPhatHanh;
    }

    public int getThangPhatHanh() {
        return thangPhatHanh;
    }
    Sot
    public void setThangPhatHanh(int thangPhatHanh) {
        this.thangPhatHanh = thangPhatHanh;
    }

    @Override
    public void hienThi() {
        System.out.println("Tạp chí: [Mã tài liệu: " + getMaTaiLieu() + ", Tên NXB: " + getTenNhaXuatBan() + ", Số bản phát hành: " + getSoBanPhatHanh() +
                ", Số phát hành: " + soPhatHanh + ", Tháng phát hành: " + thangPhatHanh + "]");
    }
}
