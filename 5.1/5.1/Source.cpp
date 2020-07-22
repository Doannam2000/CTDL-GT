#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class PERSON
{
protected:
	string Hoten;
	string Ngaysinh;
	string Quequan;
};
class KYSU : public PERSON
{
private:
	string Nganh;
	int NamTN;
public:
	void Nhap();
	void Xuat();
	int get_Nam()
	{
		return NamTN;
	}
};
void KYSU::Nhap()
{
	cout << "Nhap Ho Ten :";
	cin.ignore();
	getline(cin, Hoten);
	cout << "Nhap Ngay sinh (dd/mm/yyyy) :";
	fflush(stdin);
	getline(cin, Ngaysinh);
	cout << "Nhap Que quan :";
	fflush(stdin);
	getline(cin, Quequan);
	cout << "Nhap Nganh :";
	fflush(stdin);
	getline(cin, Nganh);
	cout << "Nhap nam tot nghiep :";
	cin >> NamTN;
}
void KYSU::Xuat()
{
	cout << left << setw(15) << Hoten;
	cout << setw(11) << Ngaysinh;
	cout << setw(10) << Quequan;
	cout << setw(6) << Nganh;
	cout << right << setw(6) << NamTN << endl;
}
void HienThi()
{
	cout << left << setw(4) << "STT";
	cout << setw(15) << "Ho Ten";
	cout << setw(11) << "Ngay Sinh";
	cout << setw(10) << "Que Quan";
	cout << setw(6) << "Nganh";
	cout << right << setw(6) << "Nam TN" << endl;
}
void MoiTN(KYSU a[], int n)
{
	int Max = a[0].get_Nam();
	int p = 0;
	for (int i = 1; i < n; i++)
	{
		if (Max < a[i].get_Nam())
			Max = a[i].get_Nam();
	}
	HienThi();
	for (int i = 0; i < n; i++)
	{
		if (Max == a[i].get_Nam())
		{
			p++;
			cout << setw(4) << left << p;
			a[i].Xuat();
		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong ky su :";
	cin >> n;
	KYSU* a;
	a = new KYSU[n];
	cout << "\t\t================= Nhap Thong Tin Ky Su =================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Ky Su " << i + 1 << " :" << endl;
		a[i].Nhap();
	}
	cout << "\t\t=================   Thong Tin Ky Su    =================" << endl;
	HienThi();
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << left << i + 1;
		a[i].Xuat();
	}
	cout << "\t\t==============  Thong Tin Ky Su Moi TN   ================" << endl;
	MoiTN(a, n);
	system("pause");
	delete a;
	return 0;
}