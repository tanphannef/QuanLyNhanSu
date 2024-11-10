#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype> //thu vien chu ham isdigit() dung de kiem tra chuoi co chua ki tu khac so khong
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>
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
};

struct NodeNhanVien
{
	User user;
	NodeBangCap* listBC = NULL;
	NodeNhanVien* link = NULL;
	int demBC = 0;
};

//Ham nhap va xuat cho struct date
void nhapDate(date& d);
void xuatDate(date d);

//Ham nhap va xuat cho struct User
void nhapUser(NodeNhanVien* dsnv, User& user);
void xuatUser(User user);

//Ham nhap va xuat cho struct BangCap
void nhapBangCap(BangCap& bc);
void xuatBangCap(BangCap bc);

//Ham kiem tra 1 chuoi co toan ki tu so hay khong
bool checkNumeric(string str);

NodeNhanVien* CreateNode(NodeNhanVien* dsnv);
void themNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* nv); //them nhan vien vao dau ds
void xuatNhanVien(NodeNhanVien* dsnv);

void themBC(NodeBangCap*& dsbc, NodeBangCap* n);
void themBC(NodeNhanVien*& dsnv, NodeNhanVien* id);

void themDSNhanVien(NodeNhanVien*& dsnv); //them lien tuc nhan vien
void xuatDSNhanVien(NodeNhanVien* dsnv); // xuat tat ca nhan vien co trong ds

//Ham doc va ghi file txt
int readFile(const char* filename, NodeNhanVien*& dsnv);
int writeFile(const char* filename, NodeNhanVien* dsnv);

//Ham doc va ghi file QLBC
int readFile(const char* filename, NodeBangCap*& dsbc);
int writeFile(const char* filename, NodeBangCap* dsbc);


NodeNhanVien* checkID(NodeNhanVien* dsnv, string id);
NodeNhanVien* checkCCCD(NodeNhanVien* dsnv, string cccd);
NodeNhanVien* checkSDT(NodeNhanVien* dsnv, string sdt);
NodeBangCap* checkBC(NodeBangCap* bc, string mabc);

void timKiem(NodeNhanVien*& dsnv);
NodeNhanVien* timKiemUser(NodeNhanVien* dsnv);
NodeNhanVien* timKiemTheoChucVu(NodeNhanVien* dsnv, string chucvu);
void xuatDanhSachChucVu(NodeNhanVien* dsnv);
void timKiemTheoMaBang(NodeNhanVien* dsnv);
void suaThongTinNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* n);

//Chuan hoa chuoi du lieu
void chuanHoaChuoi(string& str);

void subMenuSua();
void subMenuTimKiem();

void subMenuXoaSuaThemBC();
void toHopXoaSuaThemBC(NodeNhanVien*& dsnv, NodeNhanVien* n);

//Cac ham xoa NhanVien
void xoaDau(NodeNhanVien*& dsnv);
void xoaCuoi(NodeNhanVien*& dsnv);
void xoaNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* n);

//Cac ham xoa BangCap
void xoaDau(NodeBangCap*& bc);
void xoaCuoi(NodeBangCap*& bc);
void xoaBangCap(NodeNhanVien*& dsnv, NodeNhanVien* n);
//void SuaBangCap(NodeNhanVien*& dsnv, NodeNhanVien* n);

NodeBangCap* taoDanhSachBC(NodeNhanVien* dsnv, NodeBangCap* dsbc);
void xuatDSBangCap(NodeBangCap *& dsbc, NodeNhanVien* dsnv);
void xuatDSBangCap(NodeBangCap* dsbc);
void subMenuQLBC();
void QuanLyBangCap(NodeNhanVien* dsnv, NodeBangCap*& dsbc);


bool checkNhanVienSoHuuBangCap(NodeNhanVien* dsnv, string mabang);
void xoaBangCap(NodeBangCap*& dsbc, NodeNhanVien* dsnv);
void subMenuQLNV();
void QuanLyNhanVien(NodeNhanVien*& dsnv);

void menuThongKe();
void thongKe(NodeNhanVien* dsnv, NodeBangCap* dsbc);

//Cac ham dem
int demSoLuongNhanVien(NodeNhanVien* dsnv);
int demSoLuongBangCap(NodeBangCap* dsbc);
void demSoLuongNhanVienNamNu(NodeNhanVien* dsnv, int &nam, int &nu);
void demSoLuongBangCapCuaMoiNhanVien(NodeNhanVien* dsnv);
int tinhSoNgayDaLamViec(int ngay, int thang, int nam);
void xuatSoNgayDaLamViec(NodeNhanVien* dsnv);
