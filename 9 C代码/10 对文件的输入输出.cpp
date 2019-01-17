# include<stdio.h>
#pragma warning(disable:4996)
int prac1();
int prac2();
int prac3();
int prac4();
int prac5();
int prac6();

void Save() {
	FILE *fp;
	int i;
	char Number[100];
	fp = fopen("Record.txt", "w");
	if (fp == NULL) {
		printf("File cannot open!");   //保存失败时要有提示，方便进行相关处理 
	}
	for (i = 0; i < 10; i++)
	{
		if (ta[i].T_name[0] != '\0') {  	//判断内容是否为空，空的时候则不记录 
			sprintf(Number, "%s %d %d %s %s", ta[i].T_name, ta[i].T_ID, ta[i].D_ID, ta[i].D_name, ta[i].School);
			fprintf(fp, "%s\n", Number);
		}

	}
	fclose(fp);
}

bool Load() {
	FILE *fp;
	fp = fopen("Record.txt", "r");
	if (!fp)
	{
		printf("No record\n");
		return false;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s", ta[j].T_name);
		fscanf(fp, "%s", &ta[j].T_ID);
		fscanf(fp, "%s", &ta[j].D_ID);
		fscanf(fp, "%s", ta[j].D_name);
		fscanf(fp, "%s", ta[j].School);
		if (ta[j].T_name[0] != '\0') {
			printf("T_name=%s T_ID=%d D_ID=%d D_name=%s S=%s\n", ta[j].T_name, ta[j].T_ID, ta[j].D_ID, ta[j].D_name, ta[j].School);
			printf("\n");
			j++;
		}
	}
	printf("\n");
	fclose(fp);
	return true;
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