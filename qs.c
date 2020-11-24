#include <stdio.h>
#include <stdlib.h>

#define MODE 2

void fswap(double* a, double* b)//对于浮点数的数值交换
{
	double t = *a;
	*a = *b, * b = t;
	return;
}

//快排
void fqsort(double* input_array, const long begin, const long last)//传入数组名，从下标begin到下标last
{
#if MODE == 1//旧
	if (last <= begin)//首位相接
		return;
	/*double* big = (double*)calloc(len, sizeof(double));
	double* small = (double*)calloc(len, sizeof(double));*/
	double* big = (double*)_alloca(len, sizeof(double));
	double* small = (double*)_alloca(len, sizeof(double));
	int s_big = 0, s_small = 0;
	for (int cont = begin + 1; cont < last; cont++) {//用unsigned short可能会带来溢出
		if (input_array[cont] > input_array[begin]) {
			big[s_big++] = input_array[cont];//合并复制与自加
		}
		else {
			small[s_small++] = input_array[cont];
		}
	}
	track = s_small + begin;//记录,开始的基准位置恰好被移动了s_small下 
	input_array[track] = input_array[begin];//并且数组第s_small元素刚好就是复制完small数组之后一个元素 
	for (int cont = begin, copy = 0; cont < track; cont++, copy++)
		input_array[cont] = small[copy];//重新整理数组 
	for (int cont = (1 + track), copy = 0; cont < last; cont++, copy++)
		input_array[cont] = big[copy];
	//	printf("begin = %d \t last = %d \t track = %d\n",begin,last,track);//debug
	//free(big);
	//free(small);
	fqsort(input_array, begin, track);//从切割位点左边开始
	fqsort(input_array, track + 1, last);//上一步结束，从右边开始
	const unsigned long len = last - begin;//长度
	unsigned long track = begin;// ranint(begin, last);//随便选一个分割点
	double temp;
#else
	long track = (begin + last) >> 1;//len÷2
	long i = begin, j = last;
	double p = input_array[track];//待比较
	while (i <= j)//双向扫
	{
		while (input_array[i] < p)
			++i;
		while (input_array[j] > p)
			--j;
		if (i <= j)//防止中途就重合
			fswap(&input_array[i++], &input_array[j--]);//交换完同时继续移动
	}
	if (j > begin)
		fqsort(input_array, begin, j);//左
	if (i < last)
		fqsort(input_array, i, last);//右
#endif
}

int main(void) 
{
	unsigned num;
	srand(time(0));
	puts("输入待排序数据的个数：");
	scanf("%u", &num);
	double* a = (double*)_alloca(num * sizeof(double));//输入数组
	puts("输入待排序数据：");
	for(int cont = 0;cont < num; cont++)
	{
		printf("第%d个数=", cont + 1);
		scanf("%lf", &a[cont]);
	}
	fqsort(a, 0, num - 1);//对整个数组排序
	printf("\n得到结果：\n");
	//输出结果 
	for (int cont = 0; cont < num; cont++)
	{
		printf("%g ", a[cont]);
	}
	//free(a);
	return 0;
}
