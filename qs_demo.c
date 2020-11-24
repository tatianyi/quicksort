#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define num 1024

double a[num];

int ranshort(const int a, const int b)
{
	return (rand() % (b - a + 1) + a);
}

void fswap(double* a, double* b)
{
	double t = *a;
	*a = *b, * b = t;
	return;
}

void fqsort(double input_array[], const long begin, const long last)
{
	long track = (begin + last) >> 1;
	long i = begin, j = last;
	double p = input_array[track];
	while (i <= j)
	{
		while (input_array[i] < p)
			++i;
		while (input_array[j] > p)
			--j;
		if (i <= j)
			fswap(&input_array[i++], &input_array[j--]);
	}
	if (j > begin)
		fqsort(input_array, begin, j);
	if (i < last)
		fqsort(input_array, i, last);
}

int main(void) 
{
	srand(time(0));
	puts("待排序数据：");
	for (int cont = 0; cont < num; cont++)
	{
		a[cont] = ranshort(0, 32767);
		printf("%g ", a[cont]);
	}
	fqsort(a, 0, num - 1);
	printf("\n得到结果：\n");
	for (int cont = 0; cont < num; cont++)
	{
		printf("%g ", a[cont]);
	}
	return 0;
}
