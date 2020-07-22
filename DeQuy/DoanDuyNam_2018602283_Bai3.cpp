#include<iostream>
using namespace std;
int Ham(int n)
{
	if (n == 0)
		return 1;
	return n*Ham(n-1);
}
int main()
{

	int n;
	cout << "Nhap n :";
	cin >> n;
	cout << "n! = " << Ham(n) << endl;
	system("pause");
	return 0;
}
