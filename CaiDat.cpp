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

NodeNhanVien* checkCCCD(NodeNhanVien* dsnv, string cccd)
{
	NodeNhanVien* iduser = dsnv;
	while (iduser != NULL)
	{
		if (iduser->user.cccd == cccd)
		{
			return iduser;
		}
		iduser = iduser->link;
	}
	return NULL;
}

NodeNhanVien* checkSDT(NodeNhanVien* dsnv, string sdt)
{
	NodeNhanVien* iduser = dsnv;
	while (iduser != NULL)
	{
		if (iduser->user.sdt == sdt)
		{
			return iduser;
		}
		iduser = iduser->link;
	}
	return NULL;
}
NodeNhanVien* timKiemUser(NodeNhanVien* dsnv) 
{
	//NodeNhanVien* foundUser = checkID(dsnv);
	string idToFind;
	cin.ignore();
	cout << "nhap id vao: ";
	getline(cin, idToFind);
	NodeNhanVien* foundUser = checkID(dsnv, idToFind);
	if (foundUser != NULL)
	{
		return foundUser;
	}
	return NULL;
}

void xuatNhanVien(NodeNhanVien* dsnv)
{
	NodeNhanVien* n = dsnv;
	xuatUser(n->user);
	if (n->listBC == NULL)
	{
		cout << "Khong co bang cap" << endl;
	}
	NodeBangCap* tmp = n->listBC;
	while (tmp != NULL)
	{
		xuatBangCap(tmp->data);
		tmp = tmp->link;
	}
}
void xuatDate(date d)
{
	cout << d.day << "/" << d.month << "/" << d.year;
}

void nhapUser(User& user)
{
	cin.ignore();
	while (true)
	{
		cout << "Nhap id: ";
		getline(cin, user.id);
		if (user.id[0] != 'n' && user.id[0] != 'N')
		{
			cout << "Nhap id khong chinh xac vui long nhap lai!" << endl;
		}
		else if (user.id[1] != 'v' && user.id[1] != 'V')
		{
			cout << "Nhap id khong chinh xac vui long nhap lai!" << endl;
		}
		else if (user.id.length() < 5 || user.id.length() > 5)
		{
			cout << "Do dai phai la 5 ky tu!" << endl;
		}
		else
		{
			break;
		}
	}
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
	for (int i = 0; i < user.chucvu.length(); i++)
	{
		if (user.chucvu[i] == ' ')
		{
			user.chucvu.replace(i, 1, "");
		}
	}

	cout << "Nhap gioi tinh(1.nam/0.nu): ";
	cin >> user.gioitinh;
}

void xuatUser(User user)
{
	cout << "--------------------------\n";
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
	}
	return true;
}

NodeBangCap* checkBC(NodeBangCap* bc, string mabc)
{
	NodeBangCap* n = bc;
	while (n != NULL)
	{
		if (n->data.mabang == mabc)
		{
			return n;
		}
		n = n->link;
	}
	return NULL;
}
NodeNhanVien* CreateNode()
{
	NodeNhanVien *nv = new NodeNhanVien;
	nhapUser(nv->user);
	
	while (true)
	{
		char k;
		cout << "Ban co muon them bang cap cua minh khong(y/n): ";
		cin >> k;
		if (k == 'n' || k == 'N')
			break;
		NodeBangCap* bc = new NodeBangCap;
		nhapBangCap(bc->data);
		if (checkBC(nv->listBC, bc->data.mabang) != NULL)
		{
			cout << "Ma bang cap da ton tai!" << endl;
		}
		else
		{
			bc->link = nv->listBC;
			nv->listBC = bc;
			nv->listBC->i++;
		}
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
		if (checkID(dsnv, n->user.id) != NULL )
		{
			cout << "Id da ton tai!" << endl;
		}
		else if (checkSDT(dsnv, n->user.sdt) != NULL)
		{
			cout << "Sdt da ton tai!" << endl;
		}
		else if(checkCCCD(dsnv, n->user.cccd) != NULL)
		{
			cout << "Cccd da ton tai!" << endl;
		}
		else
		{
			themNhanVien(dsnv, n);
		}
		cout << "Ban co muon tiep tuc them nhan vien khong(y/n): ";
		cin >> k;
	} while (k != 'n' && k != 'N');
}

