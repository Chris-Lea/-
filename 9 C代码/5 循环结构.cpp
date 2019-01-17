#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

int prac1()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 5; j++) printf("%d\t", i*j);
		printf("\n");
	}
	return 0;
}

int prac2()
{
	double pi = 0.0;
	double i = 1; //注意不可是int i，否则计算出来的结果都是int的，
	for (; 1 / (2 * i - 1) >= 1e-6; i++)
	{
		pi += 1 / (2 * i - 1) * pow(-1, i + 1);
		//printf("%lf ", 1 / (2 * i - 1)*pow(-1, i + 1));
		//printf("%lf\t", pi);
	}
	pi *= 4;
	printf("pi=%10.8f", pi);
	return 0;
}

int prac3()
{
#define N 40
	int a[N] = { 1,1 };
	for (int i = 0; i < 40; i++)
	{
		if (i >= 2) a[i] = a[i - 1] + a[i - 2];
		printf("%10d\t", a[i]);
		if ((i+1) % 5 == 0) printf("\n");
	}
	return 0;
}

int main()
{
	//prac1();
	printf("\n");
	//prac2();
	printf("\n");
	prac3();
	printf("\n");
	//prac4();
	printf("\n");
	//prac5();
	printf("\n");
	//prac6();
	printf("\n");
	getchar();
	return 0;
}