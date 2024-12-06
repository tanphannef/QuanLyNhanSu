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
					cout << "\033[31mNhap nam khong chinh xac vui long nhap lai nam!\033[0m" << endl;
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
					cout << "\033[31mNhap thang khong chinh xac vui long nhap lai thang!\033[0m" << endl;
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
						cout << "\033[31mNgap ngay khong chinh xac vui long nhap lai ngay!\033[0m" << endl;
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
						cout << "\033[31mNgap ngay khong chinh xac vui long nhap lai ngay!\033[0m" << endl;
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
							cout << "\033[31mNgap ngay khong chinh xac vui long nhap lai ngay!\033[0m" << endl;
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
							cout << "\033[31mNgap ngay khong chinh xac vui long nhap lai ngay!\033[0m" << endl;
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
		cout << "\033[31mBan co muon luu ngay nay khong(y/n): \033[0m";
		cin >> check;
		if (check == 'y' || check == 'Y')
			break;
		else if (check == 'n' || check == 'N')
			cin.ignore();

	}
}

int nhapSoNguyen()
{
	int n;
	while (true)
	{
		cout << "Nhap lua chon: ";
		cin >> n;

		// Kiểm tra nếu `cin` ở trạng thái lỗi (do nhập sai định dạng)
		if (cin.fail()) {
			// Xóa trạng thái lỗi của `cin`
			cin.clear();
			// Bỏ qua các ký tự trong dòng cho đến khi gặp ký tự xuống dòng
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\033[31mNhap sai dinh dang! Moi nhap lai.\033[0m" << endl;
		}
		else
		{
			// Nếu không có lỗi, thoát khỏi vòng lặp
			break;
		}
	}
	return n;
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
	string idToFind;
	cin.ignore();
	cout << "Nhap id vao: ";
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
		cout << "\033[31mKhong Co Bang Cap\033[0m" << endl;
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
			cout << "\033[31mNhap id khong chinh xac vui long nhap lai!\033[0m" << endl;
		}
		else if (id[1] != 'v' && id[1] != 'V')
		{
			cout << "\033[31mNhap id khong chinh xac vui long nhap lai!\033[0m" << endl;
		}
		else if (!checkNumeric(id.substr(2, id.length())))
		{
			cout<<"\033[31mNhap id khong chinh xac vui long nhap lai!\033[0m" << endl;
		}
		else if (id.length() < 5 || id.length() > 5)
		{
			cout << "\033[31mDo dai phai la 5 ky tu!\033[0m" << endl;
		}
		else if (checkID(dsnv, id) != NULL)
		{
			cout << "\033[31mId Da Ton Tai!\033[0m" << endl;
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
			cout << "\033[31mSdt khong hop le xin moi nhap lai!\033[0m" << endl;
		}
		else if (checkSDT(dsnv, user.sdt) != NULL)
		{
			cout << "\033[31mSdt da ton tai!\033[0m" << endl;
		}
	} while (!checkNumeric(user.sdt) || user.sdt.length() < 10 || user.sdt.length() > 11 || checkSDT(dsnv, user.sdt) != NULL);
	//Kiem tra dieu kien danh cho cccd
	do
	{
		cout << "Nhap CCCD: ";
		getline(cin, user.cccd);
		if (!checkNumeric(user.cccd) || user.cccd.length() < 12 || user.cccd.length() > 12)
		{
			cout << "\033[31mCCCD khong hop le xin moi nhap lai!\033[0m" << endl;
		}
		else if (checkCCCD(dsnv, user.cccd) != NULL)
		{
			cout << "\033[31mCccd da ton tai!\033[0m" << endl;
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
	cout << "===============================================" << endl;
	cout << "====================BANG CAP===================" << endl;
	cout << "|1. IELTS(IS)									" << "\n";
	cout << "|2. TOEIC(TC)									" << "\n";
	cout << "|3. TOFFEL(TF)									" << "\n";
	cout << "|4. OTHER...								    " << "\n";
	cout << "===============================================" << endl;
	k = nhapSoNguyen();
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
			if (bc.mabang[i] >= 'a' && bc.mabang[i] <= 'z')
			{
				bc.mabang[i] -= 32;
			}
		}
		cout << "Nhap ten bang cap: ";
		getline(cin, bc.tenBangCap);
		chuanHoaChuoi(bc.tenBangCap);
		return;
	default:
		cout << "\033[31mBan da nhap sai!!!\033[0m\n";
		break;
	}
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
		cout << "\033[31mDanh Sach Dang Trong!\033[0m" << endl;
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
		cout << "\033[31mDanh sach trong!\033[0m" << endl;
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
			if (bc->data.mabang.find(mabang) != string::npos)
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
		k = nhapSoNguyen();
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
			cout << "\033[31mBan da nhap sai lua chon!\033[0m"<<endl;
			return;
		}
		if (checkNhanVienSoHuuBangCap(dsnv, mabang))
		{
			cout << "\033[31mBang cap nay dang co nhan vien so huu khong the xoa!\033[0m" << endl;
		}
		else
		{
			NodeBangCap* head = dsbc;
			while (head != NULL)
			{
				if (head->data.mabang.find(mabang) != string::npos)
				{
					break;
				}
				head = head->link;
			}
			if (head == NULL)
			{
				cout << "\033[31mKhong tim thay bang cap can xoa!\033[0m" << endl;
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
		k = nhapSoNguyen();
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
			}
			else
			{
				cout << "\033[31mDa ton tai bang cap nay!\033[0m" << endl;
				delete bc;
			}
			break;
		case 3:
			xoaBangCap(dsbc, dsnv);
			break;
		default:
			cout << "\033[31mNhap lai lua chon!!!\033[0m\n";
			break;
		}
	} while (k != 0);
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
			cout << "\033[31mMa bang cap da ton tai!\033[0m" << endl;
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
	cout << "|4. Sap Xep Nhan Vien                         |" << "\n";
	cout << "===============================================" << endl;
}
void QuanLyNhanVien(NodeNhanVien*& dsnv)
{
	int k;
	do {
		system("cls");
		subMenuQLNV();
		k = nhapSoNguyen();
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
		case 4:
			SapXep(dsnv);
			break;
		default:
			cout << "\033[31m Ban da nhap sai!!!\033[0m\n ";
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

	//Neu dem so luong nv bang 0 thi dung luon
	if (dem == 0) return 0;

	//cho duyen qua so luong nhan vien
	for (int i = 0; i < dem; i++)
	{
		NodeNhanVien* tmp = new NodeNhanVien();
		char buffer[52];


		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->user.id = buffer;

		int dodaiten;
		fscanf_s(fp, "%d", &dodaiten); // Đọc độ dài của họ tên
		fgetc(fp); // Loại bỏ ký tự xuống dòng sau số (để fgets hoạt động đúng)
		fgets(buffer, dodaiten + 1, fp); // Đọc chuỗi với độ dài được chỉ định (dodai)
		buffer[dodaiten] = '\0'; // Đảm bảo kết thúc chuỗi an toàn

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}
		tmp->user.hoten = buffer; // Gán chuỗi cho họ tên

		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->user.sdt = buffer;

		fscanf_s(fp, "%50s", buffer, (unsigned)_countof(buffer));
		buffer[50] = '\0';
		tmp->user.cccd = buffer;

		fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.day);
		fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.month);
		fscanf_s(fp, "%d", &tmp->user.ngayVaoLam.year);

		int dodaichucvu;
		fscanf_s(fp, "%d", &dodaichucvu); // Đọc độ dài của chuc vu
		fgetc(fp); // Loại bỏ ký tự xuống dòng sau số (để fgets hoạt động đúng)
		fgets(buffer, dodaichucvu + 1, fp); // Đọc chuỗi với độ dài được chỉ định (dodai)
		buffer[dodaichucvu] = '\0'; // Đảm bảo kết thúc chuỗi an toàn

		size_t lent = strlen(buffer);
		if (lent > 0 && buffer[lent - 1] == '\n') {
			buffer[lent - 1] = '\0';
		}
		tmp->user.chucvu = buffer; // Gán chuỗi cho chuc vu

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

			int dodaibangcap;
			fscanf_s(fp, "%d", &dodaibangcap); // Đọc độ dài của họ tên
			fgetc(fp); // Loại bỏ ký tự xuống dòng sau số (để fgets hoạt động đúng)
			fgets(buffer, dodaibangcap + 1, fp); // Đọc chuỗi với độ dài được chỉ định (dodai)
			buffer[dodaibangcap] = '\0'; // Đảm bảo kết thúc chuỗi an toàn

			size_t len = strlen(buffer);
			if (len > 0 && buffer[len - 1] == '\n') {
				buffer[len - 1] = '\0';
			}
			bc->data.tenBangCap = buffer; // Gán chuỗi cho họ tên

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
		fprintf_s(fp, "\n%d", static_cast<int>(p->user.hoten.length()));
		fprintf_s(fp, "\n%s", p->user.hoten.c_str());

		fprintf_s(fp, "\n%s", p->user.sdt.c_str());
		fprintf_s(fp, "\n%s", p->user.cccd.c_str());
		fprintf_s(fp, "\n%d", p->user.ngayVaoLam.day);
		fprintf_s(fp, "\n%d", p->user.ngayVaoLam.month);
		fprintf_s(fp, "\n%d", p->user.ngayVaoLam.year);

		fprintf_s(fp, "\n%d", static_cast<int>(p->user.chucvu.length()));
		fprintf_s(fp, "\n%s", p->user.chucvu.c_str());
		fprintf_s(fp, "\n%d", p->user.gioitinh);
		fprintf_s(fp, "\n%d", p->demBC);
		NodeBangCap* tmp = p->listBC;
		while (tmp != NULL)
		{
			fprintf_s(fp, "\n%s", tmp->data.mabang.c_str());
			fprintf_s(fp, "\n%d", static_cast<int>(tmp->data.tenBangCap.length()));
			fprintf_s(fp, "\n%s", tmp->data.tenBangCap.c_str());
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
		cout << "\033[31mDanh Sach Trong!\033[0m" << endl;
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
		cout << "\033[31mKhong tim thay id can xoa!\033[0m" << endl;
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
		string tmp = n->user.chucvu;
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			{
				tmp[i] += 32;
			}
		}
		if (tmp.find(chucvu) != string::npos)
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
	for (int i = 0; i < chucvu.length(); i++)
	{
		if (chucvu[i] >= 'A' && chucvu[i] <= 'Z')
		{
			chucvu[i] += 32;
		}
	}
	NodeNhanVien* ds = timKiemTheoChucVu(dsnv, chucvu);
	NodeNhanVien* n = ds;
	if (n == NULL)
	{
		cout << "\033[31mKhong tim thay nhan vien nao!\033[0m" << endl;
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
	//Xu ly khoang trang o dau
	while (str[0] == ' ')
	{
		str.replace(0, 1, "");
	}
	//Xu ly khoang trang o giua
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.replace(i+1, 1, "");
			i--;
		}
	}
	//Xu ly khoang trang o cuoi
	while (str[str.length() - 1] == ' ')
	{
		str.replace(str.length() - 1, 1, "");
	}

	//Bien tat ca thanh chuoi thuong
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}

	//Cho ki tu dau tien thanh chu hoa
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}

	//Cho ki tu sau khoang trang thanh chu hoa
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
		k = nhapSoNguyen();
		string maBang;
		bool flag = false;
		NodeNhanVien* n = dsnv;
		if (n == NULL)
		{
			cout << "\033[31mDanh sach nhan vien rong!\033[0m" << endl;
			return;
		}
		while (n != NULL)
		{
			NodeBangCap* tmp = n->listBC;

			while (tmp != NULL)
			{
				if (k == 0)
				{
					return;
				}
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
					for (int i = 0; i < maBang.length(); i++)
					{
						if (maBang[i] >= 'a' && maBang[i] <= 'z')
						{
							maBang[i] -= 32;
						}
					}
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
					if (!flag)
					{
						cout << "\033[31mKhong Tim Thay Nhan Vien Nao!\033[0m" << endl;
					}
					return;
				}
				else
				{
					cout << "\033[31mBan da nhap sai!!!\033[0m" << endl;
					return;
				}
			}
			n = n->link;
		}
		if (!flag)
		{
			cout << "\033[31mKhong Tim Thay Nhan Vien Nao!\033[0m" << endl;
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
		cout << "\033[31mDanh Sach Trong!\033[0m" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	NodeNhanVien* head = dsnv;
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
		cout << "\033[31mKhong tim thay id can sua!\033[0m" << endl;
		return;
	}
	else
	{
		int k;
		int gioitinh;
		string sdt;
		string cccd;
		do {
			system("cls");
			xuatNhanVien(tmp);
			subMenuSua();
			k = nhapSoNguyen();
			
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
					getline(cin, sdt);

					if (!checkNumeric(sdt) || sdt.length() < 10 || sdt.length() > 11)
					{
						cout << "\033[31mSdt khong hop le xin moi nhap lai!\033[0m" << endl;
					}
					else if (checkSDT(head, sdt) != NULL)
					{
						cout << "\033[31mSdt da ton tai!\033[0m" << endl;
					}
				} while (!checkNumeric(sdt) || sdt.length() < 10 || sdt.length() > 11 || checkSDT(dsnv, sdt) != NULL);
				tmp->user.sdt = sdt;
				cout << "Da cap nhat thanh cong!" << endl;
				break;
			case 3://sua cccd
				do
				{
					cout << "Nhap CCCD: ";
					getline(cin, cccd);
					if (!checkNumeric(cccd) || cccd.length() < 12 || cccd.length() > 12)
					{
						cout << "\033[31mCCCD khong hop le xin moi nhap lai!\033[0m" << endl;
					}
					else if (checkCCCD(dsnv, cccd) != NULL)
					{
						cout << "\033[31mCccd da ton tai!\033[0m" << endl;
					}
				} while (!checkNumeric(cccd) || cccd.length() < 12 ||cccd.length() > 12 || checkCCCD(dsnv,cccd) != NULL);
				tmp->user.cccd = cccd;
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
				cout << "\033[31mBan da nhap sai lua chon!\033[0m\n";
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
		k = nhapSoNguyen();
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
					NodeNhanVien* tmp = new NodeNhanVien();
					cout << "Nhap id: ";
					cin >> tmp->user.id;
					for (int i = 0; i < tmp->user.id.length(); i++)
					{
						if (tmp->user.id[i] >= 'a' && tmp->user.id[i] <= 'z')
							tmp->user.id[i] = tmp->user.id[i] - 32;
					}
					NodeNhanVien* tmp2 = id;
					while (tmp2 != NULL)
					{
						if (tmp2->user.id.find(tmp->user.id) != string::npos)
						{
							break;
						}
						tmp2 = tmp2->link;
					}
					if (tmp2 != NULL)
					{
						toHopXoaSuaThemBC(dsnv, tmp2);
					}
					else
					{
						cout << "\033[31mKhong tim thay nhan vien!\033[0m" << endl;
					}
				}
			}
			else
			{
				cout << "\033[31mKhong tim thay nhan vien!\033[0m" << endl;
			}
			break;
		case 2:
			xuatDanhSachChucVu(dsnv);
			break;
		case 3:
			timKiemTheoMaBang(dsnv);
			break;
		default:
			cout << "\033[31mBan da nhap sai!!!\033[0m\n";
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
		k = nhapSoNguyen();
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
			cout << "\033[31mBan da nhap sai!!!\033[0m\n ";
			break;
		}
	} while (k != 0);
}

