/*   1,Tao 1 struct Sinh vien  học kỳ 1 cac thuoc tinh:   Name,  Lớp, Mssv,DiemPre,DiemEPC,DiemAnh,QueQuan,SoThich,NamSinh.
   2,Nhập mảng, số lượng phần tử trong mảng sẽ do người dùng nhập tử bàn phím.(lưu ý cấp phát động, điểm số theo thang điểm 20, Mssv không được trùng nhau.)
  3, Xuất ra màn hình các phần tử trong mảng theo bang:
  +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Tên                           | Mssv | Nam sinh     | Que quan    | DiemToan | Diem Van  | Diem Anh|
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van C         | 12      |    1992          |     HN           |    10            |    9             |     8           |
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van D         | 14      |    1990          |     ND           |    10            |    8             |       8          |
  4, Tìm ra các phần tử được học bổng và xuất ra màn hình thông tin những sinh viên đó:
      Đạt học bổng thoả mãn yêu cầu sau: các môn phải trên 12 điếm và điểm trung bình trên 16 điểm theo bang.:
  +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Tên                           | Mssv | Nam sinh     | Que quan    | DiemToan | Diem Van  | Diem Anh|
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van C         | 12      |    1992          |     HN           |    10            |    9             |     8           |
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van D         | 14      |    1990          |     ND           |    10            |    8             |       8          |

  5,Thêm m phần tử vào mảng trên, m được người dùng nhập từ bàn phím.
Nhập dự liệu từ bàn phím và xuất ra mảng các phần tử mảng  hiện tại theo bang: 
  +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Tên                           | Mssv | Nam sinh     | Que quan    | DiemToan | Diem Van  | Diem Anh|
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van C         | 12      |    1992          |     HN           |    10            |    9             |     8           |
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van D         | 14      |    1990          |     ND           |    10            |    8             |       8          |
  6, Tìm kiếm phần tử theo mssv và thay đổi dư liêu phần tử đó từ bàn phím.(luu y mssv tìm kiếm nhạp từ bàn phím.)// câu này rất hay đó các em, hầu hết phần nào cũng có chưc năng tìm kiếm. xuat ra gia tri mang theo bang:
  +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Tên                           | Mssv | Nam sinh     | Que quan    | DiemToan | Diem Van  | Diem Anh|
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van C         | 12      |    1992          |     HN           |    10            |    9             |     8           |
   +-----------------------------------------------------------------------------------------------------------------------------------------+
   | Nguyen van D         | 14      |    1990          |     ND           |    10            |    8             |       8          |*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char Name[50];
    char Lop[20];
    int Mssv;
    float DiemPre;
    float DiemEPC;
    float DiemAnh;
    char QueQuan[50];
    char SoThich[100];
    int NamSinh;
};

#define MAX_STUDENTS 100

struct SinhVien* dsSinhVien = NULL;
int soLuongSinhVien = 0;

void NhapSinhVien(struct SinhVien* sv) {
    printf("Nhap ten: ");
    getchar();
    fgets(sv->Name, sizeof(sv->Name), stdin);
    sv->Name[strcspn(sv->Name, "\n")] = '\0';
    printf("Nhap lop: ");
    fgets(sv->Lop, sizeof(sv->Lop), stdin);
    sv->Lop[strcspn(sv->Lop, "\n")] = '\0';
    printf("Nhap Mssv: ");
    scanf("%d", &sv->Mssv);

    // Kiểm tra Mssv đã tồn tại chưa
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (dsSinhVien[i].Mssv == sv->Mssv) {
            printf("Mssv da ton tai. Nhap lai.\n");
            NhapSinhVien(sv);
            return;
        }
    }

    printf("Nhap Diem Pre: ");
    scanf("%f", &sv->DiemPre);
    printf("Nhap Diem EPC: ");
    scanf("%f", &sv->DiemEPC);
    printf("Nhap Diem Anh: ");
    scanf("%f", &sv->DiemAnh);

    // Kiểm tra điểm số nằm trong khoảng từ 0 đến 20
    if (sv->DiemPre < 0 || sv->DiemPre > 20 || sv->DiemEPC < 0 || sv->DiemEPC > 20 || sv->DiemAnh < 0 || sv->DiemAnh > 20) {
        printf("Diem khong hop le. Diem phai nam trong khoang tu 0 den 20. Nhap lai.\n");
        NhapSinhVien(sv);
        return;
    }

    printf("Nhap Que quan: ");
    getchar();
    fgets(sv->QueQuan, sizeof(sv->QueQuan), stdin);
    sv->QueQuan[strcspn(sv->QueQuan, "\n")] = '\0';
    printf("Nhap So thich: ");
    fgets(sv->SoThich, sizeof(sv->SoThich), stdin);
    sv->SoThich[strcspn(sv->SoThich, "\n")] = '\0';
    printf("Nhap Nam sinh: ");
    scanf("%d", &sv->NamSinh);
}

// Hàm xuất thông tin một sinh viên
void XuatSinhVien(struct SinhVien sv) {
    printf("| %-30s | %-6d | %-11d | %-11s | %-9.2f | %-9.2f | %-8.2f |\n", sv.Name, sv.Mssv, sv.NamSinh, sv.QueQuan, sv.DiemPre, sv.DiemEPC, sv.DiemAnh);
}

// Hàm xuất bảng danh sách sinh viên
void XuatBangDanhSachSinhVien() {
    printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
    printf("| Ten                            | Mssv   | Nam sinh    | Que quan    | Diem Pre  | Diem EPC  | Diem Anh |\n");
    printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
    for (int i = 0; i < soLuongSinhVien; i++) {
        XuatSinhVien(dsSinhVien[i]);
        printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
    }
}

// Hàm kiểm tra điều kiện để được học bổng
int DatHocBong(struct SinhVien sv) {
    float diemTrungBinh = (sv.DiemPre + sv.DiemEPC + sv.DiemAnh) / 3;
    return (sv.DiemPre > 12 && sv.DiemEPC > 12 && sv.DiemAnh > 12 && diemTrungBinh > 16);
}

int main() {
    int luaChon;
    dsSinhVien = (struct SinhVien*)malloc(MAX_STUDENTS * sizeof(struct SinhVien));

    if (dsSinhVien == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    do {
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien duoc hoc bong\n");
        printf("4. Them sinh vien\n");
        printf("5. Tim va sua thong tin sinh vien theo Mssv\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                if (soLuongSinhVien < MAX_STUDENTS) {
                    NhapSinhVien(&dsSinhVien[soLuongSinhVien]);
                    soLuongSinhVien++;
                } else {
                    printf("Danh sach da day. Khong the them sinh vien moi.\n");
                }
                break;
            case 2:
                XuatBangDanhSachSinhVien();
                break;
            case 3:
                printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
                printf("| Danh sach sinh vien dat hoc bong |\n");
                printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
                for (int i = 0; i < soLuongSinhVien; i++) {
                    if (DatHocBong(dsSinhVien[i])) {
                        XuatSinhVien(dsSinhVien[i]);
                        printf("+--------------------------------+--------+-------------+-------------+-----------+-----------+----------+\n");
                    }
                }
                break;
            case 4:
                if (soLuongSinhVien < MAX_STUDENTS) {
                    NhapSinhVien(&dsSinhVien[soLuongSinhVien]);
                    soLuongSinhVien++;
                } else {
                    printf("Danh sach da day. Khong the them sinh vien moi.\n");
                }
                break;
            case 5:
                printf("Nhap Mssv can tim va sua thong tin: ");
                int mssvTim;
                scanf("%d", &mssvTim);
                for (int i = 0; i < soLuongSinhVien; i++) {
                    if (dsSinhVien[i].Mssv == mssvTim) {
                        NhapSinhVien(&dsSinhVien[i]);
                        printf("Da sua thong tin cho sinh vien co Mssv %d.\n", mssvTim);
                        break;
                    }
                    if (i == soLuongSinhVien - 1) {
                        printf("Khong tim thay sinh vien co Mssv %d.\n", mssvTim);
                    }
                }
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 0);

    free(dsSinhVien);
    return 0;
}
