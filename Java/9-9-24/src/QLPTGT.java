import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

// Lớp QLPTGT
class QLPTGT {
    private List<Vehicle> danhSachPhuongTien;

    public QLPTGT() {
        danhSachPhuongTien = new ArrayList<>();
    }

    // Thêm phương tiện
    public void themPhuongTien(Vehicle vehicle) {
        danhSachPhuongTien.add(vehicle);
    }

    // Xoá phương tiện theo ID
    public void xoaPhuongTien(String id) {
        Iterator<Vehicle> iterator = danhSachPhuongTien.iterator();
        while (iterator.hasNext()) {
            Vehicle vehicle = iterator.next();
            if (vehicle.id.equals(id)) {
                iterator.remove();
                break;
            }
        }
    }

    // Gọi tính năng choHang của xe tải theo ID
    public void goiChoHang(String id, Integer khoiLuong) {
        for (Vehicle vehicle : danhSachPhuongTien) {
            if (vehicle instanceof XeTai && vehicle.id.equals(id)) {
                ((XeTai) vehicle).choHang(khoiLuong);
                return;
            }
        }
        System.out.println("Xe tai khong tim thay");
    }

    // Gọi tính năng choKHach của ô tô theo ID
    public void goiChoKHach(String id, Integer soHanhKhach) {
        for (Vehicle vehicle : danhSachPhuongTien) {
            if (vehicle instanceof Oto && vehicle.id.equals(id)) {
                ((Oto) vehicle).choKHach(soHanhKhach);
                return;
            }
        }
        System.out.println("O to khong tim thay");
    }

    // Tìm phương tiện theo hãng sản xuất và màu
    public void timPhuongTien(String hangSanXuat, String mauXe) {
        for (Vehicle vehicle : danhSachPhuongTien) {
            if (vehicle.hangSanXuat.equals(hangSanXuat) && vehicle.mauXe.equals(mauXe)) {
                System.out.println("Phuong tien: " + vehicle.id + " - " + hangSanXuat + " - " + mauXe);
            }
        }
    }

    // Thoát chương trình
    public void thoat() {
        System.out.println("Thoat chuong trinh");
    }
}
