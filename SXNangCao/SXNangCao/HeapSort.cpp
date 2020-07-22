#include<iostream>
using namespace std;

void NhapDanhSach(int a[], int n)
{
	cout << "\t\tNhap danh sach " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vi tri " << i + 1<<" :";
		cin >> a[i];
	}
}
void Xuat(int a[], int n)
{
	cout << "\t\t Danh sach " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<"\t";
	}
	cout << endl;
}
void HoanVi(int a[], int d, int n)
{
	if (d <= n / 2 - 1)
	{
		int i = 2*d + 1;
		if (a[i] < a[i + 1] && i + 1 < n)
			i++;
		if (a[i] > a[d])
		{
			int p = a[i];
			a[i] = a[d];
			a[d] = p;
			HoanVi(a, i, n);
		}
	}
}
void TaoDongDau(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		HoanVi(a, i, n);
	}
}
void SapXep(int a[], int n)
{
	TaoDongDau(a, n);
	for (int i = n; i > 1; i--)
	{
		int p = a[0];
		a[0] = a[i - 1];
		a[i - 1] = p;
		HoanVi(a, 0, i - 1);
	}
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
	SapXep(a, n);
	cout << "\t\t Khi sap xep" << endl;
	Xuat(a, n);
	system("pause");
	return 0;
}