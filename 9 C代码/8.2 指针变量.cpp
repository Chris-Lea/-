#include<stdio.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//����ָ���ͱ���
int prac1()
{
	int a = 1, b = 2;
	int *a_pointer, *b_pointer;
	a_pointer = &a; b_pointer = &b;
	//*a_pointer = a; *b_pointer = b; //��ӷ���
	//Error:ʹ����δ��ʼ���ľֲ���������Ϊ���ޣ�a_pointer = &a; b_pointer = &b;����ָ��δָ���κα�������δ��ֵ
	//����Ҫ��ָ��������г�ʼ������int *a_pointer = &a, *b_pointer = &b;���prac2();
	//���Կ���
	/*
	a_pointer = &a; b_pointer = &b;
	*a_pointer = b; *b_pointer = a;
	*/
	printf("a=%d, b=%d\n", a, b);
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	printf("&a=%o\n", &a); //�˽��������ַ
	printf("a_pointer=%o\n", &*a_pointer); //�˽��������ַ
	return 0;
}

//��ʼ��
int prac2()
{
	int a = 1, b = 2;
	int * a_pointer = &a, * b_pointer = &b;
	//����ĳ�ʼ���С�int *��һ���֣�������������ָ��int(������)��ָ���ͱ�����a_pointer = &a����һ���֣�������ʼ����
	printf("a=%d, b=%d\n", a, b);
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	return 0;
}

//��Ӹ�ֵ *a_pointer=1
int prac3()
{
	int a , b ;
	int *a_pointer, *b_pointer;
	a_pointer = &a; b_pointer = &b;
	*a_pointer = 1, *b_pointer = 2; //*  ָ��������򡰼�ӷ��ʡ������
	printf("a=%d, b=%d\n", a, b); 
	printf("*a_pointer=%d, *b_pointer=%d\n", *a_pointer, *b_pointer);
	return 0;
}

//�ȴ�С����ָ�������ֵ
//scanf����p1Ҳ�У�&a��
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

//ָ�������Ϊ������������������p���β���p�����ں����ڲ���*p���н���������ֵ�ĵ��򴫵���Ҳ�����ֵ�Ľ�����
//���ڵ��򴫵��У�����return�����Ա�������a������ָ���������p�����б任����ʵ���޶����ԡ�����P228���Ϻ���8.4
int prac5()
{
	int swap(int *p1, int *p2); //��������sqap����������������Ҫ�õ��ı���
	int a, b, *p1, *p2; //����prac5�����ľֲ�����
	p1 = &a; p2 = &b;
	printf("Please Enter Two Number;\n");
	scanf("%d %d", p1, p2);
	getchar();
	printf("&a=%o\n&b=%o\n", &a,&b); 
	if (a < b)
		swap(p1, p2);
	printf("a=%d,b=%d\n", a, b);
	printf("max=%d, min=%d\n", *p1, *p2);
	printf("&a=%o\n&b=%o", &a, &b);//ʵ��������a��b��ֵ�����ˣ�����a��b�ĵ�ַδ��
	return 0;
}

//��������*p
int swap(int *p1, int *p2)
{
	int  temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	return 0;
}

//����ֵ�ȴ�С
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

//��*p1,*p2,*p3ʵ�ִӴ�С������
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