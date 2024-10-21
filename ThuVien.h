#include <iostream>
#include <string>
#include <cctype> //thu vien chu ham isdigit() dung de kiem tra chuoi co chua ki tu khac so khong
using namespace std;

struct date
{
	int day = 0;
	int month = 0;
	int year = 0;

	//Tao phuong thuc khong can tham so
	date() {};

	//Tao phuong thuc truyen tham so
	date(int _d, int _m, int _y)
	{
		switch (_m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (_d > 0 && _d < 32)
			{
				day = _d;
				month = _m;
				year = _y;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (_d > 0 && _d < 31)
			{
				day = _d;
				month = _m;
				year = _y;
			}
			break;
		case 2:
			if (_y > 0)
			{
				if ((_y % 4 == 0 && _y % 100 != 0) || _y % 400 == 0)
				{
					if (_d > 0 && _d < 30)
					{
						day = _d;
						month = _m;
						year = _y;
					}
				}
				else
				{
					if (_d > 0 && _d < 29)
					{
						day = _d;
						month = _m;
						year = _y;
					}
				}
			}
			break;
		default:
			break;
		}
	}
};

struct User
{
	string id = "";
	string hoten = "";
	string sdt = "";
	string cccd = "";
	date ngayVaoLam;
	string chucvu = "";
	bool gioitinh = true;
};

struct BangCap
{
	string mabang = "";
	string tenBangCap = "";
};

struct NodeBangCap
{
	BangCap data;
	NodeBangCap* link = NULL;
	int i = 0;
};

struct NodeNhanVien
{
	User user;
	NodeBangCap *listBC = NULL;
	NodeNhanVien* link = NULL;
};

//Ham nhap va xuat cho struct date
void nhapDate(date& d);
void xuatDate(date d);

//Ham nhap va xuat cho struct User
void nhapUser(User& user);
void xuatUser(User user);

//Ham nhap va xuat cho struct BangCap
void nhapBangCap(BangCap& bc);
void xuatBangCap(BangCap bc);

NodeNhanVien* checkID(NodeNhanVien* dsnv);
void timKiemUser(NodeNhanVien* dsnv);

bool checkNumeric(string str);
NodeNhanVien* CreateNode();
void xuatNhanVien(NodeNhanVien *dsnv);
void themNhanVien(NodeNhanVien*& dsnv, NodeNhanVien *nv); //them nhan vien vao dau ds
void themDSNhanVien(NodeNhanVien*& dsnv); //them lien tuc nhan vien
void xuatDSNhanVien(NodeNhanVien* dsnv); // xuat tat ca nhan vien co trong ds
