#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    NodeNhanVien* id = NULL;  //dung de tim kiem theo id cho nguoi dung
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
            cout << "|3. Tim Kiem                                            |" << "\n";
            cout << "=========================================================" << endl;
            cout << "Nhap so : ";
            cin >> a;
            system("cls");
            switch (a)
            {
            case 0://thoat
                return 0;
            case 1:
                cout << "--------------------\n";
                themDSNhanVien(dsnv);
                cout << "--------------------\n";

                break;
            case 2:
                //cout << "--------------------------\n";
                xuatDSNhanVien(dsnv);
                cout << "--------------------------\n";

                break;
            case 3:
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
                return 0;
            }

        } while (a != 0);
        writeFile("danhSachNhanVien.txt", dsnv);
    }
    else
    {
        cout << "Doc file that bai!" << endl;
    }
    return 0;
}
