#include "ThuVien.h"

void nhapDate(date& d)
{
	time_t t = time(nullptr);
	tm* now = localtime(&t);
	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	while (true)
	{
		string ngayVaoLam;
		cout << "Nhap ngay vao lam viec(vd: 28/09/2024): ";
		getline(cin, ngayVaoLam);
		int ngay, thang, nam;
		int dem = sscanf(ngayVaoLam.c_str(), "%d/%d/%d", &ngay, &thang, &nam);
		if (dem == 3)
		{
			do
			{
				d.year = nam;
				if (d.year < 1 || d.year > year)
				{
					cout << "Nhap nam khong chinh xac vui long nhap lai nam!" << endl;
					cout << "Nam: ";
					cin >> nam;
					d.year = nam;
				}
			} while (d.year < 1 || d.year > year);
			do
			{
				d.month = thang;
				if (d.month < 1 || d.month > 12 || (d.month > month && d.year == year))
				{
					cout << "Nhap thang khong chinh xac vui long nhap lai thang!" << endl;
					cout << "Thang: ";
					cin >> thang;
					d.month = thang;
				}
			} while (d.month < 1 || d.month > 12 || (d.month > month && d.year == year));
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
					d.day = ngay;
					if (d.day < 1 || d.day > 31 || (d.day > now->tm_mday && d.year == year && d.month == month))
					{
						cout << "Ngap ngay khong chinh xac vui long nhap lai ngay)!" << endl;
						cout << "Ngay: ";
						cin >> ngay;
						d.day = ngay;
					}
				} while (d.day < 1 || d.day > 31 || (d.day > now->tm_mday && d.year == year && d.month == month));
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				do
				{
					d.day = ngay;
					if (d.day < 1 || d.day > 30 || (d.day > now->tm_mday && d.year == year && d.month == month))
					{
						cout << "Ngap ngay khong chinh xac vui long nhap lai ngay!" << endl;
						cout << "Ngay: ";
						cin >> ngay;
						d.day = ngay;
					}
				} while (d.day < 1 || d.day > 30 || (d.day > now->tm_mday && d.year == year && d.month == month));
				break;
			case 2:
				if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
				{
					do
					{
						d.day = ngay;
						if (d.day < 1 || d.day > 29 || (d.day > now->tm_mday && d.year == year && d.month == month))
						{
							cout << "Ngap ngay khong chinh xac vui long nhap lai ngay!" << endl;
							cout << "Ngay: ";
							cin >> ngay;
							d.day = ngay;
						}
					} while (d.day < 1 || d.day > 29 || (d.day > now->tm_mday && d.year == year && d.month == month));
				}
				else
				{
					do
					{
						d.day = ngay;
						if (d.day < 1 || d.day > 28 || (d.day > now->tm_mday && d.year == year && d.month == month))
						{
							cout << "Ngap ngay khong chinh xac vui long nhap lai ngay!" << endl;
							cout << "Ngay: ";
							cin >> ngay;
							d.day = ngay;
						}
					} while (d.day < 1 || d.day > 28 || (d.day > now->tm_mday && d.year == year && d.month == month));
				}
				break;
			default:
				break;
			}
		}
		cout << "Ngay da nhap: " << d.day << "/" << d.month << "/" << d.year << endl;
		char check;
		cout << "Ban co muon luu ngay nay khong(y/n): ";
		cin >> check;
		if (check == 'y' || check == 'Y')
			break;
		else if (check == 'n' || check == 'N')
			cin.ignore();

	}
}

//tim kiem User
NodeNhanVien* checkID(NodeNhanVien* dsnv, string id)
{
	NodeNhanVien* n = NULL;
	NodeNhanVien* iduser = dsnv;
	while (iduser != NULL)
	{
		if (iduser->user.id.find(id) != string::npos)
		{
			NodeNhanVien* tmp = new NodeNhanVien(*iduser);
			themNhanVien(n, tmp);
		}
		iduser = iduser->link;
	}
	return n;
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
	for (int i = 0; i < idToFind.length(); i++)
	{
		if (idToFind[i] >= 'a' && idToFind[i] <= 'z')
			idToFind[i] = idToFind[i] - 32;
	}
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
	cout << "---------------------------------------------------------------------------------------------------------\n";
	cout << "|" << "ID" << setw(5) << "|" << setw(10) << "Ho Ten" << setw(10) << "|" << setw(6) << "SDT" << setw(8) << "|" << setw(10) << "CCCD" << setw(8) << "|" << setw(10) << "Ngay Vao Lam" << setw(7) << "|" << setw(10) << "Chuc Vu" << setw(5) << "|" << setw(10) << "Gioi Tinh" << "|" << endl;
	cout << "|------|-------------------|-------------|-----------------|------------------|--------------|----------|\n";
	xuatUser(n->user);
	NodeBangCap* tmp = n->listBC;
	cout << "--------------------\n";
	cout << "|" << "Ma BC" << setw(2) << "|" << "Ten BC" << setw(6) << "|"<<endl;
	cout << "|------|-----------|\n";
	if (tmp == NULL)
	{
		cout << "Khong Co Bang Cap" << endl;
	}
	while (tmp != NULL)
	{
		xuatBangCap(tmp->data);
		tmp = tmp->link;
	}
}
void xuatDate(date d)
{
	string date = to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year);
	cout << date;
	switch (date.length())
	{
	case 5:
		cout << setw(14);
		break;
	case 6:
		cout << setw(13);
		break;
	case 7:
		cout << setw(12);
		break;
	case 8:
		cout << setw(11);
		break;
	case 9:
		cout << setw(10);
		break;
	case 10:
		cout << setw(9);
		break;
	default:
		break;
	}

}

