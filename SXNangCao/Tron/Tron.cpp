#include<iostream>
using namespace std;

void NhapDanhSach(int a[], int n)
{
	cout << "\t\tNhap danh sach " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vi tri " << i + 1 << " :";
		cin >> a[i];
	}
}
void Xuat(int a[], int n)
{
	cout << "\t\t Danh sach " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap n:";
	cin >> n;
	int* a = new int[n];
	NhapDanhSach(a, n);
	cout << "\t\t Truoc khi sap xep" << endl;
	Xuat(a, n);
	cout << "\t\t Khi sap xep" << endl;
	Xuat(a, n);
	system("pause");
	return 0;
}