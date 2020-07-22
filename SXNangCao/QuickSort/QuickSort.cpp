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
void QuickSort(int a[], int Left, int Right)
{
	if (Left < Right)
	{
		int i = Left;
		int j = Right;
		int t = a[(Left + Right) / 2];
		while (i <= j)
		{
			while (a[i] < t) i++;
			while (a[j] > t) j--;
			if (i <= j)
			{
				int p = a[i];
				a[i] = a[j];
				a[j] = p;
				i++;
				j--;
			}
		}
		QuickSort(a, Left, j);
		QuickSort(a, i, Right);
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
	QuickSort(a, 0, n - 1);
	cout << "\t\t Khi sap xep" << endl;
	Xuat(a, n);
	system("pause");
	return 0;
}