#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
#define z 5;


//输入10个数，求出最大值.&& 数组元素作为实参
int prac1()
{
	int max(int x, int y); //变量作形参
	int a[10], i, m, n;
	printf("Please enter 10 numbers:");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	getchar();
	for (i = 1, m = a[0], n = 0; i < 10; i++) //在for循环中声明i,m,n或只声明i都不行，原因不明
	{
		if (max(m, a[i]) > m) //数组元素作为实参
		{
			m = max(m, a[i]); //数组元素作为实参
			n = i;
		}
	}
	printf("The largest number is %d.\n", m);
	printf("It is the No.%d number\n", n+1);
	return 0;
}
int max(int x, int y)
{
	return(x > y ? x : y);
}

//算一个班学生的成绩平均数。//数组名作形参；数组名作实参
int prac2()
{
	float average(float score[10]); //数组名作形参
	float score[10], aver;
	printf("Please enter scores of ten students:\n");
	for (int i = 0; i < 10; i++)
		scanf("%f", &score[i]);
	getchar();
	aver = average(score); //数组名作实参
	printf("Their average score is %5.2f", aver);
	return 0;
}
#define N 4
float average(float score[N])
{
	float aver, sum = 0;
	for (int i = 0; i < 10; i++)
		sum += score[i];
	aver = sum / 10;
	return aver;
}

//算两个班学生的成绩平均数
int prac3()
{
	float score1[] = { 98.5,97,91.5,60,55 };
	float score2[] = { 67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5 };
	float average(float score[], int n);
	float aver1, aver2;

	aver1 = average(score1,5);
	aver2 = average(score2,10); //传递数组名
	printf("The average scores of class NO.1 is %.2f\n", aver1);
	printf("The average scores of class NO.2 is %.2f", aver2);
	return 0;
}
float average(float score[], int n)
{
	float aver, sum = 0;
	for (int i = 0; i < n; i++)
		sum += score[i];
	aver = sum / n;
	return aver;
}

//用选择排序法对数组的元素进行排序
int prac4()
{
	return 0;
}
int sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n-1; i++)
	{
		k = i; //记录顺序编号
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[k])
				k = j; // i与后面的元素比较，找出最小的j，记在k上。//即使k、j进行了交换，但array[k]一直代表的是最初的array[i]
		}
		t = array[k]; array[k] = array[i]; array[i] = t; //k与i交换
	}
	return 0;
}

int main()
{
	//prac1();
	prac2();
	//prac3();
	getchar();
}