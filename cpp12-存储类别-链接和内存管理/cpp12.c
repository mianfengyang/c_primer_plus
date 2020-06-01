#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "diceroll.h"

//cpp12.3 loc_stat.c
void trystat(void) {
	int fade  = 1;
	static int stay  = 1;
	printf("fade = %d and stay = %d\n", fade++, stay++);
}
void loc_stat() {
	int count;
	for (count = 1; count <= 3; count++) {
		printf("Here comes iteration %d:\n", count);
		trystat();
	}
}

//cpp12.9.1 global.c
//int units = 0;
int  critic() {
	/* 删除了可选的重复声明 */
	int units;
	printf("No luck, my friend. Try again.\n");
	scanf("%d", &units);
	return units;
}
void global() {
	int units;
	printf("How many punds to a frikin of butter?\n");
	scanf("%d", &units);
	while (units != 56) {
		units = critic();
		
	}
	printf("You must have looked it up!\n");
}

//cpp12.9.2
static int mode;
static int distance;
static double fuel_consume = 0;
void set_mode(int set) {
	if (0 == set || 1 == set)
	{
		mode = set;
	}
	else
	{
		printf("Invalid mode specified. Mode %s used.\n", (mode ? "1(US)" : "0(metric)"));
	}

}
void get_info() {
	if (0 == mode)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%d", &distance);

		printf("Enter fuel comsumed in liters: ");
		scanf_s("%lf", &fuel_consume);
	}
	else if (1 == mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%d", &distance);

		printf("Enter fuel comsumed in gallons: ");
		scanf_s("%lf", &fuel_consume);
	}
}
void show_info() {
	if (0 == mode)
	{
		printf("Fuel comsumption is %lf liters per 100 km\n", (fuel_consume / (distance / 100)));
	}
	else if (1 == mode)
	{
		printf("Fuel comsuption is %lf miles per gallon.\n", distance / fuel_consume);
	}
}
void cpp12_9_2() {
	int mode;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while(mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();

		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
}

// cpp12.9.3
void get_info3(int mode, int* distance, double* fuel_comsuption)
{
	if (0 == mode)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf_s("%d", distance);

		printf("Enter fuel comsumed in liters: ");
		scanf_s("%lf", fuel_comsuption);
	}
	else if (1 == mode)
	{
		printf("Enter distance traveled in miles: ");
		scanf_s("%d", distance);

		printf("Enter fuel comsumed in gallons: ");
		scanf_s("%lf", fuel_comsuption);
	}

	return;
}
void show_info3(int mode, int distance, double fuel_consume)
{
	if (0 == mode)
	{
		printf("Fuel comsumption is %lf liters per 100 km\n", (fuel_consume / (distance / 100)));
	}
	else if (1 == mode)
	{
		printf("Fuel comsuption is %lf miles per gallon.\n", distance / fuel_consume);
	}

	return;
}
void cpp12_9_3(void)
{
	int mode = 0;
	int mode_pre = 0;
	int distance = 0;
	double fuel_consumption;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf_s("%d", &mode);

	while (mode >= 0)
	{
		if ((0 != mode) && (1 != mode))
		{
			printf("Invalid mode specified. Mode %s used.\n", (mode_pre ? "1(US)" : "0(metric)"));
			mode = mode_pre;
		}
		get_info3(mode, &distance, &fuel_consumption);
		show_info3(mode, distance, fuel_consumption);
		mode_pre = mode;
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf_s("%d", &mode);
	}
	printf("Done.\n");
	return;
}

