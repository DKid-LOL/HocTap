class XeMay extends Vehicle {
    private int congSuat;

    public XeMay(String id, String hangSanXuat, int namSanXuat, double giaBan, String mauXe, int congSuat) {
        super(id, hangSanXuat, namSanXuat, giaBan, mauXe);
        this.congSuat = congSuat;
    }

    @Override
    public void khoiDong() {
        System.out.println("Khoi dong xe may");
    }

    @Override
    public void dungXe() {
        System.out.println("Dung xe may");
    }

    @Override
    public void phanh() {
        System.out.println("Phanh xe may");
    }
}