#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct HocPhan
{
	string MaHP;
	string TenHP;
	int STC;
};
struct Node
{
	HocPhan data;
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
Node* KhoiTaoNode(HocPhan x)
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
HocPhan NhapDuLieu()
{
	HocPhan x;
	cout << "Nhap Ma hoc phan :";
	cin.ignore();
	getline(cin,x.MaHP);
	cout << "Nhap ten hoc phan :";
	fflush(stdin);
	getline(cin,x.TenHP);
	cout << "Nhap so tin chi :";
	cin >> x.STC;
	return x;
}

void ThemCuoi(List& L, Node *p)
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
void ThemViTri(List &L,int n)
{
	int vt, bp = 0;
	do
	{
		cout << "Nhap vi tri can them (1<=vt<="<<n + 1<<"):";
		cin >> vt;
	} while (vt <1 || vt >n + 1);
	cout << "Nhap hoc phan can them :"<<endl;
	HocPhan x = NhapDuLieu();
	Node* p = KhoiTaoNode(x);
	if (vt == 1)
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
	else if (vt == n + 1)
	{
		ThemCuoi(L,p);
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
	cout << setw(15) << "MaHP";
	cout << setw(15) << "TenHp";
	cout << setw(5) << "STC" << endl;
}
void XuatDL(HocPhan x)
{
	cout << setw(15) << x.MaHP;
	cout << setw(15) << x.TenHP;
	cout << setw(5) << x.STC << endl;
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
	cout << "Nhap so luong hoc phan :";
	cin >> n;
	List L;
	KhoiTaoList(L);
	cout << "Nhap du lieu " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap hoc phan " << i + 1 << endl;
		HocPhan x = NhapDuLieu();
		Node* p = KhoiTaoNode(x);
		ThemCuoi(L,p);
	}
	Xuat(L);
	ThemViTri(L,n);
	Xuat(L);
	system("pause");
	return 0;
}