void xuatDSNhanVien(NodeNhanVien* dsnv)
{
	if (dsnv == NULL)
	{
		cout << "Danh sach dang trong!" << endl;
		return;
	}
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
int demSoLuongNhanVien(NodeNhanVien* dsnv)
{
	int dem = 0;
	NodeNhanVien* n = dsnv;
	while (n != NULL)
	{
		dem++;
		n = n->link;
	}
	return dem;
}
int readFile(const char* filename, NodeNhanVien*& dsnv)
{
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	if (fp == NULL)
	{
		return 0;
	}
	int dem;
	fscanf_s(fp, "%d", &dem);
	for (int i = 0; i < dem; i++)
	{
		NodeNhanVien* tmp = new NodeNhanVien();
		char buffer[51];
		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->user.id = buffer;

		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->user.hoten = buffer;

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
	return 1;
}
int writeFile(const char* filename, NodeNhanVien* dsnv)
{
	FILE* fp;
	fopen_s(&fp, filename, "wt");
	if (fp == NULL)
	{
		return 0;
	}
	fprintf_s(fp, "%d", demSoLuongNhanVien(dsnv));
	NodeNhanVien* p = dsnv;
	while (p != NULL)
	{
		fprintf_s(fp, "\n");
		fprintf_s(fp, "%s", p->user.id.c_str());
		
		//Xoa khoang trang o trong chuoi
		for (int i = 0; i < p->user.hoten.length(); i++)
		{
			if (p->user.hoten[i] == ' ')
			{
				p->user.hoten.replace(i, 1, "");
			}
		}
		fprintf_s(fp, "\t%s", p->user.hoten.c_str());

		fprintf_s(fp, "\t%s", p->user.sdt.c_str());
		fprintf_s(fp, "\t%s", p->user.cccd.c_str());
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.day);
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.month);
		fprintf_s(fp, "\t%d", p->user.ngayVaoLam.year);
		fprintf_s(fp, "\t%s", p->user.chucvu.c_str());
		fprintf_s(fp, "\t%d", p->user.gioitinh);

		NodeBangCap* tmp = p->listBC;
		if (tmp == NULL)
		{
			fprintf_s(fp, "\t%d", 0);
		}
		else
		{
			fprintf_s(fp, "\t%d", tmp->i);
		}
		while (tmp != NULL)
		{
			fprintf_s(fp, "\t%s", tmp->data.mabang.c_str());
			fprintf_s(fp, "\t%s", tmp->data.tenBangCap.c_str());
			tmp = tmp->link;
		}
		p = p->link;
	}
	fclose(fp);
	return 1;
}

void xoaDau(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL)
		return;
	if (dsnv->link == NULL)
	{
		dsnv = NULL;
		return;
	}
	NodeNhanVien* n = dsnv;
	dsnv = dsnv->link;
	n->link = NULL;
	delete n;
}

void xoaCuoi(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL)
	{
		return;
	}
	NodeNhanVien* tmp = dsnv;
	while (tmp->link->link != NULL)
	{
		tmp = tmp->link;
	}
	NodeNhanVien* d = tmp->link;
	tmp->link = NULL;
	delete d;

}
void xoaNhanVien(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL)
	{
		cout << "danh sach trong!"<<endl;
		return;
	}
	string id;
	cin.ignore();
	cout << "Nhap id can tim: ";
	getline(cin, id);
	NodeNhanVien* tmp = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id == id)
		{
			break;
		}
		tmp = tmp->link;
	}
	
	if (tmp == NULL)
	{
		cout << "Khong tim thay id can xoa!" << endl;
		return;
	}
	else
	{
		if (tmp == dsnv)
		{
			xoaDau(dsnv);
		}
		else if (tmp->link == NULL)
		{
			xoaCuoi(dsnv);
		}
		else
		{
			dsnv->link = tmp->link;
			tmp->link = NULL;
			delete tmp;
		}
	}
	cout << "Xoa nhan vien thanh cong!" << endl;
}

