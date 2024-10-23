#include "ThuVien.h"

int main()
{
    NodeNhanVien* dsnv = NULL;
    NodeNhanVien* id = NULL;  //dung de tim kiem theo id cho nguoi dung
    int a;
    do
    {
        system("cls");
        cout << "Danh Sach Menu" << "\n";
        cout << "0. Thoat" << "\n";
        cout << "1. them nhan vien" << "\n";
        cout << "2. xuat danh sach nhan vien" << "\n";
        cout << "3. xoa" << "\n";
        cout << "4. sua" << "\n";
        cout << "5. tim kiem theo id" << "\n";
        cout << "6. tim kiem theo chuc vu" << "\n";
        cout << "7. tim kiem theo ma bang" << "\n";
        cout << "8. doc file" << "\n";
        cout << "9. ghi file" << "\n";
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
        case 3://xoa
            xoaNhanVien(dsnv);
            break;
        case 4://sua
            suaThongTinNhanVien(dsnv);
            break;
        case 5://tim kiem theo id
            id = timKiemUser(dsnv);
            if (id != NULL)
            {
                xuatNhanVien(id);
            }
            else
            {
                cout << "Khong tim thay nhan vien!"<<endl;
            }
            break;
        case 6: //tim kiem theo chuc vu
            timKiemTheoChucVu(dsnv);
            break;
        case 7: //tim kiem theo ma bang cap
            timKiemTheoMaBang(dsnv);
            break;
        case 8://doc file
            if(readFile("danhSachNhanVien.txt", dsnv))
            {
                cout << "Nhap file thanh cong!" << endl;
            }
            else
            {
                cout << "Doc file that bai!" << endl;
            }
            break;
        case 9:
            if (writeFile("danhSachNhanVien.txt", dsnv))
            {
                cout << "Viet file thanh cong!" << endl;
            }
            else
            {
                cout << "Viet file that bai!" << endl;
            }
            break;
        default:
            cout << "nhap lai: "<<endl;
            break;
        }
        char check;
        cout << "Ban co muon tiep tuc khong(y/n): ";
        cin >> check;
        if (check == 'n' || check == 'N')
        {
            return 0 ;
        }

    } while (a != 0);

    return 0;
}
