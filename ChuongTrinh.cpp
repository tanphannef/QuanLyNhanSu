#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    //NodeNhanVien* id = NULL;  //dung de tim kiem theo id cho nguoi dung
    int a;
    do
    {
        system("cls");
        cout << "Danh Sach Menu" << "\n";
        cout << "0. Thoat" << "\n";
        cout << "1. them nhan vien" << "\n";
        cout << "2. xuat danh sach nhan vien" << "\n";
        cout << "3. xoa thong tin nhan vien" << "\n";
        cout << "4. sua thong tin nhan vien" << "\n";
        cout << "5. tim kiem" << "\n";
        cout << "6. doc file" << "\n";
        cout << "7. ghi file" << "\n";
        cout << "Nhap so : ";
        cin >> a;
        system("cls");
        switch (a)
        {
        case 0://thoat
            return 0;
        case 1://them nhan vien
            cout << "--------------------\n";
            themDSNhanVien(dsnv);
            cout << "--------------------\n";
            break;
        case 2://xuat nhan vien
            xuatDSNhanVien(dsnv);
            cout << "--------------------------\n";

            break;
        case 3://xoa nhan vien
            xoaNhanVien(dsnv);
            break;
        case 4://sua thong tin nhan vien
            suaThongTinNhanVien(dsnv);
            break;
        case 5://tim kiem nhan su
            timKiem(dsnv);
            break;
        case 6://doc file
            if (readFile("danhSachNhanVien.txt", dsnv))
            {
                cout << "Doc file thanh cong!" << endl;
            }
            else
            {
                cout << "Doc file that bai!" << endl;
            }
            break;
        case 7://ghi file
            if (writeFile("danhSachNhanVien.txt", dsnv))
            {
                cout << "Ghi file thanh cong!" << endl;
            }
            else
            {
                cout << "Ghi file that bai!" << endl;
            }
            break;
        default:
            cout << "nhap lai: " << endl;
            break;
        }
        char check;
        cout << "Ban co muon tiep tuc khong(y/n): ";
        cin >> check;
        if (check == 'n' || check == 'N')
        {
            return 0;
        }

    } while (a != 0);

    return 0;
}
