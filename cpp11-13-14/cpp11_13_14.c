#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>


int main(int argc, char* argv[]) {
	//这里需要注意的是：参数开始的下标为1，0是程序的名称
	double a = atof(argv[1]);
	int b = atoi(argv[2]);
	double ret = pow(a, b);
	printf("%f %d %f", a, b, ret);
	return 0;
}