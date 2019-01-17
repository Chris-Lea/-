#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
struct Person
{
	char name[20];
	int count;
}leader[3] = { {"Li",0},{"Zhang",0},{"Sun",0} };

struct Student
{
	int num;
	char name[20];
	float score;
};

int practice1();
int practice2();


//书P300 例9.3
int practice1()
{
	int i, j;
	char leader_name[20];
	for (i = 0; i < 2; i++)
	{
		printf("There are three candidates running for the position, Li, Zhang, Sun.\n");
		printf("Which one do you want to vote for\n");
		scanf("%s", leader_name);
		getchar();

		for (j = 0; j < 3; j++)
			if (strcmp(leader_name, leader[j].name) == 0)
				leader[i].count++;
	}
	printf("\nThe result is :\n");
	for (i = 0; i < 3; i++)
		printf("%6s:%d\n", leader[i].name, leader[i].count);
	return 0;
}

//书P302 例9.4
int practice2()
{
	struct Student stu[5] = { {10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},
	{10108,"Ling",73.5},{10110,"Sun",100} };
	struct Student tempstu; //不必设值.交换用变量
	//stu[i],tempstu都是类型为struct Student的结构体变量，同类的结构体变量可以相互赋值
	const int n = 5; //定义常变量。也可#define N 5 （符号常量）
	int i, j, k;

	//选择排序法
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++) //第i个和之后的每一个进行比较
		{
			if (stu[j].score > stu[k].score)
				k = j; //找到最大的为第k个
		}
		tempstu = stu[k];
		stu[k] = stu[i]; 
		stu[i] = tempstu; //k与i互换。则实现了在n轮的比较中，将每一轮找出的最大值放在第一位、第二位。。共n(n-1)/2次比较
	}

	printf("The order is :\n");
	for (i = 0; i < n; i++)
		printf("%d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);
	printf("\n");
	return 0;
}

int main()
{
	/*
	struct Person a = { "Li" };//未赋值的int-count成员就自动赋值为0
	printf("a = %d\n", a.count);
	printf("b = %d\n", leader[1].count);
	*/
	/*
	struct Person a = { a.count = 0 };//未赋值的char-name成员就为'\0'
	printf("a = %s\n", a.name);
	*/
	practice1();
	printf("\n");
	practice2();
	printf("\n");
	getchar();
	return 0;
}
