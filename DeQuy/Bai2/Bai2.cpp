#include<iostream>
using namespace std;
int Ham(int a,int b)
{
	if (b == 0)
		return a;
	return Ham(b,a%b);
}
int main()
{
	int a,b;
	cout << "Nhap a :";
	cin >> a;
	cout << "Nhap b :";
	cin >> b;
	cout << "UCLN(a,b) : " << Ham(a,b) << endl;
	system("pause");
	return 0;
}