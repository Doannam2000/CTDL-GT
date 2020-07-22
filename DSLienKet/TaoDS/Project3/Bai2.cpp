#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct ThiSinh
{
	int SBD;
	string HoTen;
	int NamSinh;
	string KhoiThi;
};
struct Node
{
	ThiSinh data;
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
Node* KhoiTaoNode(ThiSinh x)
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
ThiSinh NhapDuLieu()
{
	ThiSinh x;
	cout << "Nhap so bao danh :";
	cin >> x.SBD;
	cout << "Nhap ho va ten :";
	cin.ignore();
	getline(cin, x.HoTen);
	cout << "Nhap nam sinh :";
	cin >> x.NamSinh;
	cout << "Nhap Khoi thi :";
	cin.ignore();
	getline(cin, x.KhoiThi);
	return x;
}
void ThemCuoi(List& L,Node *p)
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
void Hien()
{
	cout << setw(10) << "SBD";
	cout << setw(15) << "Ho Ten";
	cout << setw(9) << "Nam Sinh";
	cout << setw(6) << "Khoi" << endl;
}
void XuatDL(ThiSinh x)
{
	cout << setw(10) << x.SBD;
	cout << setw(15) << x.HoTen;
	cout << setw(9) << x.NamSinh;
	cout << setw(6) << x.KhoiThi << endl;
}
void Xuat(List L)
{
	Hien();
	for (Node* k = L.pHead; k != NULL; k = k->pNext)
	{
		XuatDL(k->data);
	}
}
void Xoa(List& L, int n)
{
	int vt, bp = 0;
	do
	{
		cout << "Nhap vi tri can xoa (1<=vt<=" << n << "):";
		cin >> vt;
	} while (vt <1 || vt >n);
	if (vt == 1)
	{
		Node* p = L.pHead;
		L.pHead = p->pNext;
		delete p;
	}
	else if (vt == n)
	{
		for (Node* k = L.pHead;; k = k->pNext)
		{
			if (k->pNext->pNext == NULL)
			{
				Node* p = k->pNext;
				k->pNext = NULL;
				delete p;
				break;
			}
		}
	}
	else
	{
		for (Node* k = L.pHead; k != NULL; k = k->pNext)
		{
			bp++;
			if (bp == vt - 1)
			{
				Node* p = k->pNext;
				k->pNext = p->pNext;
				delete p;
			}
		}
	}
	Xuat(L);
}
int main()
{
	int n;
	cout << "Nhap so luong thi sinh :";
	cin >> n;
	List L;
	KhoiTaoList(L);
	cout << "Nhap du lieu " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thi sinh " << i + 1 << endl;
		ThiSinh x = NhapDuLieu();
		Node* p = KhoiTaoNode(x);
		ThemCuoi(L,p);
	}
	Xuat(L);
	Xoa(L,n);
	system("pause");
	return 0;
}