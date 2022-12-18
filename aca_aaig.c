#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void sort(int val, int number[])
{
	int i, j;
	int temp;
	for (i = 0; i < val - 1; i++)
	{
		for (j = 0; j < val - i - 1; j++)
		{
			if (number[j + 1] < number[j])
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}

void random_gen(int val, int number[])
{
	for (int i = 0; i < val; i++)
	{
		number[i] = rand();
	}
}

int main(int argc, char **argv)
{
	int val = atoi(argv[1]);
	
	int* number = (int*)malloc(val*sizeof(int));
	
	random_gen(val, number);

	clock_t t;

	t = clock();
	sort(val, number);
	t = clock() - t;

	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("%f\n", time_taken);

	FILE *fp = fopen("result.txt","a+");
	fprintf(fp,"Number Of Integers : %d\t\t Time Taken For Execuation : %f\n",val,time_taken);
}