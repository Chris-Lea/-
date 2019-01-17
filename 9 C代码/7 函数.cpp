#include<stdio.h>
#pragma warning(disable:4996)
void prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//空函数没有return或者return;
void prac1()
{
	printf("Test:If void function could return void? ");
	//return ;
}

//函数的定义(函数原型)、声明与调用
int prac2()
{
	float add(float a, float b);
	float a, b;
	printf("Please enter two numbers:\n");
	scanf("%f %f", &a, &b);
	getchar();
	printf("The addition of the two numbers is:%.2f\n", add(a, b));
	return 0;
}

float add(float a, float b)
{
	return a + b;
}

//函数的嵌套使用
int prac3()
{
	int a, b, c, d;
	int max4(int, int, int, int);
	printf("Please enter four number :\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	getchar();
	printf("The max is: %d\n", max4(a, b, c, d));
	return 0;
}

int max4(int a, int b, int c, int d)
{
	int max2(int, int);
	int m;
	m = max2(a, b);
	m = max2(m, c);
	m = max2(m, d);
	// or m=max2(max2(max2(a.b),c),d));
	return m;
}

int max2(int a, int b)
{
	return a > b ? a : b;
}

//函数的递归调用
int prac4()
{
	int age(int n);
	printf("NO.5学生的年龄是：%d", age(5));
	return 0;
}

int age(int n)
{
	int theage;
	if (n == 1) theage = 10;
	else theage = age(n - 1) + 2;
	return theage;

}

int main()
{
	//prac1();
	printf("\n");
	//prac2();
	printf("\n");
	//prac3();
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