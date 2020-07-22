#include<iostream>
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
	Node* pnext;
};
typedef struct Node* Node;
struct List
{
	Node* pHead;
};
void KhoiTaoList(List &L)
{
	L.pHead = NULL;
};
Node KhoiTaoNode(HocPhan x)
{
	
}
int main()
{

}