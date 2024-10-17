#include <iostream>
#include <string>
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

struct user
{
	string id = "";
	string hoten = "";
	string sdt = "";
	string ccd = "";
	date ngayVaoLam;
	string chucvu = "";
	bool gioitinh = true;
};

struct bangCap
{
	string mabang = "";
	string tenBangCap = "";
};

struct userBangCap
{
	string id = "";
	string mabang = "";
};



