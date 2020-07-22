#include<iostream>
using namespace std;
int Ham(int n)
{
	if (n < 10)
		return 1;
	return 1 + Ham(n/10);
}
int main()
{

	int n;
	cout << "Nhap n :";
	cin >> n;
	cout << "n co " << Ham(n) << " chu so "<< endl;
	system("pause");
	return 0;
}
