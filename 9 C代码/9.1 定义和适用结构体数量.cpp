#include <stdio.h>
#pragma warning(disable:4996)
/*第九章 结构体变量*/
/*
typedef struct 
{	int month;
	int day;
	int year;
} Date ;//Date是类型名
error
*/

struct Date
{	int month;
	int day;
	int year;
};
int practice1();
int practice2();

//书P297 例9.1
int practice1()
{
	struct Student
	{	
		long int Sno;
		char Sname[20];
		char Ssex;
		int Sage;
		char addr[30];
		struct Date birthday;
		struct Date enrollday;
	} a = {81000,"Chris",'M',21,"King Road 21st",{9,21,1998},{9,1,2016}}; //内部大括号不一定需要，会对应赋值
	printf("NO:%d,name:%s,sex:%c,age:%d,addr:%s,birthday:%d.%d,%d,enrollday:%d.%d,%d\n",a.Sno,a.Sname,a.Ssex,a.Sage,a.addr,a.birthday.month, a.birthday.day, a.birthday.year,a.enrollday.month, a.enrollday.day, a.enrollday.year);
	a.Sage = 22;
	printf("NO:%ld,name:%s,sex:%c,age:%d,addr:%s\n", a.Sno, a.Sname, a.Ssex, a.Sage, a.addr);
	return 0;
}

//书P299 例9.2
int practice2()
{
	struct Student
	{
		int num;
		char name[20];
		float score;
	}student1 ,student2;

	printf("Please input two students' numbers, names and scores:\n");
	scanf("%d%s%f", &student1.num, student1.name, &student1.score);
	getchar();//顶替回车
	scanf("%d%s%f", &student2.num, student2.name, &student2.score);
	getchar();


	if (student1.score == student2.score)
	{
		printf("The two students have got the same scores\n");
		printf("%d%6s%6.2f\n", student1.num, student1.name, student1.score);
		printf("%d%6s%6.2f\n", student2.num, student2.name, student2.score);
	}
	else 
	{
		printf("The one who has the higher score is : \n");
		if (student1.score < student2.score)
		{
			student1 = student2;

		}
		printf("%d%6s%6.2f\n", student1.num, student1.name, student1.score);
	}
	return 0;
}

int main()
{	
	practice1();
	printf("\n");
	//practice2();
	printf("\n");
	getchar();
	return 0;
}
