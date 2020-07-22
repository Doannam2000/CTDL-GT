#include<iostream>
using namespace std;
int Ham(int a)
{
	if (a >= 10)
		return a*a;
	return a+Ham(a + 1);
}
int main()
{
	int a;
	cout << "Nhap a :";
	cin >> a;
	cout << "f(a) = " << Ham(a) << endl;
	system("pause");
	return 0;
}