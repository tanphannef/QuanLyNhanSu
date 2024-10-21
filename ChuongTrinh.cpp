#include "ThuVien.h"

int main()
{
	NodeNhanVien* dsnv = NULL;
    int a;
    do
    {
        cout << "\n";
        cout << "Danh Sach Menu" << "\n";
        cout << "0. Thoat" << "\n";
        cout << "1. them nhan vien" << "\n";
        cout << "2. xuat danh sach nhan vien" << "\n";
        cout << "3. xoa" << "\n";
        cout << "4. sua" << "\n";
        cout << "5. tim kiem" << "\n";
        cout << "6. doc file" << "\n";
        cout << "7. ghi file" << "\n";
        cout << "Nhap so : ";
        cin >> a;
        switch (a)
        {
        case 0://thoat
            break;
        case 1:
            cout << "--------------------\n";
	        themDSNhanVien(dsnv);
            cout << "--------------------\n";
            break;
        case 2:
            cout << "--------------------------\n";
            xuatDSNhanVien(dsnv);
            cout << "--------------------------\n";
            break;
        case 3://xoa
            xoaUser(dsnv);
            break;
        case 4://sua

            break;
        case 5://tim kiem
            timKiemUser(dsnv);
            break;
        case 6://doc file
            readFile("quanlynhansu.txt", dsnv);
            break;
        case 7:
            writeFile("luunhansu.txt", dsnv);
            break;
        default:
            cout << "nhap lai: ";
            break;
        }

    } while (a != 0);
	return 0;
}
