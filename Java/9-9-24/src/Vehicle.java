abstract class Vehicle implements IVehicle {
    protected String id;
    protected String hangSanXuat;
    protected int namSanXuat;
    protected double giaBan;
    protected String mauXe;

    public Vehicle(String id, String hangSanXuat, int namSanXuat, double giaBan, String mauXe) {
        this.id = id;
        this.hangSanXuat = hangSanXuat;
        this.namSanXuat = namSanXuat;
        this.giaBan = giaBan;
        this.mauXe = mauXe;
    }

    // Các phương thức abstract từ Ivehicle
    @Override
    public abstract void khoiDong();

    @Override
    public abstract void dungXe();

    @Override
    public abstract void phanh();
}