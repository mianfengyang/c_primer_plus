#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//3.3十六进制，八进制打印显示
void cpp3_3() {
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
}

//toobig.c 整数溢出
void toobig() {
	int i = 2147483647;
	//long long i = 2147483647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i + 1, i + 2);
	//printf("%lld %lld %lld\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);
}

//蜂明声
void beep() {
	printf("Hello!\007\n");
}

//cpp3_5 charcode
void charcode() {
	for (int i = 0; i < 127; i++) {
		if (isprint(i))
			printf("the code for %c is %d  ", i, i);
			if (i % 5 == 0) {
				printf("\n");
		}
	}
}

//3.7showf_pt.c
void showf_pt() {
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f can be written %e\n", aboat, aboat);
	printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
	printf("%f can be written %e\n", abet, abet);
	printf("%Lf can be written %Le\n", dip, dip);
}

//3.8 typesize.c 获取当前系统各数据类型的大小
void typesize() {
	printf("type int has a size of %zd bytes.\n", sizeof(int)); //4
	printf("type float has a size of %zd bytes.\n", sizeof(float));  //4
	printf("type char has a size of %zd bytes.\n", sizeof(char));  //1
	printf("type double has a size of %zd bytes.\n", sizeof(double));  //8
	printf("type long double has a size of %zd bytes.\n", sizeof(long double));  //8
	printf("type short has a size of %zd bytes.\n", sizeof(short));  //2
	printf("type long has a size of %zd bytes.\n", sizeof(long));  //4
	printf("type long long has a size of %zd bytes.\n", sizeof(long long));  //8
}

int main() {
	
	//cpp3_3();
	//toobig();
	//beep();
	//charcode();
	//showf_pt();
	typesize();
	//cpp3_11_1_int_float_err();
	//cpp3_11_2_print_ascii();
	//cpp3_11_3_alarm_print();
	//cpp3_11_4_print_float();
	//cpp3_11_5_calc_age_to_sec();
	//cpp3_11_6_calc_h2o_num();
	//cpp3_11_7_height_inchi();
	//cpp3_11_8_calc_cup();
	return 0;
}