void themBC(NodeNhanVien*& dsnv, NodeNhanVien* id)
{
	if (dsnv == NULL)
	{
		cout << "\033[31mDanh Sach Trong!\033[0m" << endl;
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
		cout << "\033[31mKhong tim thay id can them!\033[0m" << endl;
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
			cout << "\033[31mMa bang cap da ton tai!\033[0m" << endl;
			delete n;
		}
		else
		{
			n->link = tmp->listBC;
			tmp->listBC = n;
			tmp->demBC++;
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
		cout << "\033[31mDanh Sach Trong!\033[0m" << endl;
		return;
	}
	NodeNhanVien* tmp = dsnv;
	while (tmp != NULL)
	{
		if (tmp->user.id.find(n->user.id) != string::npos)
		{
			break;
		}
		tmp = tmp->link;
	}

	if (tmp == NULL)
	{
		cout << "\033[31mKhong tim thay nhan vien can xoa!\033[0m" << endl;
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
			cout << "|1. IELTS(IS)									" << "\n";
			cout << "|2. TOEIC(TC)									" << "\n";
			cout << "|3. TOFFEL(TF)									" << "\n";
			cout << "|4. OTHER...								    " << "\n";
			cout << "===============================================" << endl;
			k = nhapSoNguyen();
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
				cout << "\033[31mNhap sai lua chon!\033[0m" << endl;
				return;
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
				cout << "\033[31mKhong tim thay ma bang can xoa!\033[0m" << endl;
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

		int dodaibangcap;
		fscanf_s(fp, "%d", &dodaibangcap); // Đọc độ dài của họ tên
		fgetc(fp); // Loại bỏ ký tự xuống dòng sau số (để fgets hoạt động đúng)
		fgets(buffer, dodaibangcap + 1, fp); // Đọc chuỗi với độ dài được chỉ định (dodai)
		buffer[dodaibangcap] = '\0'; // Đảm bảo kết thúc chuỗi an toàn

		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}
		tmp->data.tenBangCap = buffer; // Gán chuỗi cho họ tên
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
		fprintf_s(fp, "\n%d", static_cast<int>(n->data.tenBangCap.length()));
		fprintf_s(fp, "\n%s", n->data.tenBangCap.c_str());
		n = n->link;
	}
	fclose(fp);
	return 1;
}

