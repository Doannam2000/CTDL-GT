#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class NS 
{
protected:
	int d;
	int m;
	int y;
public:
	void Nhap();
	void Xuat();
	int get_Nam()
	{
		return y;
	};
};
void NS::Nhap()
{
	cout << "Nhap ngay :";
	cin >> d;	
	cout << "Nhap thang :";
	cin >> m;
	cout << "Nhap nam :";
	cin >> y;
}
void NS::Xuat()
{
	cout <<right<< setw(3) << d;
	cout << right << "/" << setw(2) << m;
	cout << right << "/" << setw(4) << y;
}
class CSBN : public NS
{
protected:
	string HoTen;
	string Que;
	NS day;
public:
	void Nhap();
	void Xuat();
	int get_Nam()
	{
		return day.get_Nam();
	}
	string get_T()
	{
		return HoTen;
	}
};
void CSBN::Nhap()
{
	cout << "Nhap ho ten :";
	cin.ignore();
	getline(cin, HoTen);
	cout << "Nhap que quan :";
	cin.ignore();
	getline(cin, Que);
	cout << "Nhap nam sinh (dd/mm/yyyy)"<<endl;
	day.Nhap();
}
void CSBN::Xuat()
{
	cout << right<<setw(10) << HoTen;
	cout << right<<setw(10) << Que;
	day.Xuat();
}
class LBA : public CSBN
{
private:
	CSBN H;
	string TBA;
	int Money;
public:
	void Nhap();
	void Xuat();
	int get_Nam()
	{
		return H.get_Nam();
	}
	int get_M()
	{
		return Money;
	}
	string get_T()
	{
		return H.get_T();
	}
};
void LBA::Nhap()
{
	cout << "Nhap ten benh an :";
	cin.ignore();
	getline(cin, TBA);
	H.Nhap();
	cout << "Nhap tien :";
	cin >> Money;
}
void LBA::Xuat()
{
	cout << right << setw(10) << TBA;
	H.Xuat();
	cout << right << setw(10) << Money;
}
void HH()
{
	cout << setw(4) << "STT";
	cout << setw(10) << "Ten BA";
	cout << setw(10) << "Ten";
	cout << setw(10) << "Que";
	cout << setw(11) << "Day";
	cout<<setw(10)<<"Tien" << endl;
}
void HienThi(LBA a[],int n)
{
	HH();
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << i + 1;
		a[i].Xuat();
		cout << endl;
	}
}
void Sort(LBA a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].get_Nam() > a[j].get_Nam())
			{
				LBA x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
		}
	}
	cout << "\t\t----------- Danh sach ben an sau khi sx-----------" << endl;
	HienThi(a, n);
}
void Tuoi(LBA a[],int n)
{
	cout << "\t\t----------- Danh sach < 10-----------" << endl;
	HH();
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		if (2020 - a[i].get_Nam() <= 10)
		{
			d++;
			cout << setw(4) << d;
			a[i].Xuat();
			cout << endl;
		}
	}
}
void Tien(LBA a[], int n)
{
	int Max = a[0].get_M();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].get_M() > Max)
			{
				Max = a[i].get_M();
			}
		}
	}
	cout << " Ten benh nhan co vien phi cao nhat :" << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i].get_M() == Max)
		{
			cout << a[i].get_T() << endl;
		}
	}
}
int main()
{
	LBA* a;
	cout << "Nhap so luong benh an :";
	int n;
	cin >> n;
	a = new LBA[n];
	cout << "\t\t--------------- Nhap danh sach ben an ---------------"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin benh an so " << i + 1 <<endl;
		a[i].Nhap();
	}
	cout << "\t\t--------------- Danh sach ben an ---------------"<<endl;
	HienThi(a, n);
	Sort(a, n);
	Tuoi(a, n);
	Tien(a, n);
	cout << "--------------------------------------------------------------";
	system("pause");
	return 0;
}