void nhapUser(NodeNhanVien* dsnv, User& user)
{
	cin.ignore();
	system("cls");
	while (true)
	{
		string id;
		cout << "Nhap id: ";
		getline(cin, id);
		for (int i = 0; i < id.length(); i++)
		{
			if (id[i] >= 'A' && id[i] <= 'Z') continue;
			if (i == 2) break;
			id[i] = id[i] - 32;

		}
		if (id[0] != 'n' && id[0] != 'N')
		{
			cout << "Nhap id khong chinh xac vui long nhap lai!" << endl;
		}
		else if (id[1] != 'v' && id[1] != 'V')
		{
			cout << "Nhap id khong chinh xac vui long nhap lai!" << endl;
		}
		else if (id.length() < 5 || id.length() > 5)
		{
			cout << "Do dai phai la 5 ky tu!" << endl;
		}
		else if (checkID(dsnv, id) != NULL)
		{
			cout << "Id Da Ton Tai!" << endl;
		}
		else
		{
			user.id = id;
			break;
		}
	}
	cout << "Nhap hoten: ";
	getline(cin, user.hoten);
	chuanHoaChuoi(user.hoten);
	//Kiem tra dieu kien danh cho sdt
	do
	{
		cout << "Nhap sdt: ";
		getline(cin, user.sdt);

		if (!checkNumeric(user.sdt) || user.sdt.length() < 10 || user.sdt.length() > 11)
		{
			cout << "Sdt khong hop le xin moi nhap lai!" << endl;
		}
		else if (checkSDT(dsnv, user.sdt) != NULL)
		{
			cout << "Sdt da ton tai!" << endl;
		}
	} while (!checkNumeric(user.sdt) || user.sdt.length() < 10 || user.sdt.length() > 11 || checkSDT(dsnv, user.sdt) != NULL);
	//Kiem tra dieu kien danh cho cccd
	do
	{
		cout << "Nhap CCCD: ";
		getline(cin, user.cccd);
		if (!checkNumeric(user.cccd) || user.cccd.length() < 12 || user.cccd.length() > 12)
		{
			cout << "CCCD khong hop le xin moi nhap lai!" << endl;
		}
		else if (checkCCCD(dsnv, user.cccd) != NULL)
		{
			cout << "Cccd da ton tai!" << endl;
		}
	} while (!checkNumeric(user.cccd) || user.cccd.length() < 12 || user.cccd.length() > 12 || checkCCCD(dsnv, user.cccd) != NULL);

	nhapDate(user.ngayVaoLam);
	cin.ignore();
	cout << "Nhap chuc vu: ";
	getline(cin, user.chucvu);
	chuanHoaChuoi(user.chucvu);
	int gioitinh;
	do
	{
		cout << "Nhap gioi tinh(1.nam/0.nu): ";
		cin >> gioitinh;;
	} while (gioitinh < 0 || gioitinh > 1);
	user.gioitinh = gioitinh;
}

