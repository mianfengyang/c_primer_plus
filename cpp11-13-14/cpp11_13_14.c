#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>


int main(int argc, char* argv[]) {
	//������Ҫע����ǣ�������ʼ���±�Ϊ1��0�ǳ��������
	double a = atof(argv[1]);
	int b = atoi(argv[2]);
	double ret = pow(a, b);
	printf("%f %d %f", a, b, ret);
	return 0;
}