void timKiemTheoChucVu(NodeNhanVien* dsnv)
{
	string chucvu;					 
	cin.ignore();
	cout << "Nhap chuc vu can tim: ";
	getline(cin, chucvu);
	//Xu ly khoang trang o giua chuoi
	for (int i = 0; i < chucvu.length(); i++)
	{
		if (chucvu[i] == ' ')
		{
			chucvu.replace(i, 1, "");
		}
	}
	NodeNhanVien* n = dsnv;
	bool flag = false;
	while (n != NULL)
	{
		if (n->user.chucvu == chucvu)
		{
			xuatNhanVien(n);
			flag = true;
		}
		n = n->link;
	}

	if (!flag)
	{
		cout << "Khong tim thay nhan vien co chuc vu: " << chucvu << endl;
		return;
	}
}

void timKiemTheoMaBang(NodeNhanVien* dsnv)
{
	string maBang;
	cin.ignore();
	cout << "Nhap ma bang can tim: ";
	getline(cin, maBang);
	bool flag = false;
	NodeNhanVien* n = dsnv;
	if (n == NULL)
	{
		cout << "Danh sach nhan vien rong!" << endl;
		return;
	}
	while (n != NULL)
	{
		NodeBangCap* tmp = n->listBC;

		while (tmp != NULL)
		{
			if (tmp->data.mabang == maBang)
			{
				xuatNhanVien(n);
				flag = true;
			}
			tmp = tmp->link;
		}
		
		n = n->link;
	}

	
	if (!flag)
	{
		cout << "Khong tim thay nhan vien co ma bang: " << maBang << endl;
		return;
	}
}

void subMenuSua()
{
	cout << "===============================================" << endl;
	cout << "===========MENU SUA THONG TIN NHAN VIEN========" << endl;
	cout << "|0. Thoat                                     |" << "\n";
	cout << "|1. Sua Ho Ten                                |" << "\n";
	cout << "|2. Sua SDT                                   |" << "\n";
	cout << "|3. Sua CCCD                                  |" << "\n";
	cout << "|4. Sua Ngay Vao Lam                          |" << "\n";
	cout << "|5. Sua Chuc Vu                               |" << "\n";
	cout << "|6. Sua Gioi Tinh                             |" << "\n";
	cout << "===============================================" << endl;
}

void suaThongTinNhanVien(NodeNhanVien*& dsnv)
{
	NodeNhanVien* n = timKiemUser(dsnv);
	if (n == NULL)
	{
		cout << "Khong tim thay id nhan vien can sua!" << endl;
	}
	else
	{
		int k;
		do {
			system("cls");
			xuatNhanVien(n);
			subMenuSua();
			cout << "Nhap lua chon: ";
			cin >> k;
			cin.ignore();
			switch (k)
			{
			case 0:
				return;
			case 1://sua ten
				cout << "Nhap ho ten:";
				getline(cin, n->user.hoten);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 2://sua sdt
				do
				{
					cout << "Nhap sdt: ";
					getline(cin, n->user.sdt);

					if (!checkNumeric(n->user.sdt) || n->user.sdt.length() < 10 || n->user.sdt.length() > 11)
					{
						cout << "Sdt khong hop le xin moi nhap lai!" << endl;
					}
				} while (!checkNumeric(n->user.sdt) || n->user.sdt.length() < 10 || n->user.sdt.length() > 11);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 3://sua cccd
				do
				{
					cout << "Nhap CCCD: ";
					getline(cin, n->user.cccd);
					if (!checkNumeric(n->user.cccd) || n->user.cccd.length() < 12 || n->user.cccd.length() > 12)
					{
						cout << "CCCD khong hop le xin moi nhap lai!" << endl;
					}
				} while (!checkNumeric(n->user.cccd) || n->user.cccd.length() < 12 || n->user.cccd.length() > 12);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 4://sua ngay vao lam
				cout << "Nhap ngay vao lam viec " << endl;
				nhapDate(n->user.ngayVaoLam);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 5://sua chuc vu
				cout << "Nhap chuc vu: ";
				getline(cin, n->user.chucvu);
				
				for (int i = 0; i < n->user.chucvu.length(); i++)
				{
					if (n->user.chucvu[i] == ' ')
					{
						n->user.chucvu.replace(i, 1, "");
					}
				}
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 6://sua gioi tinh
				cout << "Nhap gioi tinh(1.nam/0.nu): ";
				cin >> n->user.gioitinh;
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			default:
				cout << "Nhap lai\n";
				break;
			}
			char check;
			cout << "Ban co muon tiep tuc sua khong(y/n): ";
			cin >> check;
			if (check == 'n' || check == 'N')
			{
				return;
			}
		} while (k != 0);
	}
}

