#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct Node
{
	int data;
	Node* pnext;
};
typedef struct List
{
	Node* pHead;
};
void KhoiTaoList ( List &L)
{
	L.pHead = NULL;
}
Node *KhoiTaoNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat !!!" << endl;
		return NULL;
	}
	p->data = x;
	p->pnext = NULL;
	return p;
}
void ThemDau(List& L,Node *p)
{
	/*cout << "Nhap cai can them :";
	int x;
	cin >> x;
	Node* p = KhoiTaoNode(x);*/
	if (L.pHead == NULL)
	{
		L.pHead = p;
	}
	else
	{
		p->pnext = L.pHead;
		L.pHead = p;
	}
}
void ThemCuoi(List& L,Node *p)
{
	/*cout << "Nhap cai can them :";
	int x;
	cin >> x;
	Node* p = KhoiTaoNode(x);*/
	if (L.pHead == NULL)
	{
		L.pHead = p;
	}
	else
	{
		for (Node* k = L.pHead;k!=NULL; k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				break;
			}
		}
	}
}
void XuatDS(List L)
{
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		cout << k->data << " ";
	}
}
void ThemTruoc(List& L)
{
	cout << "Nhap cai can them :";
	int x;
	cin >> x;
	Node* p = KhoiTaoNode(x);
	cout << "Nhap node sau node can them :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
	Node* h = new Node;
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		if (k == L.pHead)
			continue;
		else if (k->data == q->data)
		{
			Node* g = KhoiTaoNode(p->data);
			g->pnext = k;
			h->pnext = g;
		}
		h = k;
	}
	if (L.pHead->data == q->data)
	{
		p->pnext = L.pHead;
		L.pHead = p;
	}
	XuatDS(L);
}
void ThemSau(List &L)
{
	cout << "Nhap cai can them :";
	int x;
	cin >> x;
	Node* p = KhoiTaoNode(x);
	cout << "Nhap node truoc node can them :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		if (k->data == q->data)
		{	
			if(k->pnext !=NULL)
			{
				Node* h = KhoiTaoNode(p->data);
				h->pnext = k->pnext;
				k->pnext = h;
			}
			else
			{
				k->pnext = p;
			}
		}
	}
	XuatDS(L);
}
int main()
{
	List L;
	KhoiTaoList(L);
	int n,x;
	cout << "Nhap so luong phan tu :";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 <<" :";
		cin >> x;
		Node* p = KhoiTaoNode(x);
		ThemCuoi(L,p);
	}
	cout << "Xuat Danh Sach " << endl;
	XuatDS(L);
	cout << endl;
	ThemTruoc(L);
	cout << endl;
	ThemSau(L);
	system("pause");
	return 0;
}