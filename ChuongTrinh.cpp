#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    NodeBangCap* dsbc = NULL;
    int a;
    if (readFile("danhSachNhanVien.txt", dsnv) && readFile("danhSachBangCap.txt", dsbc))
    {
        do
        {
            system("cls");
            cout << "=========================================================" << endl;
            cout << "==============|Chuong Trinh Quan Ly Nhan Su|=============" << endl;
            cout << "======================|Danh Sach Menu|===================" << "\n";
            cout << "|0. Thoat                                               |" << "\n";
            cout << "|1. Quan Ly Nhan Vien                                   |" << "\n";
            cout << "|2. Quan Ly Bang Cap                                    |" << "\n";
            cout << "|3. Thong Ke                                            |" << "\n";
            cout << "=========================================================" << endl;
            a = nhapSoNguyen();
            system("cls");
            switch (a)
            {
            case 0://thoat
                break;
            case 1:
                QuanLyNhanVien(dsnv);
                break;
            case 2:

                QuanLyBangCap(dsnv, dsbc);
                break;
            case 3:
                thongKe(dsnv, dsbc);
                break;
            default:
                cout << "Ban da lua chon sai!" << endl;
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
    if (writeFile("danhSachNhanVien.txt", dsnv) && writeFile("danhSachBangCap.txt", dsbc))
    {
        return 0;
    }
    return 0;
}
