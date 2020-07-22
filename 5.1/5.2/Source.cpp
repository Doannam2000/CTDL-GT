#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class VEHICLE
{
protected:
	string NhanHieu;
	int NamSX;
	string Hang;
public:
	void Nhap()
	{
		cout << "Nhap Nhan Hieu :";
		//fflush(stdin);
		cin.ignore();
		getline(cin, NhanHieu);
		cout << "Nam San Xuat :";
		cin >> NamSX;
		cout << "Nhap Hang :";
		cin.ignore();
		getline(cin, Hang);
	}
	void Xuat()
	{
		cout << setw(10) << left << NhanHieu;
		cout << setw(6) << NamSX;
		cout << setw(10) << Hang;
	}
};
class OTO : public VEHICLE
{
private:
	int DungTich;
	int SoChoNgoi;
public:
	void Nhap();
	void Xuat();
};
class MOTO : public VEHICLE
{
private:
	int PhanKhoi;
public:
	void Nhap();
	void Xuat();
};

void OTO::Nhap()
{
	VEHICLE::Nhap();
	cout << "\nNhap Dung tich :";
	cin >> DungTich;
	cout << "Nhap so cho ngoi :";
	cin >> SoChoNgoi;
}
void OTO::Xuat()
{
	VEHICLE::Xuat();
	cout << setw(6) << DungTich;
	cout << setw(3) << right << SoChoNgoi << endl;
}
void MOTO::Nhap()
{
	VEHICLE::Nhap();
	cout << "\nNhap phan khoi :";
	cin >> PhanKhoi;
}
void MOTO::Xuat()
{
	VEHICLE::Xuat();
	cout << setw(4) << PhanKhoi << endl;
}
void HienThi(int b)
{
	cout << left << setw(10) << "Nhan Hieu";
	cout << setw(6) << "NamSX";
	cout << setw(10) << "Hang";
	if (b == 1)
	{
		cout << setw(6) << "DTich";
		cout << right << setw(4) << "Cho" << endl;
	}
	else
	{
		cout << right << setw(4) << "PK" << endl;
	}
}
int main()
{
	OTO* a = new OTO;
	MOTO* b = new MOTO;
	cout << "\t\t\tNhap thong tin OTO " << endl;
	a->Nhap();
	cout << "\t\t\tNhap thong tin MOTO" << endl;
	b->Nhap();
	cout << "\t\t\tThong tin OTO" << endl;
	HienThi(1);
	a->Xuat();
	cout << "\t\t\tThong tin MOTO" << endl;
	HienThi(2);
	b->Xuat();
	system("pause");
	delete a;
	delete b;
	return 0;
}