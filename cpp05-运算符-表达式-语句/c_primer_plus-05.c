#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SQUARES 64

//5.5 wheat.c
void wheat() {
	const double CROP = 2E16; //世界小麦年产谷粒数
	double current, total;
	int count = 1;
	printf("square\tgrains\t\ttotal\tfraction of\n");
	printf("\tadded\t\tgrains\tworld total\n");
	total = current = 1.0;
	printf("%4d%13.2e%12.2e%12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES) {
		count = count + 1;
		current = 2.0 * current;
		total = total + current;
		printf("%4d%13.2e%12.2e%12.2e\n", count, current, total, total / CROP);
	}
	printf("That's all.\n");

}
//5.8 sizeof.c
void sizeof_() {
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n = %d, n has %zd bytes; all ints have %zd bytes\n", n, sizeof n, intsize);
}
int main() {

	//wheat();
	//sizeof_();
	//cpp5_11_1();
	//cpp5_11_2();
	//cpp5_11_3();
	//cpp5_11_4();
	//cpp5_11_5();
	//cpp5_11_6();
	//cpp5_11_7();
	//cpp5_11_8();
	cpp5_11_9();
	return 0;
}