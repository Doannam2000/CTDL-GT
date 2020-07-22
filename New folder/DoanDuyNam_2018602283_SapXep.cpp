#include<iostream>
using namespace std;
void BubleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int p = a[j];
				a[j] = a[j - 1];
				a[j - 1] = p;
			}
		}
	}
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int m = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[m] > a[j])
				m = j;
		}
		if (m != i)
		{
			int p = a[i];
			a[i] = a[m];
			a[m] = p;
		}
	}
}
void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int t = a[i];
		int j = i - 1;
		while (j >= 0 && t < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = t;
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "  \t" << a[i];
	}
}
int main()
{
	int a[] = { 20,15,89,7,5,6,18,78 };
	InsertSort(a, 8);
	xuat(a, 8);
	system("pause");
	return 0;
}