//cpp12.9.4
void test01() {
	static int call;
	call++;
	printf("我被调用了 %d 次\n", call);
}
void cpp12_9_4() {
	
	for (int i = 0; i < 3; i++) {
		test01();
		
	}
}
//cpp12.9.5
void cpp12_9_5() {
	int array[100];
	srand((unsigned int)time(0));
	for (size_t i = 0; i < 100; i++)
	{
		array[i] = (rand() % 10 + 1);
	}

	printf("Before sorted:\n");
	for (size_t i = 0; i < 100; i++)
	{
		printf("%d ", array[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}

	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = i; j < 100; j++)
		{
			if (array[i] < array[j])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	printf("After sorted:\n");
	for (size_t i = 0; i < 100; i++)
	{
		printf("%d ", array[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}

//cpp12.9.6
static unsigned long int next = 1;
int rand1() {
	next = next * 1103515245 + 12345;
	return (unsigned int)(next % 10) + 1;
}
void srand1(unsigned int seed) {
	next = seed;
}
void cpp12_9_6() {
	int count = 0;
	int num = 1;
	unsigned seed;
	printf("Please enter your choice for seed:\n");
	while (num <= 10) {
		int parray[10] = { 0 };
		scanf("%u", &seed);
		srand1(seed);
		for (int i = 1; i <= 1000; i++) {
			int tmp = rand1();
			parray[tmp - 1]++;
			printf("%d ", tmp);
			if (i % 50 == 0) {
				printf("\n");
			}
		}
		for (int j = 0; j < 10; j++) {
			printf("%d 出现 %d 次\n", j + 1, parray[j]);
		}
		num++;
	}
		
}

//cpp12.9.7
void cpp12_9_7() {
	int dice, roll;
	int sets;
	int sides;
	int status;
	srand((unsigned int)time(0)); /* 随机种子 */
	printf("Enter the number of sets, q to stop.\n");
	while (scanf("%d", &sets) == 1 && sets > 0) {
		printf("How many sides and how many dice?\n");
		if ((status = scanf("%d %d", &sides, &dice)) != 2) {
			if (status == 'q') {
				break;
			}
			else {
				printf("You should have entered an integer.");
				printf("Let's begin again.\n");
				while (getchar() != '\n') {
					continue;
				}
				printf("How many sides? Enter q to stop.\n");
				continue;
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("Here are %d sets of %d %d-sided throws.\n", sets,dice,sides);
		for (int i = 0; i < sets; i++) {
			printf("%d ", rand() % 18 +1);
		}
		printf("\n");
		printf("How many sides? Enter q to stop.\n");
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
}

//cpp12.9.8
int* make_array(int elem, int val) {
	int * p = (int*)malloc(elem * sizeof(int));
	for (int i = 0; i < elem; i++) {
		p[i] = val;
	}
	return p;
}
void show_array(const int ar[], int n) {
	for (int i = 0; i < n; i++) {
		
		if ((i % 8 == 0) && i>1) {
			printf("\n");
		}
		printf("%d ", ar[i]);
	}
}
void cpp12_9_8() {
	int* pa;
	int size;
	int value;
	printf("Enter the number of elements: ");
	while (scanf("%d", &size) == 1 && size  > 0)
	{
		printf("Enter the initialization value: ");
		scanf_s("%d", &value);
		pa  = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("\nEnter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");
}

//cpp12.9.9
char** words_array(int n) {
	char** p = (char**)malloc(n * sizeof(char*));
	
	return p;
}
void cpp12_9_9() {
	int words_num;
	char src[50];
	char** dst;
	printf("How many words do you wish to enter:");
	while ((scanf("%d", &words_num) == 1)) {
		dst = words_array(words_num);
		printf("Enter %d words now:\n", words_num);
		for (int i =0; i < words_num; i++) {
			scanf("%s", src);
			int word_len = strlen(src);
			dst[i] = (char*)malloc(word_len+1);
			strcpy(dst[i],src);
		}
		printf("Here are your words:\n");
		for (int j = 0; j < words_num; j++)
		{
			printf("%s\n", dst[j]);
		}

		// 别忘记释放内存
		for (int i = 0; i < words_num; i++)
		{
			free(dst[i]);
		}
		free(dst);
		printf("How many words do you wish to enter:");
	}

}
int main() {

	//loc_stat();
	//global();
	//cpp12_9_2();
	//cpp12_9_3();
	//cpp12_9_4();
	//cpp12_9_5();
	//cpp12_9_6();
	//cpp12_9_7();
	//cpp12_9_8();
	cpp12_9_9();
	return 0;
}