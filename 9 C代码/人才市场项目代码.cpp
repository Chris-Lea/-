/*
李艺钧
20160782280
16级信管
*/

#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

#define N 20
struct Person
{
	int no;
	char name[20];
	int major_no;
	char major_name[10];
	char school[20];
};
struct Person student[20], *p = student;

struct Major
{
	char major_name[20];
	int major_no;
} major[9] = { "Economy",0, "Management",1, "Chemistry",2, "Physics",3, "Math",4, "Education",5, "Computer",6, "Music",7, "P.E.",8 };

int input(struct Person student[]);
int output();
int person_no = 0;
int correct();

int input(struct Person student[])
{
	int key_in = 1;
	int get_num();
	printf("\nMajor list: \nEconomy:0 \nManagement:1 \nChemistry:2 \nPhysics:3 \nMath:4 \nEducation:5 \nComputer:6 \nMusic:7 \nP.E.:8 \n");
	while (key_in)
	{
		printf("\n");
		printf("Please enter one's pesonal information:\n");
		//printf("Back:0\n");
		printf("|Name     |Major No.     |Major Name     |Graduated School|\n");
		scanf("%s%d%s%s", &student[person_no].name, &student[person_no].major_no, &student[person_no].major_name, &student[person_no].school);
		getchar();
		//student[person_no].no = person_no+1;
		student[person_no].no = get_num();
		printf("Enter completed. His Personal number is %d.\n", student[person_no].no);
		person_no++;
		printf("\n");

		printf("Would you like to continue to enter personal information?\n");
		printf("Enter 1: Continue.\n");
		printf("Enter 0: Come Back.\n");
		scanf("%d", &key_in);
		switch (key_in)
		{
		case 1:continue; break;
		case 0:return 0; break;
		default:printf("Input Error, please enter a number again.\n\n");
			continue;
		}
	}
}

int get_num()
{
	int num = 1;
	int comparison(int num);
	while (comparison(num) == 0)
		num++;
	return num;
}

int comparison(int num)
{
	for (int i = 0; i < N; i++)
	{
		if (num == student[i].no)
			return 0;
	}
	return 1;
}

int output()
{
	int output_no();
	int output_name();
	int output_major_number();
	int output_major_name();
	int output_school();

	int key_out = 21;
	while (key_out != 0)
	{
		printf("\n");
		printf("How do you want to search a man:\n");
		printf("Enter 21:Search by personal number \n");
		printf("Enter 22:Search by personal name \n");
		printf("Enter 23:Search by major number\n");
		printf("Enter 24:Search by major name\n");
		printf("Enter 25:Search by graduated school\n");
		printf("Enter 0 :Back\n");

		scanf("%d", &key_out);
		switch (key_out)
		{
		case 21:output_no(); break;
		case 22:output_name(); break;
		case 23:output_major_number(); break;
		case 24:output_major_name(); break;
		case 25:output_school(); break;
		case 0:return 0;
		default:printf("Input Error, please enter a number again.\n\n");
			break;
		}
	}
	printf("\n");
	return 0;
}