void xuatUser(User user)
{
	cout << "|" << user.id << " " << "|" << user.hoten;
	switch (user.hoten.length())
	{
	case 0:
		cout << setw(20);
		break;
	case 1:
		cout << setw(19);
		break;
	case 2:
		cout << setw(18);
		break;
	case 3:
		cout << setw(17);
		break;
	case 4:
		cout << setw(16);
		break;
	case 5:
		cout << setw(15);
		break;
	case 6:
		cout << setw(14);
		break;
	case 7:
		cout << setw(13);
		break;
	case 8:
		cout << setw(12);
		break;
	case 9:
		cout << setw(11);
		break;
	case 10:
		cout << setw(10);
		break;
	case 11:
		cout << setw(9);
		break;
	case 12:
		cout << setw(8);
		break;
	case 13:
		cout << setw(7);
		break;
	case 14:
		cout << setw(6);
		break;
	case 15:
		cout << setw(5);
		break;
	case 16:
		cout << setw(4);
		break;
	case 17:
		cout << setw(3);
		break;
	case 18:
		cout << setw(2);
		break;
	case 19:
		cout << setw(1);
		break;
	case 20:
		cout << setw(0);
		break;
	default:
		break;
	}
	cout << "|" << "  " << user.sdt;
	switch (user.sdt.length())
	{
	case 10:
		cout << setw(2);
		break;
	case 11:
		cout << setw(1);
		break;
	default:
		break;
	}
	cout << "|" << "   " << user.cccd << "  " << "|";
	xuatDate(user.ngayVaoLam);
	cout << "|" << user.chucvu << " ";
	switch (user.chucvu.length())
	{
	case 0:
		cout << setw(14);
		break;
	case 1:
		cout << setw(13);
		break;
	case 2:
		cout << setw(12);
		break;
	case 3:
		cout << setw(11);
		break;
	case 4:
		cout << setw(10);
		break;
	case 5:
		cout << setw(9);
		break;
	case 6:
		cout << setw(8);
		break;
	case 7:
		cout << setw(7);
		break;
	case 8:
		cout << setw(6);
		break;
	case 9:
		cout << setw(5);
		break;
	case 10:
		cout << setw(4);
		break;
	case 11:
		cout << setw(3);
		break;
	case 12:
		cout << setw(2);
		break;
	case 13:
		cout << setw(1);
		break;
	case 14:
		cout << setw(0);
		break;
	default:
		break;
	}
	cout << "|" << " ";
	if (user.gioitinh)
	{
		cout << "NAM";
		cout << "      " << "|" << endl;
	}
	else
	{
		cout << "NU";
		cout << "       " << "|" << endl;
	}
}

void nhapBangCap(BangCap& bc)
{
	int k;
	do {
		cout << "===============================================" << endl;
		cout << "====================BANG CAP===================" << endl;
		cout << "|1. IELTS(IS)									" << "\n";
		cout << "|2. TOEIC(TC)									" << "\n";
		cout << "|3. TOFFEL(TF)									" << "\n";
		cout << "|4. OTHER...								    " << "\n";
		cout << "===============================================" << endl;
		cout << "Nhap lua chon: ";
		cin >> k;
		switch (k)
		{
		case 1:
			bc.mabang = "IS";
			bc.tenBangCap = "IELTS";
			return;
		case 2:
			bc.mabang = "TC";
			bc.tenBangCap = "TOEIC";
			return;
		case 3:
			bc.mabang = "TF";
			bc.tenBangCap = "TOFFEL";
			return;
		case 4:
			cin.ignore();
			cout << "Nhap ma bang: ";
			getline(cin, bc.mabang);
			for (int i = 0; i < bc.mabang.length(); i++)
			{
				if (bc.mabang[i] == 'a' && bc.mabang[i] == 'z')
				{
					bc.mabang[i] -= 32;
				}
			}
			cout << "Nhap ten bang cap: ";
			getline(cin, bc.tenBangCap);
			return;
		default:
			cout << "Nhap lai\n";
			break;
		}
	} while (k != 0);
}

void xuatBangCap(BangCap bc)
{
	cout << "|"<<bc.mabang;
	switch (bc.mabang.length())
	{
	case 0:
		cout << setw(7);
		break;
	case 1:
		cout << setw(6);
		break;
	case 2:
		cout << setw(5);
		break;
	case 3:
		cout << setw(4);
		break;
	case 4:
		cout << setw(3);
		break;
	case 5:
		cout << setw(2);
		break;
	case 6:
		cout << setw(1);
		break;
	default:
		break;
	}
	cout << "|"<<bc.tenBangCap;
	switch (bc.tenBangCap.length())
	{
	case 0:
		cout << setw(12);
		break;
	case 1:
		cout << setw(11);
		break;
	case 2:
		cout << setw(10);
		break;
	case 3:
		cout << setw(9);
		break;
	case 4:
		cout << setw(8);
		break;
	case 5:
		cout << setw(7);
		break;
	case 6:
		cout << setw(6);
		break;
	case 7:
		cout << setw(5);
		break;
	case 8:
		cout << setw(4);
		break;
	case 9:
		cout << setw(3);
		break;
	case 10:
		cout << setw(2);
		break;
	case 11:
		cout << setw(1);
		break;
	default:
		break;
	}
	cout << "|"<<endl;
}

