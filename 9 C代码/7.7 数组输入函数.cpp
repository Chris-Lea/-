#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
#define z 5;


//����10������������ֵ.&& ����Ԫ����Ϊʵ��
int prac1()
{
	int max(int x, int y); //�������β�
	int a[10], i, m, n;
	printf("Please enter 10 numbers:");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	getchar();
	for (i = 1, m = a[0], n = 0; i < 10; i++) //��forѭ��������i,m,n��ֻ����i�����У�ԭ����
	{
		if (max(m, a[i]) > m) //����Ԫ����Ϊʵ��
		{
			m = max(m, a[i]); //����Ԫ����Ϊʵ��
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

//��һ����ѧ���ĳɼ�ƽ������//���������βΣ���������ʵ��
int prac2()
{
	float average(float score[10]); //���������β�
	float score[10], aver;
	printf("Please enter scores of ten students:\n");
	for (int i = 0; i < 10; i++)
		scanf("%f", &score[i]);
	getchar();
	aver = average(score); //��������ʵ��
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

//��������ѧ���ĳɼ�ƽ����
int prac3()
{
	float score1[] = { 98.5,97,91.5,60,55 };
	float score2[] = { 67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5 };
	float average(float score[], int n);
	float aver1, aver2;

	aver1 = average(score1,5);
	aver2 = average(score2,10); //����������
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

//��ѡ�����򷨶������Ԫ�ؽ�������
int prac4()
{
	return 0;
}
int sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n-1; i++)
	{
		k = i; //��¼˳����
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[k])
				k = j; // i������Ԫ�رȽϣ��ҳ���С��j������k�ϡ�//��ʹk��j�����˽�������array[k]һֱ������������array[i]
		}
		t = array[k]; array[k] = array[i]; array[i] = t; //k��i����
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