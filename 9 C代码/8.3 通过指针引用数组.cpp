#include<stdio.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

//ָ���ָ��/��ֵp=a <=> p=&a[0]; 
//ָ�������ļӼ�������ͨ��ָ����������*(p+i) = *(a+i) = a[i]��ʵ����Ҳ�ȼ���p[i]����Ϊp[i]�ᱻ�����*(p+i)����Ҫע��pָ��ָ��ڼ���Ԫ�أ�a��Զָ���һ��Ԫ�ء������P236��2��
//ָ��֮��ļ����㣬������ָ�����p0��p��ָ��ͬһԪ�飬�����ָԪ�ص���Ծ���
int prac1()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *p = a; //�ȼ���int *p=&a[0];
	int *p0 = &a[9];
	printf("The First Element is: %d\n", *p);

	p++; //ʵ����˼��(p+1)*d��pָ��Ļ�������int����������d=4��
	printf("The Second Element is: %d\n", *p); 

	printf("The Second Element is: %d\n", *(a + 1)); //a��Զ��ʾ��һ��Ԫ�صĵ�ַ.ʵ����aҲ�����Լӻ��Լ���not a++, a+=1
	printf("The Third Element is: %d\n", *(a + 2));

	printf("The Fourth Element is: %d\n", *(p + 2)); //p�ղ�ָ��ڶ���Ԫ�ء�(p+2)*d = (&a[1]+2)*d

	printf("Now, the Gap between p0 and p is %d", p0 - p); //��ָԪ�ص���Ծ���=8
	return 0;
}

//scanf: &a[i]; a+i; p+i
//printf: p++, p; a[i]; *(a+i); *(p++)
int prac2()
{
	int a[10];
	int *p = a;
	printf("Please Enter 10 Number:");
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
		//scanf("%d",a+i);
		//scanf("%d",p+i); //�������д��룬�������forѭ���б�������p=a����Ϊ��ʱp��ָ�����һ��Ԫ��
	getchar();

	printf("Here are the Numbers:\n");
	for (; p < (a + 10); p++)
		printf("%d ", *p); //ȡp��ֵ����p++��Ȼ���ж�p < (a + 10)
	printf("\n");

	printf("Print the Numbers at Second Time:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ",a[i]);
	printf("\n");

	printf("Print the Numbers at Third Time:\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", *(a+i)); //����a++������Ҫ����i
	printf("\n");

	printf("Print the Numbers at Fourth Time:\n");
	p = a;
	for (int i = 0; i < 10; i++)
		printf("%d ", *p++); //�������������ֵ��֪���ȼ���*(p++), ��ȡpֵ����p++
	printf("\n");

	return 0;
}


int main()
{
	prac1();
	printf("\n");
	prac2();
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