NodeBangCap* taoDanhSachBC(NodeNhanVien* dsnv, NodeBangCap* dsbc)
{
	NodeNhanVien* tmp = dsnv;

	// Duyệt qua từng nhân viên
	while (tmp != NULL) {
		NodeBangCap* tam = tmp->listBC;
		while (tam != NULL) {
			if (checkBC(dsbc, tam->data.mabang) == NULL) // Kiểm tra nếu chưa tồn tại
			{
				NodeBangCap* newBC = new NodeBangCap();
				newBC->data = tam->data;
				newBC->link = dsbc;
				dsbc = newBC;
			}
			tam = tam->link;
		}
		tmp = tmp->link;
	}
	return dsbc;
}
void xuatDSBangCap(NodeBangCap*& dsbc, NodeNhanVien* dsnv)
{
	dsbc = taoDanhSachBC(dsnv, dsbc);
	NodeBangCap* n = dsbc;
	cout << "--------------------\n";
	cout << "|" << "Ma BC" << setw(2) << "|" << "Ten BC" << setw(6) << "|" << endl;
	cout << "|------|-----------|\n";
	if (n == NULL)
	{
		cout << "Danh Sach Dang Trong!" << endl;
	}
	else
	{
		while (n != NULL)
		{
			cout << "|" << n->data.mabang;
			switch (n->data.mabang.length())
			{
			case 0:
				cout << setw(7);
				break;
			case 1:
				cout << setw(6);
				break;
			case 2:
				cout << setw(5);
				break;
			case 3:
				cout << setw(4);
				break;
			case 4:
				cout << setw(3);
				break;
			case 5:
				cout << setw(2);
				break;
			case 6:
				cout << setw(1);
				break;
			default:
				break;
			}
			cout << "|" << n->data.tenBangCap;
			switch (n->data.tenBangCap.length())
			{
			case 0:
				cout << setw(12);
				break;
			case 1:
				cout << setw(11);
				break;
			case 2:
				cout << setw(10);
				break;
			case 3:
				cout << setw(9);
				break;
			case 4:
				cout << setw(8);
				break;
			case 5:
				cout << setw(7);
				break;
			case 6:
				cout << setw(6);
				break;
			case 7:
				cout << setw(5);
				break;
			case 8:
				cout << setw(4);
				break;
			case 9:
				cout << setw(3);
				break;
			case 10:
				cout << setw(2);
				break;
			case 11:
				cout << setw(1);
				break;
			default:
				break;
			}
			cout << "|" << endl;
			n = n->link;
		}
	}
}

void subMenuQLBC()
{
	cout << "===============================================" << endl;
	cout << "================QUAN LY BANG CAP===============" << endl;
	cout << "|0. Thoat                                     |" << "\n";
	cout << "|1. Xuat Bang Cap                             |" << "\n";
	cout << "|2. Them Bang Cap                             |" << "\n";
	cout << "|3. Xoa Bang Cap                              |" << "\n";
	cout << "===============================================" << endl;
}

void themBC(NodeBangCap*& dsbc, NodeBangCap* n)
{
	if (dsbc == NULL)
	{
		dsbc = n;
	}
	else
	{
		n->link = dsbc;
		dsbc = n;
	}
}
void xuatDSBangCap(NodeBangCap* dsbc)
{
	cout << "--------------------\n";
	cout << "|" << "Ma BC" << setw(2) << "|" << "Ten BC" << setw(6) << "|" << endl;
	cout << "|------|-----------|\n";
	if (dsbc == NULL)
	{
		cout << "Danh sach trong!" << endl;
	}
	else
	{
		NodeBangCap* n = dsbc;
		while (n != NULL)
		{
			cout << "|" << n->data.mabang;
			switch (n->data.mabang.length())
			{
			case 0:
				cout << setw(7);
				break;
			case 1:
				cout << setw(6);
				break;
			case 2:
				cout << setw(5);
				break;
			case 3:
				cout << setw(4);
				break;
			case 4:
				cout << setw(3);
				break;
			case 5:
				cout << setw(2);
				break;
			case 6:
				cout << setw(1);
				break;
			default:
				break;
			}
			cout << "|" << n->data.tenBangCap;
			switch (n->data.tenBangCap.length())
			{
			case 0:
				cout << setw(12);
				break;
			case 1:
				cout << setw(11);
				break;
			case 2:
				cout << setw(10);
				break;
			case 3:
				cout << setw(9);
				break;
			case 4:
				cout << setw(8);
				break;
			case 5:
				cout << setw(7);
				break;
			case 6:
				cout << setw(6);
				break;
			case 7:
				cout << setw(5);
				break;
			case 8:
				cout << setw(4);
				break;
			case 9:
				cout << setw(3);
				break;
			case 10:
				cout << setw(2);
				break;
			case 11:
				cout << setw(1);
				break;
			default:
				break;
			}
			cout << "|" << endl;
			n = n->link;
		}
	}
}

bool checkNhanVienSoHuuBangCap(NodeNhanVien* dsnv, string mabang)
{
	NodeNhanVien* head = dsnv;
	while (head != NULL)
	{
		NodeBangCap* bc = head->listBC;
		while (bc != NULL)
		{
			if (bc->data.mabang == mabang)
			{
				return true;
			}
			bc = bc->link;
		}
		head = head->link;
	}
	return false;
}

