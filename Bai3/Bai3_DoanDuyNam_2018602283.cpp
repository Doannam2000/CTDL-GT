#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct CuonSach
{
	string MaSach;
	string TenSach;
	string TenTG;
	int NamSB;
};
struct Node
{
	CuonSach data;
	Node* pNext;
};
struct List
{
	Node* pHead;
};
void KhoiTaoList(List& L)
{
	L.pHead = NULL;
}
Node* KhoiTaoNode(CuonSach x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat !!!" << endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
CuonSach NhapDuLieu()
{
	CuonSach x;
	cout << "Nhap ma sach :";
	cin.ignore();
	getline(cin, x.MaSach);
	cout << "Nhap ten sach :";
	fflush(stdin);
	getline(cin, x.TenSach);
	cout << "Nhap ten tac gia :";
	fflush(stdin);
	getline(cin, x.TenTG);
	cout << "Nhap so nam xuat ban :";
	cin >> x.NamSB;
	return x;
}

void ThemCuoi(List& L, Node* p)
{

	if (L.pHead == NULL)
	{
		L.pHead = p;
	}
	else
	{
		for (Node* k = L.pHead;; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}
void ThemViTri(List& L, int n)
{
	int vt, bp = 0;
	do
	{
		cout << "Nhap vi tri can them (1<=vt<=" << n + 1 << "):";
		cin >> vt;
	} while (vt <1 || vt >n + 1);
	cout << "Nhap hoc phan can them :" << endl;
	CuonSach x = NhapDuLieu();
	Node* p = KhoiTaoNode(x);
	if (vt == 1)
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
	else if (vt == n + 1)
	{
		ThemCuoi(L, p);
	}
	else
	{
		for (Node* k = L.pHead; k != NULL; k = k->pNext)
		{
			bp++;
			if (bp == vt - 1)
			{
				p->pNext = k->pNext;
				k->pNext = p;
			}
		}
	}
}
void Hien()
{
	cout << setw(15) << "MaSach";
	cout << setw(15) << "TenSach";
	cout << setw(15) << " Ten TG ";
	cout << setw(6) << "NamSB" << endl;
}
void XuatDL(CuonSach x)
{
	cout << setw(15) << x.MaSach;
	cout << setw(15) << x.TenSach;
	cout << setw(15) << x.TenTG;
	cout << setw(6) << x.NamSB << endl;
}
void Xuat(List L)
{
	Hien();
	for (Node* k = L.pHead; k != NULL; k = k->pNext)
	{
		XuatDL(k->data);
	}
}
int main()
{
	int n;
	cout << "Nhap so luong sach :";
	cin >> n;
	List L;
	KhoiTaoList(L);
	cout << "Nhap du lieu " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap cuon sach so " << i + 1 << endl;
		CuonSach x = NhapDuLieu();
		Node* p = KhoiTaoNode(x);
		ThemCuoi(L, p);
	}
	Xuat(L);
	ThemViTri(L, n);
	Xuat(L);
	system("pause");
	return 0;
}
