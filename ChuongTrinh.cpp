#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    NodeNhanVien* id = NULL;  //dung de tim kiem theo id cho nguoi dung
    int a;
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
        cout << "|4. Doc File                                            |" << "\n";
        cout << "|5. Ghi File                                            |" << "\n";
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
        case 4://doc file
            if(readFile("danhSachNhanVien.txt", dsnv))
            {
                cout << "Doc file thanh cong!" << endl;
            }
            else
            {
                cout << "Doc file that bai!" << endl;
            }
            break;
        case 5:
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
            cout << "nhap lai: "<<endl;
            break;
        }
        char check;
        cout << "Ban co muon quay lai menu khong(y/n): ";
        cin >> check;
        if (check == 'n' || check == 'N')
        {
            return 0 ;
        }

    } while (a != 0);

    return 0;
}
