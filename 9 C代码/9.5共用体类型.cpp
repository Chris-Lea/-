#include<stdio.h>
#pragma warning(disable:4996)

union Date
{
	int i;
	char ch;
	float f;
};
struct
{
	int num;
	char name[10];
	char sex;
	char job;				//struct成员：编号、姓名、性别、职业
	union
	{
		int clas;
		char position[10];		//union成员：班级、职务
	}category;              //struct成员category是共用体变量
}person[2];                 //定义结构体数组person，有2个元素

int practice1();
int practice2();

int main()
{
	printf("This is the practice1:\n");
	practice1();
	printf("This is the practice2:\n");
	//practice2();
	getchar();
	return 0;
}

//书P319 9.5.3（2）
int practice1()
{
	union Date a;
	a.i = 97;
	printf("%d\n", a.i);
	printf("%c\n", a.ch);
	printf("%f\n", a.f);//无论是哪个成员，存储的都是97
	printf("\n");

	a.ch = 'a';
	a.f = 1.5;
	a.i = 40;
	printf("%d\n", a.i); //40的%d输出
	printf("%c\n", a.ch); //40的%char输出。原来的a.ch = 'a'被覆盖了
	printf("\n");

	printf("%o\n%o\n%o\n", &a.i, &a.ch, &a.f);//无论是哪个成员，其地址都是一样的
	printf("\n");
	return 0;
}

//书P321 例9.11
int practice2()
{
	for (int i = 0; i < 2; i++) //循环i次，输入i个老师/教师
	{
		printf("Please enter the data of person,\ninclude his number,name,sex,job\n");
		scanf("%d %s %c %c", &person[i].num, &person[i].name, &person[i].sex, &person[i].job);//输入前4项
		getchar();
		if (person[i].job == 's')
		{
			printf("So he is a student,please enter his class:\n");
			scanf("%d", &person[i].category.clas);//如果是学生，则输入班级
			getchar();
		}
		else if (person[i].job == 't')
		{
			printf("So he is a teacher,please enter his position:\n");
			scanf("%s", &person[i].category.position);//如果是教师，则输入职务
			getchar();
		}
		else printf("Input error!");
	}
	printf("\n");
	printf("No.    Name      Sex Job Class/Position\n");
	for (int i = 0; i < 2; i++) //循环i次，输出i个老师/教师
	{
		if (person[i].job == 's') //若是学生
			printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.clas);
		else  //若是教师
			printf("%-6d%-10s%-4c%-4c%-10s\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.position);
	}
	return 0;
}