void xoaBangCap(NodeBangCap*& dsbc, NodeNhanVien* dsnv)
{
	int k;
	string mabang;
	do
	{
		cout << "===============================================" << endl;
		cout << "====================BANG CAP===================" << endl;
		cout << "|1. IELTS(IS)									" << "\n";
		cout << "|2. TOEIC(TC)									" << "\n";
		cout << "|3. TOFFEL(TF)									" << "\n";
		cout << "|4. OTHER...								    " << "\n";
		cout << "===============================================" << endl;
		cout << "Nhap lua chon: ";
		cin >> k;
		switch (k)
		{
		case 1:
			mabang = "IS";
			break;
		case 2:
			mabang = "TC";
			break;
		case 3:
			mabang = "TF";
			break;
		case 4:
			cin.ignore();
			cout << "Nhap ma bang: ";
			getline(cin, mabang);
			for (int i = 0; i < mabang.length(); i++)
			{
				if (mabang[i] >= 'a' && mabang[i] <= 'z')
				{
					mabang[i] -= 32;
				}
			}
			break;
		default:
			break;
		}
		if (checkNhanVienSoHuuBangCap(dsnv, mabang))
		{
			cout << "Bang cap nay dang co nhan vien so huu khong the xoa!" << endl;
		}
		else
		{
			NodeBangCap* head = dsbc;
			while (head != NULL)
			{
				if (head->data.mabang == mabang)
				{
					break;
				}
				head = head->link;
			}
			if (head == NULL)
			{
				cout << "Khong tim thay bang cap can xoa!" << endl;
			}
			else
			{
				if (head == dsbc)
				{
					xoaDau(dsbc);
					cout << "Xoa bang cap thanh cong!" << endl;
				}
				else if (head->link == NULL)
				{
					xoaCuoi(dsbc);
					cout << "Xoa bang cap thanh cong!" << endl;
				}
				else
				{
					NodeBangCap* q = dsbc;
					while (q->link != NULL)
					{
						if (q->link == head)
						{
							break;
						}
						q = q->link;
					}
					q->link = head->link;
					head->link = NULL;
					delete head;
					cout << "Xoa bang cap thanh cong!" << endl;
				}
			}
		}
		char check;
		cout << "Ban co muon xoa tiep khong(y/n): ";
		cin >> check;
		if (check == 'n' || check == 'N')
		{
			break;
		}
	} while (k != 0);
}
void QuanLyBangCap(NodeNhanVien* dsnv, NodeBangCap*& dsbc)
{
	xuatDSBangCap(dsbc, dsnv);
	int k;
	NodeBangCap* bc = NULL;
	BangCap bangcap;
	do {
		subMenuQLBC();
		cout << "Nhap lua chon: ";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 0:
			return;
		case 1:
			xuatDSBangCap(dsbc);
			break;
		case 2:
			nhapBangCap(bangcap);
			bc = new NodeBangCap();
			bc->data.mabang = bangcap.mabang;
			bc->data.tenBangCap = bangcap.tenBangCap;
			bc->link = NULL;
			if (checkBC(dsbc, bc->data.mabang) == NULL)
			{
				themBC(dsbc, bc);
				cout << "Them bang cap thanh cong!" << endl;
			}
			else
			{
				cout << "Da ton tai bang cap nay!" << endl;
				delete bc;
			}
			break;
		case 3:
			xoaBangCap(dsbc, dsnv);
			break;
		default:
			cout << "Nhap lai lua chon\n";
			break;
		}
	} while (k != 0);
	if (writeFile("danhSachBangCap.txt", dsbc))
	{
		return;
	}
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
NodeNhanVien* CreateNode(NodeNhanVien* dsnv)
{
	NodeNhanVien* nv = new NodeNhanVien;
	nhapUser(dsnv, nv->user);

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
			nv->demBC++;
		}
	}
	return nv;
}

void subMenuQLNV()
{
	cout << "===============================================" << endl;
	cout << "===============QUAN LY NHAN VIEN===============" << endl;
	cout << "|0. Thoat                                     |" << "\n";
	cout << "|1. Them Nhan Vien                            |" << "\n";
	cout << "|2. Xuat Danh Sach Nhan Vien                  |" << "\n";
	cout << "|3. Tim Kiem Thong Tin Nhan Vien              |" << "\n";
	cout << "===============================================" << endl;
}
void QuanLyNhanVien(NodeNhanVien*& dsnv)
{
	int k;
	do {
		system("cls");
		subMenuQLNV();
		cout << "Nhap lua chon: ";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 0:
			return;
		case 1:
			themDSNhanVien(dsnv);
			break;
		case 2:
			xuatDSNhanVien(dsnv);
			break;
		case 3:
			timKiem(dsnv);
			break;
		default:
			cout << "nhap lai\n ";
			break;
		}
		char check;
		cout << "Ban co muon quay lai quan ly nhan vien khong(y/n): ";
		cin >> check;
		if (check == 'n' || check == 'N')
			return;
	} while (k != 0);
}

void themNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* nv)
{
	if (dsnv == NULL)
	{
		dsnv = nv;
		nv->link = NULL;
	}
	else
	{
		nv->link = dsnv;
		dsnv = nv;
	}
}

