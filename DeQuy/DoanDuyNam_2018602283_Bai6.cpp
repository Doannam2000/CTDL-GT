#include<iostream>
using namespace std;
int Ham(int n)
{
	if (n <= 2)
		return 1;
	return Ham(n - 1)+ Ham(n-2);
}
int main()
{

	int n;
	cout << "Nhap n :";
	cin >> n;
	cout << "f(n) = " << Ham(n) << endl;
	system("pause");
	return 0;
}
