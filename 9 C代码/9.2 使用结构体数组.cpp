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


//��P300 ��9.3
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

//��P302 ��9.4
int practice2()
{
	struct Student stu[5] = { {10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},
	{10108,"Ling",73.5},{10110,"Sun",100} };
	struct Student tempstu; //������ֵ.�����ñ���
	//stu[i],tempstu��������Ϊstruct Student�Ľṹ�������ͬ��Ľṹ����������໥��ֵ
	const int n = 5; //���峣������Ҳ��#define N 5 �����ų�����
	int i, j, k;

	//ѡ������
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++) //��i����֮���ÿһ�����бȽ�
		{
			if (stu[j].score > stu[k].score)
				k = j; //�ҵ�����Ϊ��k��
		}
		tempstu = stu[k];
		stu[k] = stu[i]; 
		stu[i] = tempstu; //k��i��������ʵ������n�ֵıȽ��У���ÿһ���ҳ������ֵ���ڵ�һλ���ڶ�λ������n(n-1)/2�αȽ�
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
	struct Person a = { "Li" };//δ��ֵ��int-count��Ա���Զ���ֵΪ0
	printf("a = %d\n", a.count);
	printf("b = %d\n", leader[1].count);
	*/
	/*
	struct Person a = { a.count = 0 };//δ��ֵ��char-name��Ա��Ϊ'\0'
	printf("a = %s\n", a.name);
	*/
	practice1();
	printf("\n");
	practice2();
	printf("\n");
	getchar();
	return 0;
}
