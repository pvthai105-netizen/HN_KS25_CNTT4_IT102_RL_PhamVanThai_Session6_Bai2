
#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {
    // B1: Khai bao cac mang va bien can thiet
    char maPhieu[MAX][15];
    char tenSach[MAX][50];

    int soNgayMuon[MAX];
    int tienPhat[MAX];

    int soLuong = 0;
    int choice;
    int i;
    int index;
    int ngayMoi;
    int tongTienPhat;
    int coPhieuQuaHan;

    char maNhap[15];

    // B2: Xay dung menu
    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat\n");
        printf("6. Thoat chuong trinh\n");
        printf("===============================================================================\n");
        printf("Lua chon cua ban: ");

        scanf("%d", &choice);

        // Lam sach bo dem ban phim
        while (getchar() != '\n');

        switch (choice) {
            // ==================================================
            // CASE 1: THEM LUOT MUON SACH MOI
            // ==================================================
            case 1:
                printf("\n=== THEM LUOT MUON SACH MOI ===\n");

                if (soLuong >= MAX) {
                    printf("He thong day, khong the them phieu muon moi!\n");
                    break;
                }

                // Nhap ma phieu va kiem tra trung lap
                do {
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maPhieu[soLuong]);

                    while (getchar() != '\n');

                    index = -1;

                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maPhieu[soLuong]) == 0) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        printf("Ma phieu da ton tai! Vui long nhap ma khac.\n");
                    }

                } while (index != -1);

                // Nhap ten sach
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);

                // Xoa ky tu xuong dong
                if (strlen(tenSach[soLuong]) > 0 &&
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] == '\n') {
                    tenSach[soLuong][strlen(tenSach[soLuong]) - 1] = '\0';
                }

                // Nhap so ngay muon
                printf("Nhap so ngay muon thuc te: ");
                scanf("%d", &soNgayMuon[soLuong]);

                while (getchar() != '\n');

                while (soNgayMuon[soLuong] <= 0) {
                    printf("So ngay muon phai lon hon 0! Vui long nhap lai: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');
                }

                // Tinh tien phat
                tienPhat[soLuong] = (soNgayMuon[soLuong] > 14)
                    ? (soNgayMuon[soLuong] - 14) * 5000
                    : 0;

                printf("Tien phat tu dong tinh: %d VND\n", tienPhat[soLuong]);

                soLuong++;

                printf("Them luot muon sach thanh cong!\n");
                break;

            // ==================================================
            // CASE 2: HIEN THI DANH SACH
            // ==================================================
            case 2:
                printf("\n================ DANH SACH MUON SACH ================\n");

                if (soLuong == 0) {
                    printf("Danh sach muon sach hien dang rong!\n");
                    break;
                }

                printf("%-5s | %-12s | %-35s | %-12s | %-15s\n",
                       "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");

                printf("-----------------------------------------------------------------------------------------\n");

                tongTienPhat = 0;

                for (i = 0; i < soLuong; i++) {
                    printf("%-5d | %-12s | %-35s | %-12d | %-15d\n",
                           i + 1,
                           maPhieu[i],
                           tenSach[i],
                           soNgayMuon[i],
                           tienPhat[i]);

                    tongTienPhat += tienPhat[i];
                }

                printf("-----------------------------------------------------------------------------------------\n");
                printf("Tong tien phat toan he thong: %d VND\n", tongTienPhat);
                printf("Tong so phieu muon: %d\n", soLuong);
                break;

            // ==================================================
            // CASE 3: CAP NHAT SO NGAY MUON
            // ==================================================
            case 3:
                printf("\n=== CAP NHAT SO NGAY MUON ===\n");

                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');

                index = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                    break;
                }

                printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n",
                       tenSach[index], soNgayMuon[index]);

                printf("Nhap so ngay muon thuc te moi: ");
                scanf("%d", &ngayMoi);

                while (getchar() != '\n');

                while (ngayMoi <= 0) {
                    printf("So ngay muon phai lon hon 0! Vui long nhap lai: ");
                    scanf("%d", &ngayMoi);
                    while (getchar() != '\n');
                }

                soNgayMuon[index] = ngayMoi;

                // Tinh lai tien phat sau khi cap nhat
                tienPhat[index] = (soNgayMuon[index] > 14)
                    ? (soNgayMuon[index] - 14) * 5000
                    : 0;

                printf("Tien phat moi: %d VND\n", tienPhat[index]);
                printf("Cap nhat so ngay muon thanh cong!\n");
                break;

            // ==================================================
            // CASE 4: XOA LUOT MUON SACH
            // ==================================================
            case 4:
                printf("\n=== XOA LUOT MUON SACH ===\n");

                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maNhap);

                while (getchar() != '\n');

                index = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maNhap) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("Khong tim thay phieu muon co ma: %s\n", maNhap);
                    break;
                }

                // Don cac phan tu phia sau len truoc
                for (i = index; i < soLuong - 1; i++) {
                    strcpy(maPhieu[i], maPhieu[i + 1]);
                    strcpy(tenSach[i], tenSach[i + 1]);
                    soNgayMuon[i] = soNgayMuon[i + 1];
                    tienPhat[i] = tienPhat[i + 1];
                }

                soLuong--;

                printf("Xoa phieu muon thanh cong!\n");
                break;

            // ==================================================
            // CASE 5: THONG KE PHIEU MUON QUA HAN
            // ==================================================
            case 5:
                printf("\n=== THONG KE PHIEU MUON QUA HAN ===\n");

                coPhieuQuaHan = 0;
                tongTienPhat = 0;

                printf("%-5s | %-12s | %-35s | %-12s | %-15s\n",
                       "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");

                printf("-----------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        printf("%-5d | %-12s | %-35s | %-12d | %-15d\n",
                               i + 1,
                               maPhieu[i],
                               tenSach[i],
                               soNgayMuon[i],
                               tienPhat[i]);

                        tongTienPhat += tienPhat[i];
                        coPhieuQuaHan = 1;
                    }
                }

                printf("-----------------------------------------------------------------------------------------\n");

                if (coPhieuQuaHan == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                } else {
                    printf("Tong tien phat cac phieu qua han: %d VND\n", tongTienPhat);
                }

                break;

            // ==================================================
            // CASE 6: THOAT CHUONG TRINH
            // ==================================================
            case 6:
                printf("Cam on ban da su dung he thong LIBRARY_WMS!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}
