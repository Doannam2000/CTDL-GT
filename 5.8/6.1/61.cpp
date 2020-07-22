#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class VECTO
{
private:
	float x;
	float y;
public:
	VECTO operator+(VECTO b);
	VECTO operator-(VECTO b);
	friend istream& operator>>(istream& n, VECTO& m);
	friend ostream& operator <<(ostream& n, VECTO m);
};
istream& operator >>(istream& n, VECTO& m)
{
	cout << "Nhap x:";
	n >> m.x;
	cout << "Nhap y :";
	n >> m.y;
	return n;
}
ostream& operator<<(ostream& n, VECTO m)
{
	n << "(" << m.x << "," << m.y << ")";
	return n;
}
VECTO VECTO::operator +(VECTO b)
{
	VECTO c;
	c.x = x + b.x;
	c.y = y + b.y;
	return c;
}
VECTO VECTO:: operator -(VECTO b)
{
	VECTO c;
	c.x = x - b.x;
	c.y = y - b.y;
	return c;
}
int main()
{
	VECTO a, b;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Nhap toa do A" << endl;
	cin >> a;
	cout << "Nhap toa do B" << endl;
	cin >> b;
	VECTO c = a + b;
	cout << "A + B = C \n C";
	cout << c << endl;
	c = a - b;
	cout << "A - B = D \n D";
	cout << c << endl;
	cout << "--------------------------------------------------------------" << endl;
	system("pause");
	return 0;
}
