#include<stdio.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//指针的指向/赋值p=a <=> p=&a[0]; 
//指针与数的加减算术和通过指针引用数组*(p+i) = *(a+i) = a[i]。实际上也等价于p[i]，因为p[i]会被处理成*(p+i)，但要注意p指针指向第几个元素，a永远指向第一个元素。详见书P236（2）
//指针之间的减运算，若两个指针变量p0与p都指向同一元组，则表所指元素的相对距离
int prac1()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *p = a; //等价于int *p=&a[0];
	int *p0 = &a[9];
	printf("The First Element is: %d\n", *p);

	p++; //实际意思是(p+1)*d，p指针的基类型是int，所以这里d=4；
	printf("The Second Element is: %d\n", *p); 

	printf("The Second Element is: %d\n", *(a + 1)); //a永远表示第一个元素的地址.实际上a也不能自加或自减。not a++, a+=1
	printf("The Third Element is: %d\n", *(a + 2));

	printf("The Fourth Element is: %d\n", *(p + 2)); //p刚才指向第二个元素。(p+2)*d = (&a[1]+2)*d

	printf("Now, the Gap between p0 and p is %d", p0 - p); //所指元素的相对距离=8
	return 0;
}

//scanf: &a[i]; a+i; p+i
//printf: p++, p; a[i]; *(a+i); *(p++)
int prac2()
{
	int a[10];
	int *p = a;
	printf("Please Enter 10 Number:");
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
		//scanf("%d",a+i);
		//scanf("%d",p+i); //若是这行代码，则下面的for循环中必须重置p=a，因为此时p已指向最后一个元素
	getchar();

	printf("Here are the Numbers:\n");
	for (; p < (a + 10); p++)
		printf("%d ", *p); //取p的值后，再p++，然后判定p < (a + 10)
	printf("\n");

	printf("Print the Numbers at Second Time:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ",a[i]);
	printf("\n");

	printf("Print the Numbers at Third Time:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", *(a+i)); //不可a++，所以要借助i
	printf("\n");

	printf("Print the Numbers at Fourth Time:\n");
	p = a;
	for (int i = 0; i < 10; i++)
		printf("%d ", *p++); //根据运算的优先值可知，等价于*(p++), 先取p值，再p++
	printf("\n");

	return 0;
}


int main()
{
	prac1();
	printf("\n");
	prac2();
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