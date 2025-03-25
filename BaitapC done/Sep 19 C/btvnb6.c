#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa struct HocVien
struct HocVien {
    char name[50];
    char class[20];
    int mshv;
    float diemPre;
    float diemEPC;
    int year;
};

// Hàm kiểm tra MSNV có trùng lặp trong mảng không
int KiemTraTrungMSHV(struct HocVien *hocViens, int n, int mshv) {
    for (int i = 0; i < n; i++) {
        if (hocViens[i].mshv == mshv) {
            return 1; // Trùng lặp
        }
    }
    return 0; // Không trùng lặp
}

// Hàm kiểm tra điểm hợp lệ (phải > 0 và < 20)
int KiemTraDiemHopLe(float diem) {
    return (diem > 0 && diem < 20);
}

// Hàm tìm giá trị lớn nhất trong mảng
float TimMax(struct HocVien *hocViens, int n) {
    float max = hocViens[0].diemPre;
    for (int i = 0; i < n; i++) {
        if (hocViens[i].diemPre > max) {
            max = hocViens[i].diemPre;
        }
        if (hocViens[i].diemEPC > max) {
            max = hocViens[i].diemEPC;
        }
    }
    return max;
}

// Hàm tìm giá trị nhỏ nhất trong mảng
float TimMin(struct HocVien *hocViens, int n) {
    float min = hocViens[0].diemPre;
    for (int i = 0; i < n; i++) {
        if (hocViens[i].diemPre < min) {
            min = hocViens[i].diemPre;
        }
        if (hocViens[i].diemEPC < min) {
            min = hocViens[i].diemEPC;
        }
    }
    return min;
}

// Hàm sắp xếp mảng giảm dần theo mshv
void SapXepGiamDanTheoMSHV(struct HocVien *hocViens, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (hocViens[i].mshv < hocViens[j].mshv) {
                // Hoán đổi hai phần tử
                struct HocVien temp = hocViens[i];
                hocViens[i] = hocViens[j];
                hocViens[j] = temp;
            }
        }
    }
}

// Hàm in thông tin của học viên
void InThongTinHocVien(struct HocVien *hocViens, int n) {
    printf("\nDanh sach hoc vien:\n");
    for (int i = 0; i < n; i++) {
        printf("Ho Ten: %s\n", hocViens[i].name);
        printf("Lop: %s\n", hocViens[i].class);
        printf("MSHV: %d\n", hocViens[i].mshv);
        printf("Diem Pre: %.2f\n", hocViens[i].diemPre);
        printf("Diem EPC: %.2f\n", hocViens[i].diemEPC);
        printf("Nam Sinh: %d\n", hocViens[i].year);
        printf("------------------------------\n");
    }
}

// Hàm tìm người trẻ nhất có điểm trung bình cao nhất
void TimTreNhatCoDiemCaoNhat(struct HocVien *hocViens, int n) {
    int treNhat = 2022 - hocViens[0].year;
    float diemCaoNhat = (hocViens[0].diemPre + hocViens[0].diemEPC) / 2;

    for (int i = 1; i < n; i++) {
        int tuoi = 2022 - hocViens[i].year;
        float diemTB = (hocViens[i].diemPre + hocViens[i].diemEPC) / 2;
        if (tuoi < treNhat || (tuoi == treNhat && diemTB > diemCaoNhat)) {
            treNhat = tuoi;
            diemCaoNhat = diemTB;
        }
    }

    printf("\nThong tin nguoi tre nhat co diem trung binh cao nhat:\n");
    for (int i = 0; i < n; i++) {
        int tuoi = 2022 - hocViens[i].year;
        float diemTB = (hocViens[i].diemPre + hocViens[i].diemEPC) / 2;
        if (tuoi == treNhat && diemTB == diemCaoNhat) {
            printf("Ho Ten: %s\n", hocViens[i].name);
            printf("Lop: %s\n", hocViens[i].class);
            printf("MSHV: %d\n", hocViens[i].mshv);
            printf("Diem Trung Binh: %.2f\n", diemTB);
            printf("Nam Sinh: %d\n", hocViens[i].year);
            printf("------------------------------\n");
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong hoc vien: ");
    scanf("%d", &n);

    // Cấp phát động mảng HocVien
    struct HocVien *hocViens = (struct HocVien *)malloc(n * sizeof(struct HocVien));

    // Nhập thông tin cho từng học viên
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin cho hoc vien thu %d:\n", i + 1);
        printf("Ho Ten: ");
        scanf("%s", hocViens[i].name);

        printf("Lop: ");
        scanf("%s", hocViens[i].class);

        int mshv;
        do {
            printf("MSHV (khong trung nhau): ");
            scanf("%d", &mshv);

            if (KiemTraTrungMSHV(hocViens, i, mshv)) {
                printf("MSHV da trung lap. Hay nhap lai.\n");
            } else {
                hocViens[i].mshv = mshv;
            }
        } while (KiemTraTrungMSHV(hocViens, i, mshv));

        do {
            printf("Diem Pre: ");
            scanf("%f", &hocViens[i].diemPre);
            if (!KiemTraDiemHopLe(hocViens[i].diemPre)) {
                printf("Diem Pre khong hop le. Hay nhap lai.\n");
            }
        } while (!KiemTraDiemHopLe(hocViens[i].diemPre));

        do {
            printf("Diem EPC: ");
            scanf("%f", &hocViens[i].diemEPC);
            if (!KiemTraDiemHopLe(hocViens[i].diemEPC)) {
                printf("Diem EPC khong hop le. Hay nhap lai.\n");
            }
        } while (!KiemTraDiemHopLe(hocViens[i].diemEPC));

        printf("Nam Sinh: ");
        scanf("%d", &hocViens[i].year);
    }

    // a. Xuất thông tin học viên
    InThongTinHocVien(hocViens, n);

    // b. Tìm và xuất giá trị max và min
    float maxDiem = TimMax(hocViens, n);
    float minDiem = TimMin(hocViens, n);
    printf("\nDiem cao nhat: %.2f\n", maxDiem);
    printf("Diem thap nhat: %.2f\n", minDiem);

    // c. Sắp xếp mảng giảm dần theo mshv
    SapXepGiamDanTheoMSHV(hocViens, n);

    // d. Xuất thông tin học viên sau khi sắp xếp
    printf("\nDanh sach hoc vien sau khi sap xep theo MSHV giam dan:\n");
    InThongTinHocVien(hocViens, n);

    // e. Xuất thông tin các học viên có điểm trung bình > 15 và các môn học không dưới 12 điểm
    printf("\nHoc vien co diem trung binh > 15 va cac mon khong duoi 12 diem:\n");
    for (int i = 0; i < n; i++) {
        float diemTB = (hocViens[i].diemPre + hocViens[i].diemEPC) / 2;
        if (diemTB > 15 && hocViens[i].diemPre >= 12 && hocViens[i].diemEPC >= 12) {
            printf("Ho Ten: %s\n", hocViens[i].name);
            printf("Lop: %s\n", hocViens[i].class);
            printf("MSHV: %d\n", hocViens[i].mshv);
            printf("Diem Trung Binh: %.2f\n", diemTB);
            printf("Nam Sinh: %d\n", hocViens[i].year);
            printf("------------------------------\n");
        }
    }

    // f. Tìm người trẻ nhất có điểm trung bình cao nhất
    TimTreNhatCoDiemCaoNhat(hocViens, n);

    // Giải phóng bộ nhớ
    free(hocViens);

    return 0;
}
