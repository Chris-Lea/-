#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();

int main()
{
	prac1();
	prac2();
	prac3();
	getchar();
}

int prac1()
{
	int c[10] = { 65,66,67,92 };
	c[0] = 'a';
	char a[100] = "I am so happy right now";
	printf("%o\n", a);//�ð˽��Ƶ���ʽ�������a����ʼλ��
	printf("%o\n", a[0]);
	printf("%o\n", a[1]);

	printf("%s\n", c);//���a
	printf("%d\n", c);//���7λ�������
	printf("%s\n", a);//���I am so happy right now
	printf("%d\n", a);//���7λ�������
	printf("%c\n", a);//�����
	printf("\n\n");
	return 0;
}
int prac2()
{
	char diamond[][5] = { {' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{ ' ','*',' ','*' },{ ' ',' ','*' } };
	
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", diamond[i]);//��%s��һ���д�ӡ
		puts(diamond[i]);//puts(str)����ַ���˵
	}

	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%c", diamond[i][j]);//��%c��һ������ӡ��%s��������һ������ӡ
		printf("\n");
	}
	printf("\n\n");
	return 0;
}

int prac3()
{	
	//string catenate
	char str1[40] = "People of Republic of ";
	char str2[] = "China";
	strcat(str1, str2);
	printf("%s\n", str1);

	//string copy
	char str3[10];
	strcpy(str3, str2);
	printf("%s\n", str3);
	strncpy(str3, str2, 3);
	printf("%s\n", str3);

	//string compare
	printf("%d\n", strcmp(str1, str2)); 
	printf("%d\n", strcmp("A", "B")); 
	printf("%d\n", strcmp("a", "A")); 
	printf("%d\n", strcmp("Z", "Z"));

	//string length
	printf("%d\n", strlen(str1));
	printf("%d\n", strlen("pig")); 


	//string lowercase
	//string uppercase
	strlwr("DOG");
	strupr(str1);
	printf("\n");
	return 0;
}