#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[100];
	printf("\nNhap chuoi : "); gets_s(str);
	system("cls");
	printf("\nChuoi vua nhap: "); puts(str);
	int i, h = 0, t = 0, s = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57) s++;
		else if (str[i] >= 65 && str[i] <= 90) h++;
		else if (str[i] >= 97 && str[i] <= 122) t++;
	}
	printf("\nChuoi co:\n\t %d chu cai in hoa. \n\t %d chu cai thuong. \n\t%d chu so.", h, t, s);
	char str1[100];
	strcpy(str1, strrev(str));
	printf("\nChuoi nguoc str1 la: "); puts(str1);
	if (s == 0) printf("\nMang khong co chu so.");
	else {

		char chu[99][10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
		int n = strlen(str);
		for (i = 0; i < n; i++)
		{
			if (str[i] >= 48 && str[i] <= 57)
			{
				for (int j = i; j < n - 1; j++)
				{
					str[j] = str[j + 1];
				}
				n--;
				str[n] = '\0';
				i--;
			}
		}
		puts(str);
	}
	system("pause");
	return 0;
}
