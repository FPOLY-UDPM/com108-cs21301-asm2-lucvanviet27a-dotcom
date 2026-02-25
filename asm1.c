/******************************************************************************
 * Họ và tên: [LUC VAN VIET]
 * MSSV:      [PS49691]
 * Lớp:       [COM108-CS21302]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <stdlib.h>
int main() {
    int chonChucNang;

    do {
        printf("\n========== MENU ASM1 ==========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN cua 2 so\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai suat vay ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {

        // ===== CASE 1 =====
        case 1: {
            double n;
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            printf("Nhap mot so: ");
            scanf("%lf", &n);

            if (n == (int)n)
                printf("→ %.2f la so nguyen\n", n);
            else
                printf("→ %.2f KHONG la so nguyen\n", n);
            break;
        }

        // ===== CASE 2 =====
        case 2: {
            int a, b;
            printf("DA CHON CHUC NANG 2: TIM UCLN VA BCNN\n");
            printf("Nhap so thu nhat: ");
            scanf("%d", &a);
            printf("Nhap so thu hai: ");
            scanf("%d", &b);

            int min = (a < b) ? a : b;
            int ucln = 1;

            for (int i = 1; i <= min; i++) {
                if (a % i == 0 && b % i == 0)
                    ucln = i;
            }

            int bcnn = (a * b) / ucln;

            printf("UCLN = %d\n", ucln);
            printf("BCNN = %d\n", bcnn);
            break;
        }

        // ===== CASE 3 =====
        case 3: {
            int gioBatDau, gioKetThuc;
            printf("DA CHON CHUC NANG 3: TINH TIEN KARAOKE\n");
            printf("Nhap gio bat dau: ");
            scanf("%d", &gioBatDau);
            printf("Nhap gio ket thuc: ");
            scanf("%d", &gioKetThuc);

            int soGio = gioKetThuc - gioBatDau;
            float tien;

            if (soGio <= 3)
                tien = soGio * 150000;
            else
                tien = 3 * 150000 + (soGio - 3) * 150000 * 0.7;

            if (gioBatDau >= 14 && gioBatDau <= 17)
                tien *= 0.9;

            printf("Tien karaoke: %.0f VND\n", tien);
            break;
        }

        // ===== CASE 4 =====
        case 4: {
            int kWh;
            float tien;
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            printf("Nhap so kWh: ");
            scanf("%d", &kWh);

            if (kWh <= 50)
                tien = kWh * 1678;
            else if (kWh <= 100)
                tien = 50 * 1678 + (kWh - 50) * 1734;
            else
                tien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;

            printf("Tien dien: %.0f VND\n", tien);
            break;
        }

        // ===== CASE 5 =====
        case 5: {
            int tien;
            int menhGia[] = {500,200,100,50,20,10,5,2,1};
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            printf("Nhap so tien: ");
            scanf("%d", &tien);

            for (int i = 0; i < 9; i++) {
                printf("%d to %d\n", tien / menhGia[i], menhGia[i]);
                tien %= menhGia[i];
            }
            break;
        }

        // ===== CASE 6 =====
        case 6: {
            float tienVay = 12000000;
            float laiSuat = 0.05;
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT NGAN HANG\n");

            for (int thang = 1; thang <= 12; thang++) {
                float tienLai = tienVay * laiSuat;
                tienVay -= 1000000;
                printf("Thang %d - Lai phai tra: %.0f\n", thang, tienLai);
            }
            break;
        }

        // ===== CASE 7 =====
        case 7: {
            float giaXe;
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            printf("Nhap gia xe: ");
            scanf("%f", &giaXe);

            float traTruoc = giaXe * 0.2;
            float vay = giaXe * 0.8;

            printf("Tra truoc: %.0f\n", traTruoc);
            printf("So tien vay: %.0f\n", vay);
            break;
        }

        // ===== CASE 8 =====
        case 8: {
            char ten[3][30];
            float diem[3];
            printf("DA CHON CHUC NANG 8: SAP XEP SINH VIEN\n");

            for (int i = 0; i < 3; i++) {
                printf("Nhap ten SV %d: ", i + 1);
                scanf("%s", ten[i]);
                printf("Nhap diem: ");
                scanf("%f", &diem[i]);
            }

            for (int i = 0; i < 2; i++)
                for (int j = i + 1; j < 3; j++)
                    if (diem[i] < diem[j]) {
                        float temp = diem[i];
                        diem[i] = diem[j];
                        diem[j] = temp;
                    }

            printf("Danh sach sau sap xep:\n");
            for (int i = 0; i < 3; i++)
                printf("%s - %.2f\n", ten[i], diem[i]);
            break;
        }

        // ===== CASE 9 =====
        case 9: {
            int soNgauNhien = rand() % 15;
            int duDoan;
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            printf("Nhap so du doan (0-14): ");
            scanf("%d", &duDoan);

            if (duDoan == soNgauNhien)
                printf("CHUC MUNG! BAN DA TRUNG\n");
            else
                printf("KHONG TRUNG! So dung la %d\n", soNgauNhien);
            break;
        }

        // ===== CASE 10 =====
        case 10: {
            int a, b, c, d;
            printf("DA CHON CHUC NANG 10: TINH PHAN SO\n");
            printf("Nhap a/b: ");
            scanf("%d%d", &a, &b);
            printf("Nhap c/d: ");
            scanf("%d%d", &c, &d);

            int tu = a * d + b * c;
            int mau = b * d;

            int x = tu, y = mau;
            while (y != 0) {
                int r = x % y;
                x = y;
                y = r;
            }

            printf("Ket qua = %d/%d\n", tu / x, mau / x);
            break;
        }

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (chonChucNang != 0);

    return 0;
}