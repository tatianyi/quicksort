#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lengthofarray(x) (sizeof((x))/sizeof((x[0])))
//快排
/*
	验证结束前，循环{
		取第一个数，从数组第2项开始与它比较，
		大的就放在它后一项，否则放在前一项
	然后从左边和右边分别执行下去
	直到区间只剩1个数 
	} 
*/
int ranint(const int a,const int b){
	//生成[a,b]中一个随机整数
	return (rand()%(b-a+1)+a);
}

void quicksort(double *input_array, const int begin, const int last) {//迭代型快排算法
	/*对于init数组[a元素~1+b元素]排序		↓实测是j+1
	如对a[i]~[j]排序则要quicksort(a,i,j+1);*/
	if (begin >= last)
		return;
	int len = last - begin;
	int track = begin;
	double* big = (double*)calloc(len, sizeof(double));
	double* small = (double*)calloc(len, sizeof(double));
	int s_big = 0, s_small = 0;
	for (int cont = begin + 1; cont < last; cont++) {//用unsigned short可能会带来溢出
		if (input_array[cont] > input_array[begin]) {//L0
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
	free(big);
	free(small);
	quicksort(input_array, begin, track);//从左边开始
	quicksort(input_array, track + 1, last);//上一步结束，从右边开始
	return;
}

int main(void) {
	int num;
	printf("输入待排序数据的个数：\n");
	scanf("%d", &num);
	double* a = (double*)calloc(num, sizeof(double));//输入数组
	printf("输入待排序数据：\n");
	srand((int)time(0));
	for(int cont = 0;cont < num; cont++){
		printf("第%d个数=", cont + 1);
		scanf("%lf", &a[cont]);
	}
	quicksort(a, 0, num);
	printf("\n得到结果：\n");
	//输出结果 
	for (int cont = 0; cont < num; cont++) {
		printf("%g ", a[cont]);
	}
	free(a);
	return 0;
}
