/*Anh có giải demo phần read-write file các em xem.
Các em làm bài tập dưới:
create struct hocvien properties  : name, class, mshv, diemPre,diemEPCViet chuong trinh nhap mang kieu du lieu struct.(luu y dung cap phat dong, tao ra cac functions)
1, Viet chuong trinh nhap gia tri tu ban phim.
  diem so theo  thang diem  20, mshv ko duoc trung nhau.
2, Xuat ra gia tri cac phan tu trong mang.
3,  tim gia tri max min cac mon  trong mang  và xuat ra man hinh gia tri .
4, viet chuong trinh sap xep cac phan tu  giam  dan theo mshv.
5, Xu?t ra màn hình có di?m tb> 15 và các môn không du?i 12 di?m.
6,Tìm nh?ng b?n có di?m tb >13 và quê ? hà n?i. xu?t ra nh?ng b?n dó.
7, Tìm ngu?i tr? nh?t có di?m tb cao nh?t. xu?t ra màn hình.
8.luu file o che do binary. ten file do nguoi dung nhap vao va hien thong bao khi luu thanh cong.
9. Mo file o che do binary.hien thi danh sach theo bang?.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc HocVien
struct HocVien {
    char name[50];
    char _class[20];
    char mshv[10];
    float diemPre;
    float diemEPCViet;
};

// Hàm nhập thông tin của một học viên từ bàn phím
void NhapHocVien(struct HocVien *hv) {
    printf("Nhap ten hoc vien: ");
    scanf("%s", hv->name);
    printf("Nhap lop: ");
    scanf("%s", hv->_class);
    printf("Nhap ma so hoc vien: ");
    scanf("%s", hv->mshv);
    do {
        printf("Nhap diem Pre (0-20): ");
        scanf("%f", &hv->diemPre);
    } while (hv->diemPre < 0 || hv->diemPre > 20);
    do {
        printf("Nhap diem EPC Viet (0-20): ");
        scanf("%f", &hv->diemEPCViet);
    } while (hv->diemEPCViet < 0 || hv->diemEPCViet > 20);
}

// Hàm xuất thông tin của một học viên
void XuatHocVien(const struct HocVien *hv) {
    printf("Ten: %s, Lop: %s, Ma so hoc vien: %s, Diem Pre: %.2f, Diem EPC Viet: %.2f\n", hv->name, hv->_class, hv->mshv, hv->diemPre, hv->diemEPCViet);
}

// Hàm tìm giá trị lớn nhất trong mảng các học viên
float TimMax(const struct HocVien *dsHocVien, int n) {
    float maxDiem = dsHocVien[0].diemPre > dsHocVien[0].diemEPCViet ? dsHocVien[0].diemPre : dsHocVien[0].diemEPCViet;
    for (int i = 1; i < n; i++) {
        float diemMax = dsHocVien[i].diemPre > dsHocVien[i].diemEPCViet ? dsHocVien[i].diemPre : dsHocVien[i].diemEPCViet;
        if (diemMax > maxDiem) {
            maxDiem = diemMax;
        }
    }
    return maxDiem;
}

// Hàm tìm giá trị nhỏ nhất trong mảng các học viên
float TimMin(const struct HocVien *dsHocVien, int n) {
    float minDiem = dsHocVien[0].diemPre < dsHocVien[0].diemEPCViet ? dsHocVien[0].diemPre : dsHocVien[0].diemEPCViet;
    for (int i = 1; i < n; i++) {
        float diemMin = dsHocVien[i].diemPre < dsHocVien[i].diemEPCViet ? dsHocVien[i].diemPre : dsHocVien[i].diemEPCViet;
        if (diemMin < minDiem) {
            minDiem = diemMin;
        }
    }
    return minDiem;
}

// Hàm sắp xếp mảng học viên theo điểm giảm dần theo mshv
void SapXepGiamDan(struct HocVien *dsHocVien, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(dsHocVien[i].mshv, dsHocVien[j].mshv) < 0) {
                // Hoán đổi vị trí của hai học viên
                struct HocVien temp = dsHocVien[i];
                dsHocVien[i] = dsHocVien[j];
                dsHocVien[j] = temp;
            }
        }
    }
}

// Hàm xuất danh sách học viên có điểm trung bình > 15 và không dưới 12 điểm ở cả hai môn
void XuatHocVienDiemTB(struct HocVien *dsHocVien, int n) {
    printf("\nDanh sach hoc vien co diem trung binh > 15 va khong duoi 12 diem o ca hai mon:\n");
    for (int i = 0; i < n; i++) {
        float diemTB = (dsHocVien[i].diemPre + dsHocVien[i].diemEPCViet) / 2;
        if (diemTB > 15 && dsHocVien[i].diemPre >= 12 && dsHocVien[i].diemEPCViet >= 12) {
            XuatHocVien(&dsHocVien[i]);
        }
    }
}

// Hàm xuất danh sách học viên có điểm trung bình > 13 và quê ở Hà Nội
void XuatHocVienDiemTBVaQueHanoi(struct HocVien *dsHocVien, int n) {
    printf("\nDanh sach hoc vien co diem trung binh > 13 va que o Ha Noi:\n");
    for (int i = 0; i < n; i++) {
        float diemTB = (dsHocVien[i].diemPre + dsHocVien[i].diemEPCViet) / 2;
        if (diemTB > 13 && strstr(dsHocVien[i].name, "Ha Noi") != NULL) {
            XuatHocVien(&dsHocVien[i]);
        }
    }
}

// Hàm tìm học viên có điểm trung bình cao nhất
void TimHocVienDiemTBCaoNhat(struct HocVien *dsHocVien, int n) {
    float maxDiemTB = (dsHocVien[0].diemPre + dsHocVien[0].diemEPCViet) / 2;
    int idxMax = 0;
    for (int i = 1; i < n; i++) {
        float diemTB = (dsHocVien[i].diemPre + dsHocVien[i].diemEPCViet) / 2;
        if (diemTB > maxDiemTB) {
            maxDiemTB = diemTB;
            idxMax = i;
        }
    }
    printf("\nHoc vien co diem trung binh cao nhat la:\n");
    XuatHocVien(&dsHocVien[idxMax]);
}

// Hàm lưu danh sách học viên vào tệp nhị phân
void LuuDuLieuVaoTep(struct HocVien *dsHocVien, int n, const char *tenTep) {
    FILE *tep = fopen(tenTep, "wb");
    if (tep == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    
    fwrite(dsHocVien, sizeof(struct HocVien), n, tep);
    fclose(tep);
    printf("Luu du lieu thanh cong vao tep %s.\n", tenTep);
}

// Hàm nạp danh sách học viên từ tệp nhị phân
int NapDuLieuTuTep(struct HocVien **dsHocVien, const char *tenTep) {
    FILE *tep = fopen(tenTep, "rb");
    if (tep == NULL) {
        printf("Khong the mo tep de doc.\n");
        return 0;
    }
    
    fseek(tep, 0, SEEK_END);
    int soLuong = ftell(tep) / sizeof(struct HocVien);
    fseek(tep, 0, SEEK_SET);
    
    *dsHocVien = (struct HocVien *)malloc(soLuong * sizeof(struct HocVien));
    
    fread(*dsHocVien, sizeof(struct HocVien), soLuong, tep);
    fclose(tep);
    
    return soLuong;
}

int main() {
    int n;
    printf("Nhap so luong hoc vien: ");
    scanf("%d", &n);
    
    // Cấp phát động cho mảng các học viên
    struct HocVien *dsHocVien = (struct HocVien *)malloc(n * sizeof(struct HocVien));
    
    // Nhập thông tin cho các học viên và kiểm tra mshv trùng lặp
    for (int i = 0; i < n; i++) {
        do {
            NhapHocVien(&dsHocVien[i]);
            int trung = 0;
            for (int j = 0; j < i; j++) {
                if (strcmp(dsHocVien[i].mshv, dsHocVien[j].mshv) == 0) {
                    trung = 1;
                    printf("Ma so hoc vien trung lap. Vui long nhap lai.\n");
                    break;
                }
            }
            if (!trung) {
                break;
            }
        } while (1);
    }
    
    // Xuất thông tin của các học viên
    printf("\nDanh sach hoc vien:\n");
    for (int i = 0; i < n; i++) {
        XuatHocVien(&dsHocVien[i]);
    }
    
    // Tìm và xuất giá trị lớn nhất và nhỏ nhất
    float maxDiem = TimMax(dsHocVien, n);
    float minDiem = TimMin(dsHocVien, n);
    printf("\nDiem cao nhat trong danh sach: %.2f\n", maxDiem);
    printf("Diem thap nhat trong danh sach: %.2f\n", minDiem);
    
    // Sắp xếp danh sách học viên theo mshv giảm dần
    SapXepGiamDan(dsHocVien, n);
    printf("\nDanh sach hoc vien sau khi sap xep theo mshv giam dan:\n");
    for (int i = 0; i < n; i++) {
        XuatHocVien(&dsHocVien[i]);
    }
    
    // Xuất danh sách học viên có điểm trung bình và điểm môn Pre không dưới 12
    XuatHocVienDiemTB(dsHocVien, n);
    
    // Xuất danh sách học viên có điểm trung bình > 13 và quê ở Hà Nội
    XuatHocVienDiemTBVaQueHanoi(dsHocVien, n);
    
    // Tìm học viên có điểm trung bình cao nhất
    TimHocVienDiemTBCaoNhat(dsHocVien, n);
    
    // Lưu danh sách học viên vào tệp nhị phân
    char tenTep[50];
    printf("\nNhap ten tep de luu: ");
    scanf("%s", tenTep);
    LuuDuLieuVaoTep(dsHocVien, n, tenTep);
    
    // Giải phóng bộ nhớ đã cấp phát động
    free(dsHocVien);
    
    // Mở tệp nhị phân và hiển thị danh sách theo bảng
    int soLuong;
    struct HocVien *dsHocVienNap;
    printf("\nNhap ten tep de nap: ");
    scanf("%s", tenTep);
    soLuong = NapDuLieuTuTep(&dsHocVienNap, tenTep);
    printf("\nDanh sach hoc vien sau khi nap tu tep:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s |\n", "Ten", "Lop", "Ma so", "Diem Pre", "Diem EPC Viet");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < soLuong; i++) {
        XuatHocVien(&dsHocVienNap[i]);
    }
    
    // Giải phóng bộ nhớ đã cấp phát động cho danh sách nạp từ tệp
    free(dsHocVienNap);
    
    return 0;
}
