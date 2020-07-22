#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
int UCLN(int m, int n)
{
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		int p = m % n;
		m = n;
		n = p;
	}
	return m; 
}
class PhanSo
{
private:
	int x;
	int y;
public:
	void Nhap();
	void Xuat();
	friend PhanSo Cong(PhanSo a, PhanSo b);
	friend PhanSo Tru(PhanSo a, PhanSo b);
	friend PhanSo Nhan(PhanSo a, PhanSo b);
	friend PhanSo Chia(PhanSo a, PhanSo b);
};
void PhanSo::Nhap()
{
	cout << "Nhap tu:";
	cin >> x;
	cout << "Nhap mau :";
	cin >> y;
}
void PhanSo::Xuat()
{
	cout << x <<"/"<< y << endl;
}
PhanSo Cong(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.x = a.x*b.y + b.x*a.y;
	c.y = a.y*b.y;
	int p = UCLN(c.x, c.y);
	c.x = c.x / p;
	c.y = c.y / p;
	return c;
}
PhanSo Tru(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.x = a.x * b.y +-b.x * a.y;
	c.y = a.y * b.y;
	int p = UCLN(c.x, c.y);
	c.x = c.x / p;
	c.y = c.y / p;
	return c;
}
PhanSo Nhan(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.x = a.x*b.x;
	c.y = a.y*b.y;
	int p = UCLN(c.x, c.y);
	c.x = c.x / p;
	c.y = c.y / p;
	return c;
}
PhanSo Chia(PhanSo a, PhanSo b)
{
	PhanSo c;
	c.x = a.x * b.y;
	c.y = a.y * b.x;
	int p = UCLN(c.x, c.y);
	c.x = c.x / p;
	c.y = c.y / p;
	return c;
}
int main()
{
	PhanSo a, b;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Nhap  A" << endl;
	a.Nhap();
	cout << "Nhap  B" << endl;
	b.Nhap();
	PhanSo c = Cong(a, b);
	cout << "A + B = C \n C";
	c.Xuat();
	c = Tru(a, b);
	cout << "A - B = D \n D";
	c.Xuat();
	c = Nhan(a, b);
	cout << "A * B = E \n E";
	c.Xuat();
	c = Chia(a, b);
	cout << "A / B = F \n F";
	c.Xuat();
	cout << "--------------------------------------------------------------" << endl;
	system("pause");
	return 0;
}
