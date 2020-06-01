
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


//10.13-2
void copy_arr(target1, source, length);
void copy_ptr(target2, source, length);
void copy_ptrs(target3, source, length);

void cpp10_13_2() {
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[5];
	double target2[5];
	double target3[5];
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	for (int i = 0; i < 5; i++) {
		printf("target2[%d] = %.1f \n", i, target2[i]);
	}
	copy_ptrs(target3, source, source + 5);
}

void copy_arr(double target1[], double source[], int length) {
	for (int i = 0; i < length; i++) {
		target1[i] = source[i];
	}
	for (int i = 0; i < length; i++) {
		printf("target1[%d] = %.1f\n", i, target1[i]);
	}
}

void copy_ptr(double *target2, double *source, int length) {
	for (int i = 0; i < length; i++) {
		*(target2+i) = *(source+i);
	}
	
}

void copy_ptrs(double *target3, double *source, double *source_last) {
	for (int i = 4; i >= 0; i--) {
		*(target3+i) = *(source_last-1);
		source_last--;
	}
	for (int i = 0; i < 5; i++) {
		printf("target3[%d] = %.1f\n", i, *(target3 + i));
	}
}

//10.13-3
int get_max(int *num, int len) {
	int *temp = num;
	for (int i = 0; i < len; i++) {
		if (*temp < * (num + i)) {
			*temp = *(num + i);
		}
	}
	return *temp;
}
void cpp10_13_3() {
	int number[5] = { 10,20,10,30,8 };
	int res = get_max(number,5);
	printf("最大值是：%d", res);
}

//10.13-4
int get_max_index(double* num, int len) {
	double* temp = num;
	int index = 0;
	for (int i = 0; i < len; i++) {
		if (*temp < *(num + i)) {
			*temp = *(num + i);
			index = i;
		}
	}
	return index;
}
void cpp10_13_4() {
	double number[5] = { 100.1,20.2,10.3,30.9,8.9 };
	int res = get_max_index(number, 5);
	printf("最大值下标为：%d", res);
}

//10.13-5
double get_max_double(double* num, int len) {
	double* temp = num;
	for (int i = 0; i < len; i++) {
		if (*temp < *(num + i)) {
			*temp = *(num + i);
		}
	}
	return *temp;
}
double get_min(double* num, int len) {
	double* temp = num;
	for (int i = 0; i < len; i++) {
		if (*temp > *(num + i)) {
			*temp = *(num + i);
		}
	}
	return *temp;
}
void cpp10_13_5() {
	double number[5] = { 100.1,20.2,10.3,30.9,8.9 };
	double max = get_max_double(number, 5);
	double min = get_min(number, 5);
	printf("最大值与最小值差为：%.1f", max-min);
}

//10.13.6
void revers_arr(double* num, int len) {
	double temp;
	for (int i = 0; i < (len - 1) / 2; i++) {
		temp = *(num+i);
		*(num+i) = *(num + len - 1 - i);
		*(num + len - 1 - i) = temp;
	}
	for (int i = 0; i < len; i++) {
		printf("%.1f ", *(num + i));
	}
}
void cpp10_13_6() {
	double number[5] = { 1.1,2.2,3.3,4.4,5.5 };
	revers_arr(number, 5);
	for (int i = 0; i < 5; i++) {
		printf("\n%.1f ", number[i]);
	}
}

//zippo2.c 指向多维数组的指针
void zippo2() {
	int zippo[4][2] = { {2,4},{6,8},{1,3},{5,7} };
	//[]的优先级高于*,下面pz指向一个内含2个int类型值的数组，而int* pax[2]则表示一个内含2个指针元素的数组，每个元素都指向int的指针。
	int(*pz)[2];
	pz = zippo;
	printf("pz　=　%p,pz　+　1　=　%p\n", pz, pz + 1);//2,6地址
	printf("pz[0]　=　%p,pz[0][0] = %p, pz[0]　+　1　=　%p\n", pz[0],&pz[0][0], pz[0] + 1);//2,4地址
	printf("*pz = %p,　*pz + 1 = %p, *(pz+1) = %p\n", *pz, *pz + 1,*(pz+1));//2,4，6地址
	printf("pz[0][0]　=　%d\n", pz[0][0]);//2
	printf("*pz[0] = %d\n", *pz[0]);//2
	printf("**pz = %d\n", **pz);//2
	printf("pz[2][1]　=　%d\n", pz[2][1]);//3
	printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));//3
}

