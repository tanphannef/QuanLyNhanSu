#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    int a;
    if (readFile("danhSachNhanVien.txt", dsnv))
    {
        do
        {
            system("cls");
            cout << "=========================================================" << endl;
            cout << "==============|Chuong Trinh Quan Ly Nhan Su|=============" << endl;
            cout << "======================|Danh Sach Menu|===================" << "\n";
            cout << "|0. Thoat                                               |" << "\n";
            cout << "|1. Them Nhan Vien                                      |" << "\n";
            cout << "|2. Xuat Danh Sach Nhan Vien                            |" << "\n";
            cout << "|3. Quan Ly Bang Cap                                    |" << "\n";
            cout << "|4. Tim Kiem                                            |" << "\n";
            cout << "=========================================================" << endl;
            cout << "Nhap so : ";
            cin >> a;
            system("cls");
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
                xuatDSNhanVien(dsnv);
                cout << "--------------------------\n";

                break;
            case 3:
                /*QuanLyBangCap(dsnv)*/
                break;
            case 4:
                timKiem(dsnv);
                break;
            default:
                cout << "nhap lai: " << endl;
                break;
            }
            char check;
            cout << "Ban co muon quay lai menu khong(y/n): ";
            cin >> check;
            if (check == 'n' || check == 'N')
            {
                break;
            }

        } while (a != 0);
    }
    else
    {
        cout << "Doc file that bai!" << endl;
    }
    if (writeFile("danhSachNhanVien.txt", dsnv))
    {
        return 0;
    }

    return 0;
}
