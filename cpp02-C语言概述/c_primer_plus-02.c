// c_primer_plus-02.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void cpp2_8() {
	int a, b;
	a = 5;
	b = 2;
	b = a; //b = 5
	a = b; //a = 5;
	printf("%d %d\n", b, a); //5 5
}

void cpp2_9() {
	int x, y;
	x = 10;
	y = 5;
	y = x + y; //15
	x = x * y; //150
	printf("%d %d\n", x, y); //150 15
}
int main() {
	//cpp2_8();
	//cpp2_9();
	/*cpp2_12_1();
	cpp2_12_2();
	cpp2_12_3();
	cpp2_12_4();
	cpp2_12_5();
	cpp2_12_6();
	cpp2_12_7();*/
	cpp2_12_8();
	return 0;
}

