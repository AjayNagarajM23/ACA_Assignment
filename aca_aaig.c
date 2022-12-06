#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1000000
char num[SIZE][8];
int comp[SIZE];

void sort()
{
	int i, j;
	FILE *fp4 = fopen("sorted.txt", "a+");
	int temp;
	printf("Progress:\e[s");
	for (i = 0; i < SIZE - 1; i++)
	{
		float pct = ((float)i / SIZE) * 100;
		printf("%2d (%3f%%)\e[u", i, pct);
		fflush(stdout);
		for (j = 0; j < SIZE - i - 1; j++)
		{
			if (comp[j + 1] < comp[j])
			{
				temp = comp[j];
				comp[j] = comp[j + 1];
				comp[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
		fprintf(fp4, "%d\n", comp[i]);

	printf("\n The file is sorted successfully and saved as sorted.txt.\n");
	fclose(fp4);
}

int main()
{
	FILE *fp;
	int count = 0;
	char ch;

	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("\n Cannot open the file \n");
		exit(0);
	}
	else
		printf("File opened sucessfully..\n");

	for (int i = 0; i < SIZE; i++)
	{
		fscanf(fp, "%s ", num[i]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		comp[i] = atoi(num[i]);
	}

	clock_t t;
	t = clock();
	sort();
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

	printf("Sorting took %f seconds to execute \n", time_taken);
}