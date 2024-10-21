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
NodeNhanVien* checkID(NodeNhanVien* dsnv, string id)
{
	NodeNhanVien* iduser = dsnv;
	while (iduser != NULL)
	{
		if (iduser->user.id == id)
		{
			return iduser;
		}
		iduser = iduser->link;
	}
	return NULL;
}

void timKiemUser(NodeNhanVien* dsnv)
{
	string idToFind;
	cin.ignore();
	cout << "nhap id vao: ";
	getline(cin, idToFind);
	NodeNhanVien* foundUser = checkID(dsnv, idToFind);
	if (foundUser != NULL)
	{
		xuatNhanVien(foundUser);
	}
	else
	{
		cout << "khong tim thay nhan vien co ID: " << idToFind << endl;
	}
	return;
}

//xoa User
void xoaNhanVien(NodeNhanVien* &dsnv, string idToDelete)
{
	if (dsnv == NULL) 
	{
		cout << "danh sach trong!";
		return;
	}

	NodeNhanVien* tmp = dsnv;
	if (tmp != NULL && tmp->user.id == idToDelete)
	{
		dsnv = tmp->link;
		delete tmp;
		return;
	}

	NodeNhanVien* prev = NULL;
	while (tmp != NULL && tmp->user.id != idToDelete)
	{
		prev = tmp;
		tmp = tmp->link;
	}

	prev->link = tmp->link;

	delete tmp;
}

void xoaUser(NodeNhanVien* dsnv) 
{
	string idToDelete;
	cin.ignore();
	cout << "nhap id vao: ";
	getline(cin, idToDelete);
	NodeNhanVien* foundUser = checkID(dsnv, idToDelete);
	if (foundUser != NULL)
	{
		xoaNhanVien(dsnv,idToDelete);
	}
	else
	{
		cout << "khong tim thay nhan vien co ID: " << idToDelete <<"de xoa"<< endl;
	}
	return;
}

void xuatNhanVien(NodeNhanVien* dsnv)
{
	xuatUser(dsnv->user);
	if (dsnv->listBC == NULL)
	{
		cout << "Khong co bang cap" << endl;
	}
	while (dsnv->listBC != NULL)
	{
		xuatBangCap(dsnv->listBC->data);
		dsnv->listBC = dsnv->listBC->link;
	}
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

void nhapBangCap(BangCap& bc)
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
	NodeNhanVien* nv = new NodeNhanVien;
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
	NodeNhanVien* p = dsnv;
	while (p != NULL)
	{
		xuatUser(p->user);
		NodeBangCap* tmp = p->listBC;
		if (tmp == NULL)
		{
			cout << "Khong co bang cap" << endl;
		}
		while (tmp != NULL)
		{
			xuatBangCap(tmp->data);
			tmp = tmp->link;
		}
		p = p->link;
	}
}

int readFile(const char* filename, NodeNhanVien*& dsnv)
{
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	if (fp == NULL)
	{
		return 0;
	}
	NodeNhanVien* tmp = new NodeNhanVien();
	char buffer[51];
	fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
	buffer[50] = '\0';
	tmp->user.id = buffer;

	char ho[11], tenlot[11], ten[11];
	fscanf_s(fp, "%10s", ho, (unsigned)_countof(ho));
	ho[10] = '\0';

	fscanf_s(fp, "%10s", tenlot, (unsigned)_countof(tenlot));
	tenlot[10] = '\0';

	fscanf_s(fp, "%10s", ten, (unsigned)_countof(ten));
	ten[10] = '\0';

	tmp->user.hoten = string(ho) + " " + string(tenlot) + " " + string(ten);

	fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
	buffer[50] = '\0';
	tmp->user.sdt = buffer;

	fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
	buffer[50] = '\0';
	tmp->user.cccd = buffer;

	fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.day);
	fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.month);
	fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.year);
	fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
	buffer[50] = '\0';
	tmp->user.chucvu = buffer;

	int gioitinh;
	fscanf_s(fp, "%d", &gioitinh);
	tmp->user.gioitinh = (gioitinh != 0);
	int dem;
	fscanf_s(fp, "%d", &dem);
	for (int i = 0; i < dem; i++)
	{
		NodeBangCap* bc = new NodeBangCap();
		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		bc->data.mabang = buffer;

		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		bc->data.tenBangCap = buffer;

		bc->link = tmp->listBC;
		tmp->listBC = bc;
	}
	themNhanVien(dsnv, tmp);
}
int writeFile(const char* filename, NodeNhanVien* dsnv)
{
	FILE* fp;
	fopen_s(&fp, filename, "wt");
	if (fp == NULL)
	{
		return 0;
	}
	NodeNhanVien* p = dsnv;
	while (p != NULL)
	{
		fprintf_s(fp, "\n");
		fprintf_s(fp, "%s", p->user.id.c_str());
		fprintf_s(fp, "\t%s", p->user.hoten.c_str());
		fprintf_s(fp, "\t%s", p->user.sdt.c_str());
		fprintf_s(fp, "\t%s", p->user.cccd.c_str());
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.day);
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.month);
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.year);
		fprintf_s(fp, "\t%s", p->user.chucvu.c_str());
		fprintf_s(fp, "\t%d", p->user.gioitinh);

		NodeBangCap* tmp = p->listBC;
		while (tmp != NULL)
		{
			fprintf_s(fp, "\t%d", tmp->i);
			fprintf_s(fp, "\t%s", tmp->data.mabang.c_str());
			fprintf_s(fp, "\t%s", tmp->data.tenBangCap.c_str());
			tmp = tmp->link;
		}
		p = p->link;
	}
	fclose(fp);
	return 1;
}
