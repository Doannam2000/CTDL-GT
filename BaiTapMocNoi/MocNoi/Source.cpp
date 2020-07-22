#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* pnext;
};
typedef struct List
{
	Node* pHead;
	Node* pTail;
};
void KhoiTaoList(List &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
Node* KhoiTaoNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat :";
		return NULL;
	}
	p->pnext = NULL;
	p->data = x;
	return p;
}
void ThemVaoDau(List &L,Node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = p;
	}
	else
	{
		p->pnext = L.pHead;
		L.pHead = p;
	}
}
void ThemVaoCuoi(List& L, Node* p)
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
void XuatDS(List L)
{
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		cout << k->data << " ";
	}
}
void ThemNode(List &L,int n)
{
	cout << "Nhap node : ";
	Node* p = new Node;
	int x,y,vt= 0;
	cin >> x;
	p = KhoiTaoNode(x);
	do
	{
		cout << "Nhap vi tri can them :";
		cin >> y;
		if (y<1 || y > n + 1)
			cout << "Vo ly" << endl;
	} while ( y<1 || y > n + 1);
	if (y == 1)
		ThemVaoDau(L, p);
	else if (y == n )
		ThemVaoCuoi(L, p);
	else
	{
		for (Node* k = L.pHead; k != NULL; k = k->pnext)
		{
			vt++;
			if (vt == y - 1)
			{
				p->pnext = k->pnext;
				k->pnext = p;
				break;
			}
		}
	}
	XuatDS(L);
}
void ThemSau(List &L)
{
	cout << "Nhap node : ";
	Node* p = new Node;
	int x,vt = 0;
	cin >> x;
	p = KhoiTaoNode(x);
	cout << "Nhap node truoc node can them :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
	
		for (Node* k = L.pHead; k != NULL; k = k->pnext)
		{
			if (k == L.pTail)
				break;
			else if (q->data == k->data)
			{
				Node* h = KhoiTaoNode(p -> data);
				h->pnext = k->pnext;
				k-> pnext = h;
				k = k->pnext;
			}
		}
		if (q->data == L.pTail->data)
		{
			ThemVaoCuoi(L, p);
		}
	XuatDS(L);
}
void ThemTruoc(List& L)
{
	cout << "Nhap node : ";
	Node* p = new Node;
	int x, vt = 0;
	cin >> x;
	p = KhoiTaoNode(x);
	cout << "Nhap node truoc node can them :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
		Node* g = new Node;
		for (Node* k = L.pHead; k != NULL; k = k->pnext)
		{
			if (k == L.pHead)
			{
				continue;
			}
			else if (q->data == k ->data)
			{
				Node* h = KhoiTaoNode(p->data);
				h->pnext = g->pnext;
				g->pnext = h;
			}
			g = k;
		}
		if (L.pHead->data == q->data)
		{
			ThemVaoDau(L, p);
		}
	XuatDS(L);
}
void XoaDau(List &L)
{
	if (L.pHead == NULL)
		return;
	Node* p = L.pHead;
	L.pHead = L.pHead->pnext;
	delete p;
	XuatDS(L);
}
void XoaCuoi(List& L)
{
	if (L.pHead == NULL)
		return;
	Node *p = L.pTail;
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		if (k->pnext == L.pTail)
		{
			k->pnext = NULL;
			L.pTail = k;
			delete p;
		}
	}
	XuatDS(L);
}
void XoaSau(List& L)
{
	int x,d = 0;
	cout << "Nhap node truoc node can Xoa :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
	if (L.pHead == L.pTail || L.pTail -> data == q ->data)
	{
		cout << "May khong thay vo li a tml kia =_=";
		return;
	}
	for (Node* k = L.pHead; k != NULL; k = k->pnext)
	{
		if (k->data == q->data)
		{
			Node* a = k -> pnext;
			k->pnext = a->pnext;
			delete a;
			d = 1;
		}
	}
	if (d == 0)
		cout << "Khong co"<<endl;
	XuatDS(L);
}
void XoaTruoc(List& L)
{
	int x, d = 0;
	cout << "Nhap node sau node can Xoa :";
	cin >> x;
	Node* q = new Node;
	q = KhoiTaoNode(x);
	Node* g = L.pHead; 
	if (L.pHead == L.pTail || L.pHead->data == q->data)
	{
		cout << "May khong thay vo li a tml kia =_=\n";
		return;
	}
	for (Node* k = L.pHead ->pnext; k != NULL; k = k->pnext)
	{
		Node* h = KhoiTaoNode(k->pnext ->data)	;
		if (h->data == q->data)
		{
			Node* a = k;
			g->pnext = h;
			delete a;
		}
		delete h;
		g = k;
	}
	XuatDS(L);
}
int main()
{
	List l;
	KhoiTaoList(l);
	cout << " Nhap so luong :";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << " Nhap so thu " << i << " :";
		cin >> x;
		Node * p = KhoiTaoNode(x);
		ThemVaoCuoi(l, p);
	}
	XuatDS(l);
	//ThemNode(l,n);
	//ThemTruoc(l);
	//ThemSau(l);
	/*cout << "\nXoa Dau :\n";
	XoaDau(l);
	cout << "\nXoa cuoi : \n";
	XoaCuoi(l);
	cout << "\nXoa sau : \n";
	XoaSau(l);*/
	cout << "\nXoa truoc : \n";
	XoaTruoc(l);
	system("pause");
	return 0;
}