#include<stdio.h>
int main()
{
	int row = 0, col = 0, i, j, max = 0;
	int a[3][4] = { {1,2,3,4},{9,8,7,6},{-10,-15 ,-5,2} };
	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			if (a[i][j] > max)
			{
				max = a[i][j];
				row = i;
				col = j;
			}
	printf("The max is %d ,which is in row %d and column %d", max, row, col);
	getchar();
	return 0;
}