void themDSNhanVien(NodeNhanVien*& dsnv)
{
	char k;
	do
	{
		NodeNhanVien* n = CreateNode(dsnv);
		themNhanVien(dsnv, n);
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
	cout << "---------------------------------------------------------------------------------------------------------\n";
	cout << "|" << "ID" << setw(5) << "|" << setw(10) << "Ho Ten" << setw(10) << "|" << setw(6) << "SDT" << setw(8) << "|" << setw(10) << "CCCD" << setw(8) << "|" << setw(10) << "Ngay Vao Lam" << setw(7) << "|" << setw(10) << "Chuc Vu" << setw(5) << "|" << setw(10) << "Gioi Tinh" << "|" << endl;
	cout << "|------|-------------------|-------------|-----------------|------------------|--------------|----------|\n";
	NodeNhanVien* p = dsnv;
	while (p != NULL)
	{
		xuatUser(p->user);
		p = p->link;
		cout << "|------|-------------------|-------------|-----------------|------------------|--------------|----------|\n";
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
		fscanf_s(fp, "%d", &tmp->demBC);
		for (int i = 0; i < tmp->demBC; i++)
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
	fclose(fp);
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
		fprintf_s(fp, "\t%d", p->demBC);
		NodeBangCap* tmp = p->listBC;
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
void xoaNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* n)
{
	if (dsnv == NULL)
	{
		cout << "danh sach trong!" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	NodeNhanVien* p = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id == n->user.id)
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
			while (p->link != NULL)
			{
				if (p->link == tmp)
				{
					break;
				}
				p = p->link;
			}
			p->link = tmp->link;
			tmp->link = NULL;
			delete tmp;
		}
	}
	cout << "Xoa nhan vien thanh cong!" << endl;
}

NodeNhanVien* timKiemTheoChucVu(NodeNhanVien* dsnv, string chucvu)
{
	NodeNhanVien* nv = NULL;
	
	NodeNhanVien* n = dsnv;
	while (n != NULL)
	{
		if (n->user.chucvu.find(chucvu) != string::npos)
		{
			NodeNhanVien* new_nv = new NodeNhanVien(*n);
			themNhanVien(nv, new_nv);
		}
		n = n->link;
	}
	return nv;
}

void xuatDanhSachChucVu(NodeNhanVien* dsnv)
{
	string chucvu;
	cin.ignore();
	cout << "Nhap chuc vu can tim: ";
	getline(cin, chucvu);
	chuanHoaChuoi(chucvu);
	NodeNhanVien* ds = timKiemTheoChucVu(dsnv, chucvu);
	NodeNhanVien* n = ds;
	if (n == NULL)
	{
		cout << "Khong tim thay nhan vien nao!" << endl;
	}
	else
	{
		while (n != NULL)
		{
			xuatNhanVien(n);
			n = n->link;
		}
	}
}

void chuanHoaChuoi(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
			}
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.replace(i, 1, "");
		}
	}
}
void timKiemTheoMaBang(NodeNhanVien* dsnv)
{
	int k;
	do
	{
		system("cls");
		cout << "===============================================" << endl;
		cout << "====================BANG CAP===================" << endl;
		cout << "|0. Thoat								        " << "\n";
		cout << "|1. IELTS(IS)									" << "\n";
		cout << "|2. TOEIC(TC)									" << "\n";
		cout << "|3. TOFFEL(TF)									" << "\n";
		cout << "|4. OTHER...								    " << "\n";
		cout << "===============================================" << endl;
		cout << "Nhap lua chon: ";
		cin >> k;
		string maBang;
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
				if (k == 1)
				{
					if (tmp->data.mabang == "IS")
					{
						xuatNhanVien(n);
						flag = true;
					}
					tmp = tmp->link;
				}
				else if (k == 2)
				{
					if (tmp->data.mabang == "TC")
					{
						xuatNhanVien(n);
						flag = true;
					}
					tmp = tmp->link;
				}
				else if (k == 3)
				{
					if (tmp->data.mabang == "TF")
					{
						xuatNhanVien(n);
						flag = true;
					}
					tmp = tmp->link;
				}
				else if (k == 4)
				{
					cin.ignore();
					cout << "Nhap ma bang can tim: ";
					getline(cin, maBang);
					chuanHoaChuoi(maBang);
					NodeNhanVien* nv = n;
					while (nv != NULL)
					{
						NodeBangCap* tmp1 = nv->listBC;
						while (tmp1 != NULL)
						{
							if (tmp1->data.mabang.find(maBang) != string::npos)
							{
								xuatNhanVien(nv);
								flag = true;
							}
							tmp1 = tmp1->link;
						}
						nv = nv->link;
					}
					return;
				}

			}
			n = n->link;
		}
		if (!flag)
		{
			cout << "Khong Tim Thay Nhan Vien Nao!" << endl;
		}
		char check;
		cout << "Ban co muon tiep tuc tim kiem khong(y/n): ";
		cin >> check;
		if(check == 'n' || check == 'N')
		{
			break;
		}
	} while (k != 0);
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