int output_no()
{
	int number, key0;
	//char character;
	//char category[5][20] = { "number","name","major number","major name","graduated school" };
	printf("\n");
	printf("Please enter his number:");
	scanf("%d", &number);
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	for (int i = 0; i < N; i++)
	{
		if (number == student[i].no)
		{
			printf(" %-8d%-9s%-13d%-15s%-s\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
		}
	}
	printf("Enter 1:Correct the information \n");
	printf("Enter 0:Come back last option \n");
	scanf("%d", &key0);
	switch (key0)
	{
	case 1:correct(); break;
	case 0:return 0; break;
	default:printf("Input Error, please enter a number again.\n\n");
		break;
	}
}
int output_name()
{
	//int number;
	int key0;
	char character[20];
	//char category[5][20] = { "number","name","major number","major name","graduated school" };
	printf("\n");
	printf("Please enter his name:");
	scanf("%s", character);
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	for (int i = 0; i < N; i++)
	{
		if (strcmp(character, student[i].name) == 0)
		{
			printf(" %-8d%-9s%-13d%-15s%-s\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
		}
	}
	printf("Enter 1:Correct the information \n");
	printf("Enter 0:Come back last option \n");
	scanf("%d", &key0);
	switch (key0)
	{
	case 1:correct(); break;
	case 0:return 0; break;
	default:printf("Input Error, please enter a number again.\n\n");
		break;
	}
}
int output_major_number()
{
	int number, key0;
	//char character;
	//char category[5][20] = { "number","name","major number","major name","graduated school" };
	printf("\n");
	printf("Please enter his major number:");
	scanf("%d", &number);
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	for (int i = 0; i < N; i++)
	{
		if (number == student[i].major_no)
		{
			printf(" %-8d%-9s%-13d%-15s%-s\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
		}
	}
	printf("Enter 1:Correct the information \n");
	printf("Enter 0:Come back last option \n");
	scanf("%d", &key0);
	switch (key0)
	{
	case 1:correct(); break;
	case 0:return 0; break;
	default:printf("Input Error, please enter a number again.\n\n");
		break;
	}
}
int output_major_name()
{
	int key0;
	char character[20];
	//char category[5][20] = { "number","name","major number","major name","graduated school" };
	printf("\n");
	printf("Please enter his major name:");
	scanf("%s", character);
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	for (int i = 0; i < N; i++)
	{
		if (strcmp(character, student[i].major_name) == 0)
		{
			printf(" %-8d%-9s%-13d%-15s%-s\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
		}
	}
	printf("Enter 1:Correct the information \n");
	printf("Enter 0:Come back last option \n");
	scanf("%d", &key0);
	switch (key0)
	{
	case 1:correct(); break;
	case 0:return 0; break;
	default:
		break;
	}
}
int output_school()
{
	int key0;
	char character[20];
	//char category[5][20] = { "number","name","major number","major name","graduated school" };
	printf("\n");
	printf("Please enter his graduated school:");
	scanf("%s", character);
	getchar();
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	for (int i = 0; i < N; i++)
	{
		if (strcmp(character, student[i].school) == 0)
		{
			printf(" %-8d%-9s%-13d%-15s%-s\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
		}
	}
	printf("Enter 1:Correct the information \n");
	printf("Enter 0:Come back last option \n");
	scanf("%d", &key0);
	switch (key0)
	{
	case 1:correct(); break;
	case 0:return 0; break;
	default:printf("Input Error, please enter a number again.\n\n");
		break;
	}
}

int correct()
{
	int number, i, key_cor;
	int correct_no(int o);
	printf("\n");
	printf("Please enter the personal number which you want to correct:");
	scanf("%d", &number);
	printf("His original information is :\n");
	for (i = 0; i < N; i++)
	{
		if (number == student[i].no)
		{
			printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
			printf(" %-8d%-9s%-13d%-15s%-s\n\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
			break;
		}
	}

	printf("Which one do you want to correct:\n");
	printf("Enter 1:Personal Number\n");
	printf("Enter 2:Personal Name\n");
	printf("Enter 3:Major Number\n");
	printf("Enter 4:Major Name\n");
	printf("Enter 5:Graduated School\n");
	printf("Enter 0:Cancel\n");
	scanf("%d", &key_cor);
	getchar();
	switch (key_cor)
	{
	case 1:
		printf("Please enter the new Personal Number:\n");
		student[i].no = correct_no(i);
		break;
	case 2:
		printf("Please enter the new Personal Name:\n");
		scanf("%s", &student[i].name); 
		break;
	case 3:
		printf("Please enter the new Major Number:\n");
		scanf("%d", &student[i].major_no); 
		break;
	case 4:
		printf("Please enter the new Major Name:\n");
		scanf("%s", &student[i].major_name); 
		break;
	case 5:
		printf("Please enter the new Graduated School:\n");
		scanf("%s", &student[i].school); 
		break;
	case 0:
		return 0; 
		break;
	default:
		printf("Input Error, please enter a number again.\n\n");
		break;
	}
	printf("\nHis new information is :\n");
	printf("|NO.   |Name    |Major No.   |Major Name    |Graduated School\n");
	printf(" %-8d%-9s%-13d%-15s%-s\n\n", student[i].no, student[i].name, student[i].major_no, student[i].major_name, student[i].school);
	printf("Correction completes. Come back to the last option\n");
}

int correct_no(int o)
{
	int no;
	scanf("%d", &no);
	for (int i = 0; i < N; i++)
	{
		if (no == student[i].no)
		{
			printf("The Personal Number %d is existed.\n\nPlease enter a new Personal Number again:\n", student[i].no);
			no = correct_no(o);
			break;
		}
	}
	return no;
}
int main()
{
	printf("Welcome to the information system of talent market:\n");
	int key = 1;
	while (key != 0)
	{
		printf("\n");
		printf("This Is The Major Menu.\n");
		printf("Enter 1 :Enter Information.\n");
		printf("Enter 2 :Search And Correct.\n");
		printf("Enter 3 :Only Correct.\n");
		printf("Enter 0 :Exit\n");
		scanf("%d", &key);
		getchar();
		switch (key)
		{
		case 1:input(p); break;
		case 2:output(); break;
		case 3:correct(); break;
		case 0:break; break;
		default:printf("Input Error, please enter a number again.\n\n");
			break;
		}
	}
	return 0;
}