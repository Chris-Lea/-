# include<stdio.h>
# include<math.h>
#pragma warning(disable:4996)
#define BUFF_LEN 11 // 12 may fix the Run-Time Check Failure #2 


int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//实参用数组名
int prac1()
{
	int inv1(int arr[], int num); //数组有点神烦，这里形参arr[]并不是表数组，而是数组名、指针变量，不能表示地址（？）
	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = 10;
	printf("The Original Order is :\n");
	for (int i = 0; i < n; i++)
		printf("%d ", *(array + i));
	printf("\n");

	inv1(array, 10); //实参array传入数组名，代表指针变量，数组名
	printf("The New Order is :\n");
	for (int i = 0; i < n; i++)
		printf("%d ", *(array + i));
	printf("\n");
	return 0;
}

//形参用数组名
int inv1(int arr[], int num)
{
	int temp, m = (num - 1) / 2, j;
	for (int i = 0; i <= m; i++)
	{
		j = num - 1 - i;
		temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
	}
	return 0;
}

//实参用指针
int prac2()
{
	int inv2(int *p, int num); //形参用指针
	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = 10;
	int *p = array;
	printf("The Original Order is :\n");
	for (; p<array+10; p++)
		printf("%d ", *p);
	printf("\n");
	p = array;

	inv2(p, 10); //实参用指针
	printf("The New Order is :\n");
	for (p=array; p < array + 10; p++)
		printf("%d ", *p);
	printf("\n");
	return 0;
}

//形参用指针
int inv2(int *p, int num)
{
	int temp, *m = p+(num - 1) / 2, *j;
	j = p + num - 1;
	for (; p <= m; p++)
	{
		temp = *p; *p = *j; *j = temp;
		j--;
	}
	return 0;
}

//四种情况都有。实际上形参在编译时都是用作指针变量.主函数prac3()里都一样，只是副函数inv()里面写法不一样
int prac3()
{
	int inv1(int arr[], int num); //形参用数组名
	int inv2(int *p, int num); //形参用指针
	int array[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = 10;
	int *p = array;
	printf("The Original Order is :\n");
	for (; p < array + 10; p++)
		printf("%d ", *p);
	printf("\n");

	p = array; //指针的实参传入形参前，先重置
	inv2(p, 10); //形参用指针, 实参用指针
	printf("the First invertion :\n");
	for (p = array; p < array + 10; p++)
		printf("%d ", *p);
	printf("\n");

	inv2(array, 10); //形参用指针, 实参用指针
	printf("the Second Order is :\n");
	for (p = array; p < array + 10; p++)
		printf("%d ", *p);
	printf("\n");

	inv1(array, 10); //形参用数组名, 实参用数组名
	printf("the Third Order is :\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	p = array; //指针的实参传入形参前，先重置
	inv1(p, 10); //形参用数组名, 实参用指针
	printf("the Fourth Order is :\n");
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

//实现排序
int prac4()
{
#define N 11
	int sort(int a[], int num);
	int array[N];
	int *p = array;
	printf("Please Enter %d Numbers:\n",N);
	for (; p < array + N; p++)
		scanf("%d",p);
	getchar();
	printf("\n");
	p = array;
	sort(p, N);
	printf("The Sorted Result is :\n");
	for (p=array; p < array + N; p++)
		printf("%d ", *p);
	return 0;
}

int sort(int a[], int num)
{
	int i, j, k, t;
	for (i = 0; i < num-1; i++)
	{
		k = i;
		for (j = i + 1; j < num; j++)
			if (a[j] > a[k]) k = j;
			if (k != i)
			{
				t = a[i]; a[i] = a[k]; a[k] = t;
			}
	}
	return 0;
}
int main()
{
	float f;
	f = 64.1;
	printf("%30.17f\n%30.24lf\n", f,f); 
	printf("%d\n%d", (int)pow(8,1/3),sqrt(4));
	printf("%d", sizeof(short));
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