#include "ThuVien.h"

NodeNhanVien* CreateNode()
{
	NodeNhanVien *nv = new NodeNhanVien;
	nv->user.nhapUser();
	
	while (true)
	{
		char k;
		cout << "Ban co muon them bang cap cua minh khong(y/n)";
		cin >> k;
		if (k == 'n' || k == 'N')
			break;
		NodeBangCap* bc = new NodeBangCap;
		bc->data.nhapBangCap();
		bc->link = nv->listBC;
		nv->listBC = bc;
		nv->listBC->i++;
	}
	return nv;
}

void xuatNhanVien(NodeNhanVien* dsnv)
{
	dsnv->user.xuatUser();
	if (dsnv->listBC == NULL)
	{
		cout << "Khong co bang cap";
	}
	while(dsnv->listBC != NULL)
	{
		dsnv->listBC->data.xuatBangCap();
		dsnv->listBC = dsnv->listBC->link;
	}

}