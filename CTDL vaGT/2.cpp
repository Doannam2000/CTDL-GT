#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class DoanhNghiep;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	void nhap();
	void xuat();
};
typedef class Date NTL;
void Date::nhap()
{
	cout << "Nhap ngay :";
	cin >> day;
	cout << "Nhap thang :";
	cin >> month;
	cout << "Nhap nam :";
	cin >> year;
}
void Date::xuat()
{
	cout <<setw(3)<<left<< day << "/";
	cout<<setw(3)<<left<< month << "/";
	cout<<setw(4) <<left<< year;
}
class DiaChi
{
private:
	char dienThoai[12];
	char phuong[30];
	char quan[30];
	char thanhPho[30];
public:
	friend class DoanhNghiep;
	friend void SearchHN(DoanhNghiep a[], int n);
};
typedef class DiaChi DC;
class DoanhNghiep
{
private:
	int maDn;
	char tenDn[60];
	NTL ngayTl;
	DC diaChi;
	char giamDoc[30];
	long doanhThu;
public:
	void Nhap();
	void xuat();
	friend void SearchHN(DoanhNghiep a[],int n);
};
void DoanhNghiep::Nhap()
{
	cout << "Nhap ma doanh nghiep :";
	cin >> maDn;
	cout << "Ten doanh nghiep :";
	fflush(stdin);
	gets(tenDn);
	cout << "Nhap ngay thanh lap :";
	ngayTl.nhap();
	cout << "Nhap dia chi:"<<endl;
	cout << "1.So dien thoai :";
	fflush(stdin);
	gets(diaChi.dienThoai);
	cout << "\n2.phuong :";
	fflush(stdin);
	gets(diaChi.phuong);
	cout << "\n3.quan :";
	fflush(stdin);
	gets(diaChi.quan);
	cout << "\n4.thanh pho :";
	fflush(stdin);
	gets(diaChi.thanhPho);
	cout << "\nNhap ten giam doc :";
	fflush(stdin);
	gets(giamDoc);
	cout << "Nhap doanh thu :";
	cin >> doanhThu;
}
void DoanhNghiep::xuat()
{
	cout<<endl;
    cout<<left<<setw(10)<<maDn;
	cout<<setw(10)<<tenDn;
    ngayTl.xuat();
	cout <<right<< setw(10) << diaChi.dienThoai;
	cout << setw(10) << diaChi.phuong;
	cout << setw(10) << diaChi.quan;
	cout << setw(12) << diaChi.thanhPho;
	cout << setw(10) << giamDoc;
	cout << setw(12) << doanhThu;
}
void out()
{
	cout<<left<<setw(10)<<"MaDN";
	cout<<setw(10)<<"TenDN";
	cout<<setw(12)<<"Date";
	cout<<right<<setw(10)<<"SDT";
	cout<<setw(10)<<"Phuong";
	cout<<setw(10)<<"Quan";
	cout<<setw(12)<<" TP ";
	cout<<setw(10)<<"GiamDoc";
	cout<<setw(12)<<"DoanhThu";
}
void SearchHN(DoanhNghiep a[],int n)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].diaChi.thanhPho,"Ha Noi") == 0)
		{
			a[i].xuat();
		}
	}
}
int main()
{
	int n;
	cout<<"Nhap so luong doanh nghiep";
	cin>>n;
	DoanhNghiep *a;
	a= new DoanhNghiep[n];
	cout<<"Nhap thong tin doanh nghiep";
	for(int i=0;i<n;i++)
	{
		cout<<"Doanh nghiep "<<i+1<<" :"<<endl;
		a[i].Nhap();
	}
	cout<<"Thong tin doanh nghiep"<<endl;
	out();
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	return 0;
}