void demSoLuongNhanVienNamNu(NodeNhanVien* dsnv, int& nam, int& nu)
{
	NodeNhanVien* head = dsnv;
	while (head != NULL)
	{
		if (head->user.gioitinh == true)
		{
			nam++;
		}
		else
		{
			nu++;
		}
		head = head->link;
	}
}
void demSoLuongBangCapCuaMoiNhanVien(NodeNhanVien* dsnv)
{
	NodeNhanVien* n = dsnv;
	cout << "-------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << "ID" << setw(5) << "|" << setw(10) << "Ho Ten" << setw(10) << "|" << setw(6) << "SDT" << setw(8) << "|" << setw(10) << "CCCD" << setw(8) << "|" << setw(10) << "Ngay Vao Lam" << setw(7) << "|" << setw(10) << "Chuc Vu" << setw(5) << "|" << setw(10) << "Gioi Tinh" << "|" <<"SLBC"<<setw(6)<<"|" << endl;
	cout << "|------|-------------------|-------------|-----------------|------------------|--------------|----------|---------|\n";
	if (n == NULL)
	{
		cout << "Danh sach nhan vien dang trong!" << endl;
	}
	while (n != NULL)
	{
		cout << "|" << n->user.id << " " << "|" << n->user.hoten;
		switch (n->user.hoten.length())
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
		cout << "|" << "  " << n->user.sdt;
		switch (n->user.sdt.length())
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
		cout << "|" << "   " << n->user.cccd << "  " << "|";
		xuatDate(n->user.ngayVaoLam);
		cout << "|" << n->user.chucvu << " ";
		switch (n->user.chucvu.length())
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
		if (n->user.gioitinh)
		{
			cout << "NAM";
			cout << "      " << "|";
		}
		else
		{
			cout << "NU";
			cout << "       " << "|";
		}
		cout << n->demBC;
		switch (to_string(n->demBC).length())
		{	
		case 0:
			cout << setw(10);
			break;
		case 1:
			cout << setw(9);
			break;
		case 2:
			cout << setw(8);
			break;
		case 3:
			cout << setw(7);
			break;
		case 4:
			cout << setw(6);
			break;
		case 5:
			cout << setw(5);
			break;
		case 6:
			cout << setw(4);
			break;
		case 7:
			cout << setw(3);
			break;
		case 8:
			cout << setw(2);
			break;
		case 9:
			cout << setw(1);
			break;
		default:
			break;
		}
		cout << "|" << endl;
		n = n->link;
	}
}
int tinhSoNgayDaLamViec(int ngay, int thang, int nam)
{
	auto ngayHienTai = chrono::system_clock::now();
	time_t ngayHienTaiTimeT = chrono::system_clock::to_time_t(ngayHienTai);
	tm* tmNgayHienTai = localtime(&ngayHienTaiTimeT);

	// Chuyển đổi ngày vào làm việc thành đối tượng std::tm
	tm ngayVaoLam = {};
	ngayVaoLam.tm_mday = ngay;
	ngayVaoLam.tm_mon = thang - 1;  // tháng bắt đầu từ 0
	ngayVaoLam.tm_year = nam - 1900; // năm bắt đầu từ 1900

	// Tạo các đối tượng time_point từ std::tm để tính toán
	auto timePointNgayVaoLam = chrono::system_clock::from_time_t(mktime(&ngayVaoLam));

	// Tính số giờ giữa hai thời điểm và sau đó chuyển đổi sang ngày
	auto soGioLamViec = chrono::duration_cast<chrono::hours>(ngayHienTai - timePointNgayVaoLam).count();
	int soNgayLamViec = soGioLamViec / 24;
	return soNgayLamViec;
}
void xuatSoNgayDaLamViec(NodeNhanVien* dsnv)
{
	NodeNhanVien* n = dsnv;
	cout << "----------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << "ID" << setw(5) << "|" << setw(10) << "Ho Ten" << setw(10) << "|" << setw(6) << "SDT" << setw(8) << "|" << setw(10) << "CCCD" << setw(8) << "|" << setw(10) << "Ngay Vao Lam" << setw(7) << "|" << setw(10) << "Chuc Vu" << setw(5) << "|" << setw(10) << "Gioi Tinh" << "|" << "SoNgayDaLam" << setw(2) << "|" << endl;
	cout << "|------|-------------------|-------------|-----------------|------------------|--------------|----------|------------|\n";
	if (n == NULL)
	{
		cout << "\033[31mDanh sach nhan vien dang trong!\033[0m" << endl;
	}
	while (n != NULL)
	{
		int soNgayLamViec = tinhSoNgayDaLamViec(n->user.ngayVaoLam.day, n->user.ngayVaoLam.month, n->user.ngayVaoLam.year);
		cout << "|" << n->user.id << " " << "|" << n->user.hoten;
		switch (n->user.hoten.length())
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
		cout << "|" << "  " << n->user.sdt;
		switch (n->user.sdt.length())
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
		cout << "|" << "   " << n->user.cccd << "  " << "|";
		xuatDate(n->user.ngayVaoLam);
		cout << "|" << n->user.chucvu << " ";
		switch (n->user.chucvu.length())
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
		if (n->user.gioitinh)
		{
			cout << "NAM";
			cout << "      " << "|";
		}
		else
		{
			cout << "NU";
			cout << "       " << "|";
		}
		cout << soNgayLamViec;
		switch (to_string(soNgayLamViec).length())
		{
		case 1:
			cout << setw(12);
			break;
		case 2:
			cout << setw(11);
			break;
		case 3:
			cout << setw(10);
			break;
		case 4:
			cout << setw(9);
			break;
		case 5:
			cout << setw(8);
			break;
		case 6:
			cout << setw(7);
			break;
		case 7:
			cout << setw(6);
			break;
		case 8:
			cout << setw(5);
			break;
		case 9:
			cout << setw(4);
			break;
		case 10:
			cout << setw(3);
			break;
		case 11:
			cout << setw(2);
			break;
		case 12:
			cout << setw(1);
			break;
		default:
			break;
		}
		cout << "|" << endl;
		n = n->link;
	}
}
void thongKe(NodeNhanVien* dsnv, NodeBangCap* dsbc)
{
	int k;
	int soLuongNhanVien = demSoLuongNhanVien(dsnv);
	int soLuongBangCap = demSoLuongBangCap(dsbc);
	int nam = 0;
	int nu = 0;
	demSoLuongNhanVienNamNu(dsnv, nam, nu);
	do
	{
		system("cls");
		cout << "======================THONG KE=======================" << endl;
		cout << "|0. Thoat                                           |" << endl;
		cout << "|So luong nhan vien dang quan ly la: "<<soLuongNhanVien<<"             |" << endl;
		cout << "|So luong bang cap dang quan ly la: "<<soLuongBangCap<<"               |" << endl;
		cout << "|So luong nhan vien nam la: "<<nam<<"                      | " << endl;
		cout << "|So luong nhan vien nu la: "<<nu<<"                        | " << endl;
		cout << "|1. Xem so luong bang cap cua moi nhan vien         |" << endl;
		cout << "|2. Xem so ngay da lam viec cua moi nhan vien       |" << endl;
		cout << "=====================================================" << endl;
		k = nhapSoNguyen();
		switch (k)
		{ 
		case 0:
			return;
		case 1:
			demSoLuongBangCapCuaMoiNhanVien(dsnv);
			break;
		case 2:
			xuatSoNgayDaLamViec(dsnv);
			break;
		default:
			cout << "\033[31mBan da nhap sai!!!\033[0m" << endl;
			break;
		}
		char check;
		cout << "Ban co muon tiep tuc xem thong ke khong(y/n): ";
		cin >> check;
		if (check == 'n' || check == 'N')
			break;
	} while (k != 0);
}