void subMenuTimKiem()
{
	cout << "======================================================" << endl;
	cout << "==============MENU TIM KIEM NHAN VIEN=================" << endl;
	cout << "|0. Thoat                                            |" << endl;
	cout << "|1. Tim kiem theo ID                                 |" << endl;
	cout << "|2. Tim kiem theo chuc vu                            |" << endl;
	cout << "|3. Tim kiem theo ma bang                            |" << endl;
	cout << "======================================================" << endl;
}

void timKiem(NodeNhanVien*& dsnv)
{
	NodeNhanVien* id = NULL;
	int k;
	do
	{
		system("cls");
		subMenuTimKiem();
		cout << "Nhap Lua Chon: ";
		cin >> k;
		switch (k)
		{
		case 0:
			return;
		case 1:
			id = timKiemUser(dsnv);
			if (id != NULL)
			{
				xuatNhanVien(id);
				toHopXoaSuaThemBC(dsnv);
			}
			else
			{
				cout << "Khong tim thay nhan vien!" << endl;
			}
			break;
		case 2:
			timKiemTheoChucVu(dsnv);
			break;
		case 3:
			timKiemTheoMaBang(dsnv);
			break;
		default:
			cout << "Nhap lai\n";
			break;
		}
		char check;
		cout << "Ban co muon tiep tuc tim kiem nhan vien khong(y/n): ";
		cin >> check;
		if (check == 'n' || check == 'N')
		{
			return;
		}
	} while (k != 0);
}

void subMenuXoaSuaThemBC()
{
	cout << "=================================" << endl;
	cout << "|Ban muon lam gi tiep theo?     |" << endl;
	cout << "|0. Thoat                       |" << endl;
	cout << "|1. Them Bang Cap               |" << endl;
	cout << "|2. Xoa Nhan Vien               |" << endl;
	cout << "|3. Sua Thong Tin Nhan Vien     |" << endl;
	cout << "=================================" << endl;
}
void toHopXoaSuaThemBC(NodeNhanVien*& dsnv)
{
	int k;
	do {
		subMenuXoaSuaThemBC();
		cout << "Nhap lua chon: ";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 0:
			return;
		case 1:
			themBC(dsnv);
			break;
		case 2:
			xoaNhanVien(dsnv);
			break;
		case 3:
			suaThongTinNhanVien(dsnv);
			break;
		default:
			cout << "nhap lai\n ";
			break;
		}
	} while (k != 0);
}

void themBC(NodeNhanVien*& dsnv)
{
	NodeNhanVien* id = timKiemUser(dsnv);
	if (id == NULL)
	{
		cout << "Khong tim thay user!" << endl;
		return;
	}
	while (true)
	{
		char check;
		cout << "Ban co muon them bang cap khong(y/n): ";
		cin >> check;
		if (check == 'n' || check == 'N')
			break;
		NodeBangCap* n = new NodeBangCap();
		nhapBangCap(n->data);
		//NodeBangCap* tmp = id->listBC;
		if (checkBC(id->listBC, n->data.mabang) != NULL)
		{
			cout << "Ma bang cap da ton tai!" << endl;
		}
		else
		{
			n->link = id->listBC;
			id->listBC = n;
			id->listBC->i++;
			cout << "Them thanh cong!" << endl;
		}
	}
}
