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
	char job;				//struct��Ա����š��������Ա�ְҵ
	union
	{
		int clas;
		char position[10];		//union��Ա���༶��ְ��
	}category;              //struct��Աcategory�ǹ��������
}person[2];                 //����ṹ������person����2��Ԫ��

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

//��P319 9.5.3��2��
int practice1()
{
	union Date a;
	a.i = 97;
	printf("%d\n", a.i);
	printf("%c\n", a.ch);
	printf("%f\n", a.f);//�������ĸ���Ա���洢�Ķ���97
	printf("\n");

	a.ch = 'a';
	a.f = 1.5;
	a.i = 40;
	printf("%d\n", a.i); //40��%d���
	printf("%c\n", a.ch); //40��%char�����ԭ����a.ch = 'a'��������
	printf("\n");

	printf("%o\n%o\n%o\n", &a.i, &a.ch, &a.f);//�������ĸ���Ա�����ַ����һ����
	printf("\n");
	return 0;
}

//��P321 ��9.11
int practice2()
{
	for (int i = 0; i < 2; i++) //ѭ��i�Σ�����i����ʦ/��ʦ
	{
		printf("Please enter the data of person,\ninclude his number,name,sex,job\n");
		scanf("%d %s %c %c", &person[i].num, &person[i].name, &person[i].sex, &person[i].job);//����ǰ4��
		getchar();
		if (person[i].job == 's')
		{
			printf("So he is a student,please enter his class:\n");
			scanf("%d", &person[i].category.clas);//�����ѧ����������༶
			getchar();
		}
		else if (person[i].job == 't')
		{
			printf("So he is a teacher,please enter his position:\n");
			scanf("%s", &person[i].category.position);//����ǽ�ʦ��������ְ��
			getchar();
		}
		else printf("Input error!");
	}
	printf("\n");
	printf("No.    Name      Sex Job Class/Position\n");
	for (int i = 0; i < 2; i++) //ѭ��i�Σ����i����ʦ/��ʦ
	{
		if (person[i].job == 's') //����ѧ��
			printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.clas);
		else  //���ǽ�ʦ
			printf("%-6d%-10s%-4c%-4c%-10s\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.position);
	}
	return 0;
}