//cpp10.13.7
void cpp10_13_7() {
	double source[2][2] = { {1,2},{3,4} };
	double target[2][2];
	for (int j = 0; j < 2; j++) {
		copy_ptr(target[j], source[j], 2);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("target[%d][%d] = %.1f\n", i,j,target[i][j]);
		}
	}
}

//cpp10.13.8
void cpp10_13_8() {
	double source[7] = {1,2,3,4,5,6,7};
	double target[3] = { 0 };
	copy_ptr(&target[0], &source[2], 3);
	for (int i = 0; i < 7; i++) {
		printf("%.1f,", source[i]);
	}
	for (int j = 0; j < 3; j++) {
		printf("\ntarget[%d] = %.1f", j, target[j]);
	}
}

//cpp10.13.9
#define N 3
#define M 5
void cp_ptr_vsl(int rows, int cols, double(* target)[M], double (*source)[M]);
void display_arr(int rows, int cols, double (*arr)[M]);
void cpp10_13_9() {
	double source[N][M] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	double target[N][M];
	cp_ptr_vsl(N, M, target, source);
	display_arr(N, M, source);
	printf("\n");
	display_arr(N, M, target);
}
void cp_ptr_vsl(int rows, int cols, double (*target)[M], double (*source)[M]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(target+i)+j) = *(*(source + i) + j);
		}
	}
}
void display_arr(int rows, int cols, double (*arr)[M]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.1f ", *(*(arr+i)+j));
		}
	}
}

//10.13.10
void sum_arr(int *pa, int *pb, int *pc, int len);
void cpp10_13_10() {
	int num1[4] = { 2,4,5,8 };
	int num2[4] = { 1,0,4,6 };
	int res[4];
	sum_arr(num1, num2, res, 4);
	for (int i = 0; i < 4; i++) {
		printf("res[%d] = %d\n", i, res[i]);
	}
}
void sum_arr(int* pa, int* pb, int *pc, int len) {
	for (int i = 0; i < len; i++) {
		*(pc + i) = *(pa + i) + *(pb + i);
	}
}

//cpp10.13.11
void dis_array(int(*arr)[5], int rows);
void bide_array(int(*arr)[5], int rows);
void cpp10_13_11() {
	int source[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	dis_array(source, 3);
	bide_array(source, 3);
	printf("\n");
	dis_array(source, 3);
}
void bide_array(int(*arr)[5], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 5; j++) {
			*(*(arr + i) + j) *= 2;
		}
	}
}
void dis_array(int(*arr)[5], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ",*(*(arr + i) + j));
		}
	}
}

//cpp10.13.12
//cpp10.13.13
void get_num(double(*source)[5], int rows) {
	
	for (int i = 0; i < rows; i++) {
		printf("请输入第 %d 组的5个double类型的数（逗号或空格隔开）：", i);
		printf("\n");
		scanf("%lf %lf %lf %lf %lf", &source[i][0], &source[i][1], &source[i][2], &source[i][3], &source[i][4]);
	}
}
void avg_num_5(double(*source)[5], int rows) {
	double avg_res = 0;
	double sum;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += *(*(source + i) + j);
			avg_res = sum / 5;
		}
		printf("第 %d 组平均数为: %.1f\n", i, avg_res);
	}
}
void avg_num_all(double(*source)[5], int rows) {
	double avg_res = 0;
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 5; j++) {
			sum += *(*(source + i) + j);
		}
	}
	avg_res = sum / 15;
	printf("总平均数为:%.1f\n", avg_res);
}
double get_num_max(double(*source)[5], int rows) {
	
	double max = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 5; j++) {
			if (*(*(source + i) + j) > max) {
				max = *(*(source + i) + j);
			}
		}
	}
	return max;
}
void cpp10_13_13() {
	double source[3][5];
	get_num(source, 3);
	printf("\n");
	printf("你输入的二维数组是:");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%.1f ", source[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	avg_num_5(source, 3);
	avg_num_all(source, 3);
	printf("数组中最大值是：%.1f", get_num_max(source, 3));
}

int main() {

	//cpp10_13_2();
	//cpp10_13_3();
	//cpp10_13_4();
	//cpp10_13_5();
	//cpp10_13_6();
	//zippo2();
	//cpp10_13_7();
	//cpp10_13_8();
	//cpp10_13_9();
	//cpp10_13_10();
	//cpp10_13_11();
	cpp10_13_13();
	return 0;
}
