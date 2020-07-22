#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class SanPham
{
protected:
	string MaSP;
	string TenSP;
	string NgaySX;
	float TL;
	string Mau;
public:
	void Nhap()
	{
		cout << "Nhap ma san pham :";
		fflush(stdin);
		getline(cin, MaSP);
		cout << "Nhap ten san pham :";
		fflush(stdin);
		getline(cin, TenSP);
		cout << "Nhap ngay san xuat(dd/mm/yyyy) :";
		fflush(stdin);
		getline(cin, NgaySX);
		cout << "Nhap trong luong :";
		cin >> TL;
		cout << " Mau sac :";
		fflush(stdin);
		getline(cin, Mau);
	}
	void Xuat()
	{
		cout << left << setw(8) << MaSP;
		cout << setw(15) << TenSP;
		cout << setw(11) << NgaySX;
		cout << setw(5) << TL;
		cout << setw(6) << Mau;
	}
};
class HangDienTu : public SanPham
{
private:
	float CongSuat;
	int Dien;
public:
	void Nhap();
	void Xuat();
	int get_TL()
	{
		return TL;
	}
};
void HangDienTu::Nhap()
{
	SanPham::Nhap();
	cout << "Nhap cong suat :";
	cin >> CongSuat;
	cout << "Nhap dong dien :";
	cin >> Dien;
}
void HangDienTu::Xuat()
{
	SanPham::Xuat();
	cout << setw(10) << CongSuat;
	cout << right << setw(6) << Dien;
}
void HienThi()
{
	cout << left << setw(8) << "MaSP";
	cout << setw(15) << "TenSP";
	cout << setw(11) << "Ngay SX";
	cout << setw(5) << "TLuong";
	cout << setw(6) << "Mau";
	cout << setw(10) << "P";
	cout<<right<<setw(6)<<"D.Dien"<< endl;
}
void TL(HangDienTu a[], int n)
{
	int Min = a[0].get_TL();
	int p = 0;
	for (int i = 1; i < n; i++)
	{
		if (Min > a[i].get_TL())
			Min = a[i].get_TL();
	}
	HienThi();
	for (int i = 0; i < n; i++)
	{
		if (Min == a[i].get_TL())
		{
			a[i].Xuat();
		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong danh sach hang dien tu :";
	cin >> n;
	HangDienTu *a = new HangDienTu[n];
	cout << "\t\t================= Nhap Thong Tin  =================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Ky Su " << i + 1 << " :" << endl;
		a[i].Nhap();
	}
	cout << "\t\t=================   Thong Tin Ky Su    =================" << endl;
	HienThi();
	for (int i = 0; i < n; i++)
	{
		a[i].Xuat();
	}
	cout << "\t\t==============  Thong Tin Ky Su Moi TN   ================" << endl;
	TL(a, n);
	system("pause");
	delete a;
	return 0;
}