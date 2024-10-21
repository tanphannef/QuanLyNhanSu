#include "ThuVien.h"

void nhapDate(date& d)
{
	do
	{
		cout << "Nam: ";
		cin >> d.year;
	} while (d.year < 1);
	do
	{
		cout << "Thang: ";
		cin >> d.month;
	} while (d.month < 1 || d.month > 12);
	switch (d.month)
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
			cin >> d.day;
		} while (d.day < 1 || d.day > 31);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		do
		{
			cout << "Ngay: ";
			cin >> d.day;
		} while (d.day < 1 || d.day > 30);
		break;
	case 2:
		if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
		{
			do
			{
				cout << "Ngay: ";
				cin >> d.day;
			} while (d.day < 1 || d.day > 29);
		}
		else
		{
			do
			{
				cout << "Ngay: ";
				cin >> d.day;
			} while (d.day < 1 || d.day > 28);
		}
		break;
	default:
		break;
	}
}

//tim kiem User
NodeNhanVien* checkID(NodeNhanVien* dsnv)
{
	string id;
	NodeNhanVien* iduser = dsnv;
	while (iduser != nullptr)
	{
		if (iduser->user.id == id) 
		{
			return iduser;
		}
		iduser = iduser->link;
	}
	return nullptr;
}

void timKiemUser(NodeNhanVien* dsnv) 
{
	NodeNhanVien* foundUser = checkID(dsnv);
	string idToFind;
	cin.ignore();
	cout << "nhap id vao: ";
	getline(cin, idToFind);
	if (foundUser != nullptr)
	{
		cout << "tim thay nhan vien "<<foundUser->user.id << endl;
	}
	else 
	{
		cout << "khong tim thay nhan vien co ID: " << idToFind << endl;
	}
	return;
}



void xuatDate(date d)
{
	cout << d.day << "/" << d.month << "/" << d.year;
}

void nhapUser(User& user)
{
	cin.ignore();
	cout << "Nhap id: ";
	getline(cin, user.id);
	cout << "Nhap hoten: ";
	getline(cin, user.hoten);
	//Kiem tra dieu kien danh cho sdt
	do
	{
		cout << "Nhap sdt: ";
		getline(cin, user.sdt);

		if (!checkNumeric(user.sdt) || user.sdt.length() < 10 || user.sdt.length() > 11)
		{
			cout << "Sdt khong hop le xin moi nhap lai!" << endl;
		}
	} while (!checkNumeric(user.sdt) || user.sdt.length() < 10 || user.sdt.length() > 11);
	//Kiem tra dieu kien danh cho cccd
	do
	{				 
		cout << "Nhap CCCD: ";
		getline(cin, user.cccd);
		if (!checkNumeric(user.cccd) || user.cccd.length() < 12 || user.cccd.length() > 12)
		{
			cout << "CCCD khong hop le xin moi nhap lai!" << endl;
		}
	} while (!checkNumeric(user.cccd) || user.cccd.length() < 12 || user.cccd.length() > 12);

	cout << "Nhap ngay vao lam viec " << endl;
	nhapDate(user.ngayVaoLam);
	cin.ignore();
	cout << "Nhap chuc vu: ";
	getline(cin, user.chucvu);
	cout << "Nhap gioi tinh(1.nam/0.nu): ";
	cin >> user.gioitinh;
}

void xuatUser(User user)
{
	cout << "ID: " << user.id << endl;
	cout << "Hoten: " << user.hoten << endl;
	cout << "SDT: " << user.sdt << endl;
	cout << "CCCD: " << user.cccd << endl;
	cout << "Ngay vao lam: ";
	xuatDate(user.ngayVaoLam);
	cout << endl;
	cout << "Chuc vu: " << user.chucvu << endl;
	if (user.gioitinh)
	{
		cout << "Gioi tinh: nam" << endl;
	}
	else
	{
		cout << "Gioi tinh: nu" << endl;
	}
}

void nhapBangCap(BangCap &bc)
{
	cin.ignore();
	cout << "Nhap ma bang: ";
	getline(cin, bc.mabang);
	cout << "Nhap ten bang cap: ";
	getline(cin, bc.tenBangCap);
}

void xuatBangCap(BangCap bc)
{
	cout << "Ma bang cap: " << bc.mabang << endl;
	cout << "Ten bang cap: " << bc.tenBangCap << endl;
}

bool checkNumeric(string str)
{
	for (char k : str)
	{
		if (!isdigit(k))
		{
			return false;
		}
		return true;
	}
}

NodeNhanVien* CreateNode()
{
	NodeNhanVien *nv = new NodeNhanVien;
	nhapUser(nv->user);
	
	while (true)
	{
		char k;
		cout << "Ban co muon them bang cap cua minh khong(y/n)";
		cin >> k;
		if (k == 'n' || k == 'N')
			break;
		NodeBangCap* bc = new NodeBangCap;
		nhapBangCap(bc->data);
		bc->link = nv->listBC;
		nv->listBC = bc;
		nv->listBC->i++;
	}
	return nv;
}

void xuatNhanVien(NodeNhanVien* dsnv)
{
	xuatUser(dsnv->user);
	if (dsnv->listBC == NULL)
	{
		cout << "Khong co bang cap"<<endl;
	}
	while(dsnv->listBC != NULL)
	{
		xuatBangCap(dsnv->listBC->data);
		dsnv->listBC = dsnv->listBC->link;
	}

}

void themNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* nv)
{
	if (dsnv == NULL)
	{
		dsnv = nv;
		return;
	}
	nv->link = dsnv;
	dsnv = nv;

}

void themDSNhanVien(NodeNhanVien*& dsnv)
{
	char k;
	do
	{ 
		NodeNhanVien* n = CreateNode();
		themNhanVien(dsnv, n);
		cout << "Ban co muon tiep tuc them nhan vien khong(y/n): ";
		cin >> k;
	} while (k != 'n' && k != 'N');
}

void xuatDSNhanVien(NodeNhanVien* dsnv)
{
	while (dsnv != NULL)
	{
		xuatUser(dsnv->user);
		if (dsnv->listBC == NULL)
		{
			cout << "Khong co bang cap\n";
		}
		while (dsnv->listBC != NULL)
		{
			xuatBangCap(dsnv->listBC->data);
			dsnv->listBC = dsnv->listBC->link;
		}
		dsnv = dsnv->link;
	}
}
