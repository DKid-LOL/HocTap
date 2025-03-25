class XeTai extends Vehicle {
    private int trongTai;

    public XeTai(String id, String hangSanXuat, int namSanXuat, double giaBan, String mauXe, int trongTai) {
        super(id, hangSanXuat, namSanXuat, giaBan, mauXe);
        this.trongTai = trongTai;
    }

    @Override
    public void khoiDong() {
        System.out.println("Khoi dong xe tai");
    }

    @Override
    public void dungXe() {
        System.out.println("Dung xe tai");
    }

    @Override
    public void phanh() {
        System.out.println("Phanh xe tai");
    }

    // Phương thức riêng của xe tải
    public void choHang(Integer khoiLuong) {
        if (khoiLuong > trongTai) {
            System.out.println("Khoi luong khong phu hop");
        } else {
            System.out.println("Khoi luong phu hop");
        }
    }
}