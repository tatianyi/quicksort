#include <stdio.h>
#include <stdlib.h>

#define MODE 2

void fswap(double* a, double* b)//���ڸ���������ֵ����
{
	double t = *a;
	*a = *b, * b = t;
	return;
}

//����
void fqsort(double* input_array, const long begin, const long last)//���������������±�begin���±�last
{
#if MODE == 1//��
	if (last <= begin)//��λ���
		return;
	/*double* big = (double*)calloc(len, sizeof(double));
	double* small = (double*)calloc(len, sizeof(double));*/
	double* big = (double*)_alloca(len, sizeof(double));
	double* small = (double*)_alloca(len, sizeof(double));
	int s_big = 0, s_small = 0;
	for (int cont = begin + 1; cont < last; cont++) {//��unsigned short���ܻ�������
		if (input_array[cont] > input_array[begin]) {
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
	//free(big);
	//free(small);
	fqsort(input_array, begin, track);//���и�λ����߿�ʼ
	fqsort(input_array, track + 1, last);//��һ�����������ұ߿�ʼ
	const unsigned long len = last - begin;//����
	unsigned long track = begin;// ranint(begin, last);//���ѡһ���ָ��
	double temp;
#else
	long track = (begin + last) >> 1;//len��2
	long i = begin, j = last;
	double p = input_array[track];//���Ƚ�
	while (i <= j)//˫��ɨ
	{
		while (input_array[i] < p)
			++i;
		while (input_array[j] > p)
			--j;
		if (i <= j)//��ֹ��;���غ�
			fswap(&input_array[i++], &input_array[j--]);//������ͬʱ�����ƶ�
	}
	if (j > begin)
		fqsort(input_array, begin, j);//��
	if (i < last)
		fqsort(input_array, i, last);//��
#endif
}

int main(void) 
{
	unsigned num;
	srand(time(0));
	puts("������������ݵĸ�����");
	scanf("%u", &num);
	double* a = (double*)_alloca(num * sizeof(double));//��������
	puts("������������ݣ�");
	for(int cont = 0;cont < num; cont++)
	{
		printf("��%d����=", cont + 1);
		scanf("%lf", &a[cont]);
	}
	fqsort(a, 0, num - 1);//��������������
	printf("\n�õ������\n");
	//������ 
	for (int cont = 0; cont < num; cont++)
	{
		printf("%g ", a[cont]);
	}
	//free(a);
	return 0;
}
