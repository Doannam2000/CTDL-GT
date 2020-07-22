#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;


struct CanBo
{
	char MCB[8];
	char TenCB[20];
	int HSL;
};
typedef struct CanBo CB;
struct node
{
	CB data;
	struct node* pnext;
};
typedef struct node NODE;
struct List
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct List LIST;
void KhoiTaoList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
};
NODE* KhoiTaoNode(CB x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat !!!" << endl;
		return NULL;
	}
	p->data = x;
	p->pnext = NULL;
}
void ThemVaoCuoi(LIST& L, NODE* p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		L.pTail->pnext = p;
		L.pTail = p;
	}
}
void Nhap(CB& a)
{
	cout << "Nhap ma can bo: ";
	//cin.ignore();
	fflush(stdin);
	gets(a.MCB);
	cout << "Nhap ten can bo: ";
	fflush(stdin);
	gets(a.TenCB);
	cout << "Nhap he so luong: ";
	cin >> a.HSL;
}
void Xuat(CB a)
{
	cout << right << setw(8) << a.MCB;
	cout << right << setw(20) << a.TenCB;
	cout << right << setw(5) << a.HSL << endl;
}
void XuatDanhSach(LIST L)
{
	cout << left << setw(4) << "STT";
	cout << right << setw(8) << "Ma Can Bo";
	cout << right << setw(20) << "Ten";
	cout << right << setw(5) << "HSL" << endl;
	int k = 1;
	for (NODE* i = L.pHead; i != NULL; i = i->pnext)
	{
		cout << left << setw(4) << k;
		k++;
		Xuat(i->data);
	}
}
void Chen(LIST &L)
{
	CB x;
	cout << "\nNhap thong tin can bo can chen "<<endl;
	Nhap(x);
	NODE* p = KhoiTaoNode(x);
	int i = 0;
	for (NODE* k = L.pHead; k != NULL; k = k->pnext)
	{
		i++;
		if (i == 3)
		{
			NODE* g = k->pnext; 
			p->pnext = g;
			k->pnext = p;
			break;
		}
	}
}
void Xoa(LIST& L)
{
	int d = 0;
	if (strcmp(L.pHead->data.MCB, "123") == 0)
	{
		NODE* p = L.pHead; 
		L.pHead = L.pHead->pnext;
		delete p;
		d = 1;
	}
	if (strcmp(L.pTail->data.MCB, "123") == 0)
	{
		d = 1;
		for (NODE* k = L.pHead; k != NULL; k = k->pnext)
		{
			if (k->pnext == L.pTail)
			{
				delete L.pTail;
				k->pnext = NULL;
				L.pTail = k;
			}
		}
	}
	NODE* g = new NODE;
	for (NODE* k = L.pHead; k != NULL; k = k->pnext)
	{
		if (strcmp(k->data.MCB,"123")==0)
		{
			g->pnext = k->pnext; 
			delete k;
			d = 1;
		}
		g = k;
	}
	if (d == 0)
		cout << "Khong co can bo nao co ma 123 !!!" << endl;
	else
	{
		cout << "Danh sach sau khi xoa :" << endl;
		XuatDanhSach(L);
	}
}
void SapXep(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pnext)
	{
		for (NODE* h = k->pnext; h != NULL; h = h->pnext)
		{
			if (k->data.HSL > h->data.HSL)
			{
				CB a = k->data;
				k->data = h->data;
				h->data = a;
			}
		}
		
	}
	cout << "Danh sach sau khi sap xep la :" << endl;
	XuatDanhSach(l);
}
int main()
{
	LIST l;
	KhoiTaoList(l);
	cout<<"Ho Ten SV: Doan Duy Nam \n Lop : CNTT3 \n MSV : 2018602283 \n Em nop bai a !"<<endl;
	for (int i = 1; i <= 5; i++)
	{
		CB x;
		cout << "\nNhap thong tin can bo "<<i<<endl;
		Nhap(x);
		NODE* p = KhoiTaoNode(x);
		ThemVaoCuoi(l, p);
	}
	XuatDanhSach(l);
	Chen(l);
	cout << "Danh sach sau khi chen :"<<endl;
	XuatDanhSach(l);
	Xoa(l);
	SapXep(l);
	system("pause");
	return 0;
}
