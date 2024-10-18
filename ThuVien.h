#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

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

	//Ham nhap ngay cho user
	void nhapDate()
	{
		do
		{
			cout << "Nam: ";
			cin >> year;
		} while (year < 1);
		do
		{
			cout << "Thang: ";
			cin >> month;
		} while (month < 1 || month > 12);
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			do
			{
				cout << "Ngay: ";
				cin >> day;
			} while (day < 1 || day > 31);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			do
			{
				cout << "Ngay: ";
				cin >> day;
			} while (day < 1 || day > 30);
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				do
				{
					cout << "Ngay: ";
					cin >> day;
				} while (day < 1 || day > 29);
			}
			else
			{
				do
				{
					cout << "Ngay: ";
					cin >> day;
				} while (day < 1 || day > 28);
			}
			break;
		default:
			break;
		}
	}

	//Ham xuat ngay cho user
	void xuatDate()
	{
		cout << day<<"/"<<month<<"/"<<year;
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

	void nhapUser()
	{
		cout << "Nhap id: ";
		getline(cin, id);
		cout << "Nhap hoten: ";
		getline(cin, hoten);
		cout << "Nhap sdt: ";
		getline(cin, sdt);
		cout << "Nhap CCCD: ";
		getline(cin, cccd);
		cout << "Nhap ngay: " << endl;
		ngayVaoLam.nhapDate();
		cin.ignore();
		cout << "Nhap chuc cu: ";
		getline(cin, chucvu);
		cout << "Nhap gioi tinh(1.nam/0.nu): ";
		cin >> gioitinh;
	}

	void xuatUser()
	{
		cout << "ID: " << id << endl;
		cout << "Hoten: " << hoten << endl;
		cout << "SDT: " << sdt << endl;
		cout << "CCCD: " << cccd << endl;
		cout << "Ngay vao lam: ";
		ngayVaoLam.xuatDate();
		cout << endl;
		cout << "Chuc vu: " << chucvu << endl;
		cout << "Gioi tinh: " << gioitinh << endl;
	}
};

struct BangCap
{
	string mabang = "";
	string tenBangCap = "";

	void nhapBangCap()
	{
		cin.ignore();
		cout << "Nhap ma bang: ";
		getline(cin, mabang);
		cout << "Nhap ten bang cap: ";
		getline(cin, tenBangCap);
	}

	void xuatBangCap()
	{
		cout << "Ma bang cap: " << mabang << endl;
		cout << "Ten bang cap: " << tenBangCap << endl;
	}
};

struct NodeBangCap
{
	BangCap data;
	NodeBangCap* link = NULL;
	int i = 0;
};

struct UserBangCap
{
	string id = "";
	string mabang = "";
};


struct NodeNhanVien
{
	User user;
	NodeBangCap *listBC = NULL;
	//UserBangCap ubc;
	NodeNhanVien* link = NULL;
};

NodeNhanVien* CreateNode();
void xuatNhanVien(NodeNhanVien *dsnv);