//Cac ham cai dat cua sap xep
void menuSapXep()
{
	cout << "===========================================" << endl;
	cout << "================MENU SAP XEP===============" << endl;
	cout << "|0. Thoat                                 |" << endl;
	cout << "|1. Sap Xep ID Nhan Vien Tang Dan         |" << endl;
	cout << "|2. Sap Xep ID Nhan Vien Giam Dan         |" << endl;
	cout << "|3. Sap Xep HoTen Nhan Vien Tang Dan      |" << endl;
	cout << "|4. Sap Xep HoTen Nhan Vien Giam Dan      |" << endl;
	cout << "|5. Sap Xep ChucVu Nhan Vien Tang Dan     |" << endl;
	cout << "|6. Sap Xep ChucVu Nhan Vien Giam Dan     |" << endl;
	cout << "===========================================" << endl;
}
void SapXep(NodeNhanVien*& dsnv)
{
	int k;
	do
	{
		system("cls");
		xuatDSNhanVien(dsnv);
		menuSapXep();
		k = nhapSoNguyen();
		switch (k)
		{
		case 0:
			break;
		case 1:
			sapXepIDTangDan(dsnv);
			break;
		case 2:
			sapXepIdGiamDan(dsnv);
			break;
		case 3:
			sapXepHoTenTangDan(dsnv);
			break;
		case 4:
			sapXepHoTenGiamDan(dsnv);
			break;
		case 5:
			sapXepChucVuTangDan(dsnv);
			break;
		case 6:
			sapXepChucVuGiamDan(dsnv);
			break;
		default:
			cout << "Ban da nhap sai lua chon!!!" << endl;
			break;
		}
	} while (k != 0);
}
void sapXepIDTangDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!" << endl;
		return;
	}

	bool check; // Biến kiểm tra xem có cần hoán đổi nữa không
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.id > head->link->user.id)
				{
					// Hoán đổi hai nút liền kề
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;

					if (prev == NULL)
					{
						dsnv = tmp; // Cập nhật đầu danh sách nếu nút đầu tiên thay đổi
					}
					else
					{
						prev->link = tmp;
					}

					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);
}
void sapXepIdGiamDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!" << endl;
		return;
	}

	bool check; // Biến kiểm tra xem có cần hoán đổi nữa không
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.id < head->link->user.id)
				{
					// Hoán đổi hai nút liền kề
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;

					if (prev == NULL)
					{
						dsnv = tmp; // Cập nhật đầu danh sách nếu nút đầu tiên thay đổi
					}
					else
					{
						prev->link = tmp;
					}

					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);
}
void sapXepHoTenTangDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!" << endl;
		return;
	}

	bool check; // Biến kiểm tra xem có cần hoán đổi nữa không
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.hoten > head->link->user.hoten)
				{
					// Hoán đổi hai nút liền kề
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;

					if (prev == NULL)
					{
						dsnv = tmp; // Cập nhật đầu danh sách nếu nút đầu tiên thay đổi
					}
					else
					{
						prev->link = tmp;
					}

					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);
}
void sapXepHoTenGiamDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!!" << endl;
		return;
	}
	bool check;
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.hoten < head->link->user.hoten)
				{
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;
					if (prev == NULL)
					{
						dsnv = tmp;
					}
					else
					{
						prev->link = tmp;
					}
					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);
}

void sapXepChucVuTangDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!!" << endl;
		return;
	}
	bool check;
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.chucvu > head->link->user.chucvu)
				{
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;
					if (prev == NULL)
					{
						dsnv = tmp;
					}
					else
					{
						prev->link = tmp;
					}
					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);

}

void sapXepChucVuGiamDan(NodeNhanVien*& dsnv)
{
	if (dsnv == NULL || dsnv->link == NULL)
	{
		cout << "Danh sach trong hoac chi co 1 phan tu khong can sap xep!!!" << endl;
		return;
	}
	bool check;
	do
	{
		check = false;
		NodeNhanVien* head = dsnv;
		NodeNhanVien* prev = NULL;

		while (head != NULL)
		{
			if (head->link != NULL)
			{
				if (head->user.chucvu < head->link->user.chucvu)
				{
					NodeNhanVien* tmp = head->link;
					head->link = tmp->link;
					tmp->link = head;
					if (prev == NULL)
					{
						dsnv = tmp;
					}
					else
					{
						prev->link = tmp;
					}
					check = true;
				}
			}
			prev = head;
			head = head->link;
		}
	} while (check);
}
