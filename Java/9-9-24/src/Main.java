import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        QLPTGT qlptgt = new QLPTGT();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Menu ---");
            System.out.println("1. Them phuong tien");
            System.out.println("2. Xoa phuong tien theo ID");
            System.out.println("3. Goi tinh nang choHang cua xe tai theo ID");
            System.out.println("4. Goi tinh nang choKHach cua oto theo ID");
            System.out.println("5. Tim phuong tien theo hang san xuat va mau xe");
            System.out.println("6. Thoat chuong trinh");
            System.out.print("Chon lua chon (1-6): ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    // Thêm phương tiện
                    System.out.print("Nhap loai phuong tien (oto/xemay/xetai): ");
                    String loai = scanner.nextLine();
                    System.out.print("Nhap ID: ");
                    String id = scanner.nextLine();
                    System.out.print("Nhap hang san xuat: ");
                    String hangSanXuat = scanner.nextLine();
                    System.out.print("Nhap nam san xuat: ");
                    int namSanXuat = scanner.nextInt();
                    System.out.print("Nhap gia ban: ");
                    double giaBan = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline
                    System.out.print("Nhap mau xe: ");
                    String mauXe = scanner.nextLine();

                    if (loai.equalsIgnoreCase("oto")) {
                        System.out.print("Nhap so cho ngoi: ");
                        int soChoNgoi = scanner.nextInt();
                        scanner.nextLine(); // Consume newline
                        System.out.print("Nhap kieu dong co: ");
                        String kieuDongCo = scanner.nextLine();
                        qlptgt.themPhuongTien(new Oto(id, hangSanXuat, namSanXuat, giaBan, mauXe, soChoNgoi, kieuDongCo));
                    } else if (loai.equalsIgnoreCase("xemay")) {
                        System.out.print("Nhap cong suat: ");
                        int congSuat = scanner.nextInt();
                        scanner.nextLine(); // Consume newline
                        qlptgt.themPhuongTien(new XeMay(id, hangSanXuat, namSanXuat, giaBan, mauXe, congSuat));
                    } else if (loai.equalsIgnoreCase("xetai")) {
                        System.out.print("Nhap trong tai: ");
                        int trongTai = scanner.nextInt();
                        scanner.nextLine(); // Consume newline
                        qlptgt.themPhuongTien(new XeTai(id, hangSanXuat, namSanXuat, giaBan, mauXe, trongTai));
                    } else {
                        System.out.println("Loai phuong tien khong hop le!");
                    }
                    break;

                case 2:
                    // Xoá phương tiện theo ID
                    System.out.print("Nhap ID phuong tien can xoa: ");
                    String xoaId = scanner.nextLine();
                    qlptgt.xoaPhuongTien(xoaId);
                    break;

                case 3:
                    // Gọi tính năng choHang của xe tải theo ID
                    System.out.print("Nhap ID xe tai: ");
                    String xeTaiId = scanner.nextLine();
                    System.out.print("Nhap khoi luong hang: ");
                    int khoiLuong = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    qlptgt.goiChoHang(xeTaiId, khoiLuong);
                    break;

                case 4:
                    // Gọi tính năng choKHach của ô tô theo ID
                    System.out.print("Nhap ID oto: ");
                    String otoId = scanner.nextLine();
                    System.out.print("Nhap so hanh khach: ");
                    int soHanhKhach = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    qlptgt.goiChoKHach(otoId, soHanhKhach);
                    break;

                case 5:
                    // Tìm phương tiện theo hãng sản xuất và màu
                    System.out.print("Nhap hang san xuat: ");
                    String timHangSanXuat = scanner.nextLine();
                    System.out.print("Nhap mau xe: ");
                    String timMauXe = scanner.nextLine();
                    qlptgt.timPhuongTien(timHangSanXuat, timMauXe);
                    break;

                case 6:
                    // Thoát chương trình
                    qlptgt.thoat();
                    break;

                default:
                    System.out.println("Lua chon khong hop le. Vui long chon tu 1 den 6.");
            }
        } while (choice != 6);

        scanner.close();
    }
}
