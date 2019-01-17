#include<stdio.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//入门指针型变量
int prac1()
{
	int a = 1, b = 2;
	int *a_pointer, *b_pointer;
	a_pointer = &a; b_pointer = &b;
	//*a_pointer = a; *b_pointer = b; //间接访问
	//Error:使用了未初始化的局部变量，因为若无（a_pointer = &a; b_pointer = &b;）则指针未指向任何变量，即未赋值
	//而若要对指针变量进行初始化，则int *a_pointer = &a, *b_pointer = &b;详见prac2();
	//所以可以
	/*
	a_pointer = &a; b_pointer = &b;
	*a_pointer = b; *b_pointer = a;
	*/
	printf("a=%d, b=%d\n", a, b);
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	printf("&a=%o\n", &a); //八进制输出地址
	printf("a_pointer=%o\n", &*a_pointer); //八进制输出地址
	return 0;
}

//初始化
int prac2()
{
	int a = 1, b = 2;
	int * a_pointer = &a, * b_pointer = &b;
	//这里的初始化中。int *是一部分，表明声明的是指向int(基类型)的指针型变量，a_pointer = &a是另一部分，表明初始化。
	printf("a=%d, b=%d\n", a, b);
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	return 0;
}

//间接赋值 *a_pointer=1
int prac3()
{
	int a , b ;
	int *a_pointer, *b_pointer;
	a_pointer = &a; b_pointer = &b;
	*a_pointer = 1, *b_pointer = 2; //*  指针运算符或“间接访问”运算符
	printf("a=%d, b=%d\n", a, b); 
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	return 0;
}

//比大小：换指针变量的值
//scanf赋给p1也行（&a）
int prac4()
{
	int a, b, *p1, *p2, *p;
	p1 = &a; p2 = &b;
	printf("Please Enter Two Number;\n");
	scanf("%d %d", p1, p2);
	getchar();
	//scanf("a=%d,b=%d", &a, &b);
	if (a < b)
	{
		p = p1; p1 = p2; p2 = p;
		//p1 = &b; p2 = &a;
	}
	printf("a=%d,b=%d\n", a, b);
	printf("max=%d, min=%d\n", *p1, *p2);
	return 0;
}

//指针变量作为函数参数。函数传入p（形参是p），在函数内部对*p进行交换，则在值的单向传递中也能完成值的交换。
//若在单向传递中（即无return），对变量本身（a），或指针变量本身（p）进行变换，则实参无动于衷。见书P228最上和例8.4
int prac5()
{
	int swap(int *p1, int *p2); //声明函数sqap函数并声明函数需要用到的变量
	int a, b, *p1, *p2; //声明prac5函数的局部变量
	p1 = &a; p2 = &b;
	printf("Please Enter Two Number;\n");
	scanf("%d %d", p1, p2);
	getchar();
	printf("&a=%o\n&b=%o\n", &a,&b); 
	if (a < b)
		swap(p1, p2);
	printf("a=%d,b=%d\n", a, b);
	printf("max=%d, min=%d\n", *p1, *p2);
	printf("&a=%o\n&b=%o", &a, &b);//实验结果发现a，b的值交换了，但是a，b的地址未变
	return 0;
}

//交换两个*p
int swap(int *p1, int *p2)
{
	int  temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	return 0;
}

//三个值比大小
int prac6()
{
	int exchange(int *p1, int *p2, int *p3);
	int a, b, c, *p1, *p2, *p3;
	p1 = &a; p2 = &b; p3 = &c;
	printf("Please Enter Three Number;\n");
	scanf("%d %d %d", &a, &b, &c);
	getchar();
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	exchange(p1, p2, p3);
	printf("a=%d,b=%d,c=%d\n", a, b, c);
	printf("The Order is: %d, %d, %d.", *p1, *p2, *p3);
	return 0;
}

//将*p1,*p2,*p3实现从大到小的排列
int exchange(int *p1, int *p2, int *p3)
{
	int swap(int *p1, int *p2);
	if (*p1 < *p2) swap(p1, p2);
	if (*p1 < *p3) swap(p1, p3);
	if (*p2 < *p3) swap(p2, p3);
	return 0;
}

int main()
{
	prac1();
	printf("\n");
	//prac2();
	printf("\n");
	//prac3();
	printf("\n");
	//prac4();
	printf("\n");
	//prac5();
	printf("\n");
	prac6();
	printf("\n");
	getchar();
	return 0;
}