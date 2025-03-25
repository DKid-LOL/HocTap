class Oto extends Vehicle {
    private int soChoNgoi;
    private String kieuDongCo;

    public Oto(String id, String hangSanXuat, int namSanXuat, double giaBan, String mauXe, int soChoNgoi, String kieuDongCo) {
        super(id, hangSanXuat, namSanXuat, giaBan, mauXe);
        this.soChoNgoi = soChoNgoi;
        this.kieuDongCo = kieuDongCo;
    }

    @Override
    public void khoiDong() {
        System.out.println("Khoi dong oto");
    }

    @Override
    public void dungXe() {
        System.out.println("Dung xe oto");
    }

    @Override
    public void phanh() {
        System.out.println("Phanh xe oto");
    }

    // Phương thức riêng của ô tô
    public Integer choKHach(Integer soHanhKhach) {
        if (soHanhKhach > soChoNgoi) {
            System.out.println("So hanh khach vuot qua so cho ngoi: " + (soHanhKhach - soChoNgoi));
            return soHanhKhach - soChoNgoi;
        } else {
            System.out.println("So hanh khach phu hop");
            return 0;
        }
    }
}