void suaThongTinNhanVien(NodeNhanVien*& dsnv, NodeNhanVien* n)
{
	if (dsnv == NULL)
	{
		cout << "danh sach trong!" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id == n->user.id)
		{
			break;
		}
		tmp = tmp->link;
	}

	if (tmp == NULL)
	{
		cout << "Khong tim thay id can sua!" << endl;
		return;
	}
	else
	{
		int k;
		int gioitinh;
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
				getline(cin, tmp->user.hoten);
				chuanHoaChuoi(tmp->user.hoten);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 2://sua sdt
				do
				{
					cout << "Nhap sdt: ";
					getline(cin, tmp->user.sdt);

					if (!checkNumeric(tmp->user.sdt) || tmp->user.sdt.length() < 10 || tmp->user.sdt.length() > 11)
					{
						cout << "Sdt khong hop le xin moi nhap lai!" << endl;
					}
					else if (checkSDT(dsnv, tmp->user.sdt) != NULL)
					{
						cout << "Sdt da ton tai!" << endl;
					}
				} while (!checkNumeric(tmp->user.sdt) || tmp->user.sdt.length() < 10 || tmp->user.sdt.length() > 11 || checkSDT(dsnv, tmp->user.sdt));
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 3://sua cccd
				do
				{
					cout << "Nhap CCCD: ";
					getline(cin, tmp->user.cccd);
					if (!checkNumeric(tmp->user.cccd) || tmp->user.cccd.length() < 12 || tmp->user.cccd.length() > 12)
					{
						cout << "CCCD khong hop le xin moi nhap lai!" << endl;
					}
					else if (checkCCCD(dsnv, tmp->user.cccd) != NULL)
					{
						cout << "Cccd da ton tai!" << endl;
					}
				} while (!checkNumeric(tmp->user.cccd) || tmp->user.cccd.length() < 12 || tmp->user.cccd.length() > 12 || checkCCCD(dsnv, tmp->user.cccd) != NULL);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 4://sua ngay vao lam
				nhapDate(tmp->user.ngayVaoLam);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 5://sua chuc vu
				cout << "Nhap chuc vu: ";
				getline(cin, tmp->user.chucvu);
				chuanHoaChuoi(tmp->user.chucvu);
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 6://sua gioi tinh
				do
				{
					cout << "Nhap gioi tinh(1.nam/0.nu): ";
					cin >> gioitinh;
				} while (gioitinh < 0 || gioitinh > 1);
				tmp->user.gioitinh = gioitinh;
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
	cout << "===============MENU TIM KIEM NHAN VIEN================" << endl;
	cout << "|0. Thoat                                            |" << endl;
	cout << "|1. Tim kiem theo ID                                 |" << endl;
	cout << "|2. Tim kiem theo chuc vu                            |" << endl;
	cout << "|3. Tim kiem theo ma bang                            |" << endl;
	cout << "======================================================" << endl;
}

void timKiem(NodeNhanVien*& dsnv)
{
	NodeNhanVien* id = NULL;
	NodeNhanVien* dem = NULL;
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
			dem = id;
			if (dem != NULL)
			{
				while (dem != NULL)
				{
					xuatNhanVien(dem);
					dem = dem->link;
				}
				if(demSoLuongNhanVien(id) == 1)
					toHopXoaSuaThemBC(dsnv, id);
				else
				{
					char k;
					cout << "Ban co muon chinh sua nhan vien khong(y/n): ";
					cin >> k;
					if (k == 'n' || k == 'N')
						break;
					cout << "Ban can nhap chinh xac id nhan vien can chinh sua!" << endl;
					NodeNhanVien tmp;
					cout << "Nhap id: ";
					cin >> tmp.user.id;
					for (int i = 0; i < tmp.user.id.length(); i++)
					{
						if (tmp.user.id[i] >= 'a' && tmp.user.id[i] <= 'z')
							tmp.user.id[i] = tmp.user.id[i] - 32;
					}
					toHopXoaSuaThemBC(dsnv, &tmp);
				}
			}
			else
			{
				cout << "Khong tim thay nhan vien!" << endl;
			}
			break;
		case 2:
			xuatDanhSachChucVu(dsnv);
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
	cout << "|2. Xoa Bang Cap                |" << endl;
	cout << "|3. Xoa Nhan Vien               |" << endl;
	cout << "|4. Sua Thong Tin Nhan Vien     |" << endl;
	cout << "=================================" << endl;
}
void toHopXoaSuaThemBC(NodeNhanVien*& dsnv, NodeNhanVien* n)
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
			themBC(dsnv, n);
			break;
		case 2:
			xoaBangCap(dsnv, n);
			break;
		case 3:
			xoaNhanVien(dsnv, n);
			return;
		case 4:
			suaThongTinNhanVien(dsnv, n);
			break;
		default:
			cout << "nhap lai\n ";
			break;
		}
	} while (k != 0);
}

