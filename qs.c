#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lengthofarray(x) (sizeof((x))/sizeof((x[0])))
//����
/*
	��֤����ǰ��ѭ��{
		ȡ��һ�������������2�ʼ�����Ƚϣ�
		��ľͷ�������һ��������ǰһ��
	Ȼ�����ߺ��ұ߷ֱ�ִ����ȥ
	ֱ������ֻʣ1���� 
	} 
*/
int ranint(const int a,const int b){
	//����[a,b]��һ���������
	return (rand()%(b-a+1)+a);
}

void quicksort(double *input_array, const int begin, const int last) {//�����Ϳ����㷨
	/*����init����[aԪ��~1+bԪ��]����		��ʵ����j+1
	���a[i]~[j]������Ҫquicksort(a,i,j+1);*/
	if (begin >= last)
		return;
	int len = last - begin;
	int track = begin;
	double* big = (double*)calloc(len, sizeof(double));
	double* small = (double*)calloc(len, sizeof(double));
	int s_big = 0, s_small = 0;
	for (int cont = begin + 1; cont < last; cont++) {//��unsigned short���ܻ�������
		if (input_array[cont] > input_array[begin]) {//L0
			big[s_big++] = input_array[cont];//�ϲ��������Լ�
		}
		else {
			small[s_small++] = input_array[cont];
		}
	}
	track = s_small + begin;//��¼,��ʼ�Ļ�׼λ��ǡ�ñ��ƶ���s_small�� 
	input_array[track] = input_array[begin];//���������s_smallԪ�ظպþ��Ǹ�����small����֮��һ��Ԫ�� 
	for (int cont = begin, copy = 0; cont < track; cont++, copy++)
		input_array[cont] = small[copy];//������������ 
	for (int cont = (1 + track), copy = 0; cont < last; cont++, copy++)
		input_array[cont] = big[copy];
	//	printf("begin = %d \t last = %d \t track = %d\n",begin,last,track);//debug
	free(big);
	free(small);
	quicksort(input_array, begin, track);//����߿�ʼ
	quicksort(input_array, track + 1, last);//��һ�����������ұ߿�ʼ
	return;
}

int main(void) {
	int num;
	printf("������������ݵĸ�����\n");
	scanf("%d", &num);
	double* a = (double*)calloc(num, sizeof(double));//��������
	printf("������������ݣ�\n");
	srand((int)time(0));
	for(int cont = 0;cont < num; cont++){
		printf("��%d����=", cont + 1);
		scanf("%lf", &a[cont]);
	}
	quicksort(a, 0, num);
	printf("\n�õ������\n");
	//������ 
	for (int cont = 0; cont < num; cont++) {
		printf("%g ", a[cont]);
	}
	free(a);
	return 0;
}