void themBC(NodeNhanVien*& dsnv, NodeNhanVien* id)
{
	if (dsnv == NULL)
	{
		cout << "Danh Sach Trong!" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id == id->user.id)
		{
			break;
		}
		tmp = tmp->link;
	}

	if (tmp == NULL)
	{
		cout << "Khong tim thay id can them!" << endl;
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
		if (checkBC(tmp->listBC, n->data.mabang) != NULL)
		{
			cout << "Ma bang cap da ton tai!" << endl;
		}
		else
		{
			n->link = tmp->listBC;
			tmp->listBC = n;
			dsnv->demBC++;
			cout << "Them thanh cong!" << endl;
		}
	}
}

void xoaDau(NodeBangCap*& bc)
{
	if (bc == NULL)
	{
		return;
	}
	NodeBangCap* tmp = bc;
	bc = bc->link;
	tmp->link = NULL;
	delete tmp;
}
void xoaCuoi(NodeBangCap*& bc)
{
	if (bc == NULL)
	{
		return;
	}
	NodeBangCap* tmp = bc;
	while (tmp->link->link != NULL)
	{
		tmp = tmp->link;
	}
	NodeBangCap* p = tmp->link;
	tmp->link = NULL;
	delete p;
}
void xoaBangCap(NodeNhanVien*& dsnv, NodeNhanVien* n)
{
	if (dsnv == NULL)
	{
		cout << "Danh Sach Trong!" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id == n->user.id)
		{
			break;
		}
		tmp = tmp->link;
	}

	if (tmp == NULL)
	{
		cout << "Khong tim thay nhan vien can xoa!" << endl;
		return;
	}
	else
	{
		int k;
		string maBang;
		do
		{
			cout << "===============================================" << endl;
			cout << "=================MA BANG CAP===================" << endl;
			cout << "|0. Thoat                                      " << endl;
			cout << "|1. IS									        " << "\n";
			cout << "|2. TC									        " << "\n";
			cout << "|3. TF									        " << "\n";
			cout << "|4. OTHER...								    " << "\n";
			cout << "===============================================" << endl;
			cout << "Nhap lua chon: ";
			cin >> k;
			switch (k)
			{
			case 0:
				break;
			case 1:
				maBang = "IS";
				break;
			case 2:
				maBang = "TC";
				break;
			case 3:
				maBang = "TF";
				break;
			case 4:
				cin.ignore();
				cout << "Nhap ma bang can xoa: ";
				getline(cin, maBang);
				for (int i = 0; i < maBang.length(); i++)
				{
					if (maBang[i] == 'a' && maBang[i] == 'z')
					{
						maBang[i] -= 32;
					}
				}
				break;
			default:
				cout << "Nhap sai moi nhap lai!" << endl;
				break;
			}
			NodeBangCap* p = tmp->listBC;
			NodeBangCap* q = tmp->listBC;
			while (p != NULL)
			{
				if (p->data.mabang == maBang)
				{
					break;
				}
				p = p->link;
			}
			if (p == NULL)
			{
				cout << "Khong tim thay ma bang can xoa!" << endl;
				return;
			}
			else
			{
				if (p == tmp->listBC)
				{
					xoaDau(tmp->listBC);
				}
				else if (p->link == NULL)
				{
					xoaCuoi(tmp->listBC);
				}
				else
				{
					while (q->link != NULL)
					{
						if (q->link == p)
						{
							break;
						}
						q = q->link;
					}
					q->link = p->link;
					p->link = NULL;
					delete p;
				}
				tmp->demBC--;
				cout << "Xoa bang cap thanh cong!" << endl;
				char check;
				cout << "Ban co muon xoa tiep khong(y/n): ";
				cin >> check;
				if (check == 'n' || check == 'N')
				{
					break;
				}
			}
		} while (k != 0);
	}
}

int demSoLuongBangCap(NodeBangCap* dsbc)
{
	int i = 0;
	NodeBangCap* n = dsbc;
	while (n != NULL)
	{
		i++;
		n = n->link;
	}
	return i;
}
int readFile(const char* filename, NodeBangCap*& dsbc)
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
		NodeBangCap* tmp = new NodeBangCap();
		char buffer[51];
		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->data.mabang = buffer;

		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->data.tenBangCap = buffer;
		themBC(dsbc, tmp);
	}
	fclose(fp);
	return 1;
}
int writeFile(const char* filename, NodeBangCap* dsbc)
{
	FILE* fp;
	fopen_s(&fp, filename, "wt");
	if (fp == NULL)
	{
		return 0;
	}
	fprintf_s(fp, "%d", demSoLuongBangCap(dsbc));
	NodeBangCap* n = dsbc;
	while (n != NULL)
	{
		fprintf_s(fp, "\n");
		fprintf_s(fp, "%s", n->data.mabang.c_str());
		fprintf_s(fp, "\t%s", n->data.tenBangCap.c_str());
		n = n->link;
	}
	fclose(fp);
	return 1;
}
