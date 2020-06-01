#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "hotel.h"

void up_and_down(int);
void up_and_down(int n) {
	printf("Level %d: n location %p\n", n, &n);
	if (n < 4) {
		up_and_down(n + 1);
	}
	printf("Level %d: n location %p\n", n, &n);
}
void recur() {
	up_and_down(1);
}

//9.7 factor.c
factor() {
	long fact(int n);
	long rfact(int n);
	int num;
	printf("This program calculates factorials.\n");
	printf("Enter a value in the range 0-12 (q to quit):");
	while (scanf("%d", &num) == 1) {
		if (num < 0) {
			printf("No negative numbers,please.\n");
		}
		else if (num > 12) {
			printf("Keep input under 13.\n");
		}
		else {
			printf("loop: %d factorial = %ld\n", num, fact(num));
			printf("recursion: %d factorial = %ld\n", num, rfact(num));
		}
		printf("Enter a value in the range 0-12 (q to quit):");
	}
	printf("Bye.\n");
}
long fact(int n) {
	long ans;
	for (ans = 1; n > 1; n--) {
		ans *= n;
	}
	return ans;
}
long rfact(int n) {
	long ans;
	if (n > 0) {
		ans = n * rfact(n - 1);
	}
	else {
		ans = 1;
	}
	return ans;
}


//9.8 binary.c
void binary() {
	void to_binary(unsigned long n);
	unsigned long number;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu", &number) == 1) {
		printf("Binary equivalent: ");
		to_binary(number);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");
}

void to_binary(unsigned long n) {
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
}

//9.9 usehotel.c
void usehotel() {
	int nights;
	double hotel_rate;
	int code;
	while ((code = menu()) != 5) {
		switch (code) {
		case 1: hotel_rate = HOTEL1;
			break;
		case 2: hotel_rate = HOTEL2;
			break;
		case 3: hotel_rate = HOTEL3;
			break;
		case 4: hotel_rate = HOTEL4;
			break;
		default: hotel_rate = 0.0;
			printf("Oops!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you and goodbye.\n");
}

//9.11.1
void cpp9_11_1() {
	double imin(double x, double y);
	double res = imin(2.34, 4.23);
	printf("%f", res);
}
double imin(double x, double y) {
	return x > y ? y : x;
}

//9.11.2
void cpp9_11_2() {
	char chline(ch, i, j);
	char ch[5][10] = {"the","desk","on","ground","welcome"};
	char res = chline(ch, 2, 3);
	printf("%c", res);
}
char chline(char ch[][10], int i, int j) {
	return ch[j][i];
}

//9.11.3
void cpp9_11_3() {
	void print(ch, num, lines);
	char ch;
	int num;
	int lines;
	printf("请输入一个字符，次数及行数：");
	scanf("%c%d%d", &ch, &num, &lines);
	print(ch, num, lines);
}
void print(char ch,int num, int lines) {
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < num; j++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

//9.11.4
void cpp9_11_4() {
	double tavg(num1, num2);
	double num1, num2;
	double res;
	printf("请输入2个数：");
	scanf("%lf%lf", &num1, &num2);
	res = tavg(num1, num2);
	printf("%.4f %.4f 调和平均数为：%.4f", num1, num2, res);
}
double tavg(double num1, double num2) {
	return 1 / ((1 / num1 + 1 / num2) / 2);
}

//9.11.5
void cpp9_11_5() {
	void larger_of(x, y);
	double x = 1024.8;
	double y = 512.4;
	larger_of(&x, &y);
	printf("x = %f, y = %f", x, y);
}
void larger_of(double *x, double *y) {
	if (*x > * y) {
		*y = *x;
	}
	else {
		*x = *y;
	}
}

//9.11.6
void cpp9_11_6() {
	void sort_test(x, y, z);
	double num1, num2, num3;
	printf("请输入3个数：");
	scanf("%lf%lf%lf", &num1, &num2, &num3);
	printf("你输入的数是：%f %f %f\n", num1, num2, num3);
	sort_test(&num1, &num2, &num3);
	printf("min = %f,midle = %f,max = %f", num1, num2, num3);
}

void sort_test(double *x, double *y, double *z) {
	double temp;
	if (*x > *y ) {
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if (*x > *z){
		temp = *x;
		*x = *z;
		*z = temp;
	}
	if (*y > * z) {
		temp = *y;
		*y = *z;
		*z = temp;
	}
}

//9.11.7
void cpp9_11_7() {
	int get_index(ch);
	char input;
	int index;
	printf("Please input text(end with #):");
	while ((input = getchar()) != '#') {
		//putchar(input);
		if (input == '\n') {
			continue;
		}
		index = get_index(tolower(input));
		if (index == -1) {
			printf("%c is not a charactor.\n", input);
			
		}
		else {
			printf("%c is charactor.", input);
			printf(" index is %d\n", index);
		}
		//printf("Please input text(ctrl + d stop):");
	}
	printf("Done!\n");
}
int get_index(char ch) {
	char str[26] = "abcdefghijklmnopqrstuvwxyz";
	if (isalpha(ch)) {
		for (int i = 0; i < 26; i++) {
			if (str[i] == ch) {
				return i + 1;
			}
		}
	}
	else {
		return -1;
	}
}

//9.11.8
void cpp9_11_8() {
	double power(double n, int p);
	double x, xpow;
	int exp;
	printf("Enter a number and the positive integer power to which the number will be raised.Enter q to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2) {
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");

	}
	printf("Hope you enjoyed this power trip --bye!\n");
}
double power(double n, int p) {
	double pow = 1;
	int i;
	if (p >= 0) {
		for (i = 1; i <= p; i++) {
			pow *= n;
		}
		return pow;
	}
	else {
		for (i = 1; i <= -p; i++) {
			pow *= n;
		}
		return 1 / pow;
	}
}
//9.11.9
double power_recur(double n, int p) {
	double pow;
	int i;
	pow = n * p;
	if (n == 0) {
		if (p == 0) {
			printf("%f 的 %d 次幂未定义，处理为：%d\n", n, p, 1);
		}
		else {
			pow = 0;
			return pow;
		}
	}
	if (p == 0 && n !=0) {
		pow = 1;
		return pow;
	}
	
	else if (p<0){
		if (p == -1) {
			pow = n * (-p);
			return 1/pow;
		}
		else{
			pow = n * power_recur(n, -p-1);
			return 1 / pow;
		}
	}
	else{
		pow = n * power_recur(n, p - 1);
		return pow;
	}
}

void cpp9_11_9() {
	double power_recur(double n, int p);
	double x, xpow;
	int exp;
	printf("Enter a number and the positive integer power to which the number will be raised.Enter q to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2) {
		xpow = power_recur(x, exp);
		if ( x !=0 || exp != 0)
			printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");

	}
	printf("Hope you enjoyed this power trip --bye!\n");
}

//9.11.10
void cpp9_11_10() {
	void to_base_n_1(unsigned long n,int p);
	unsigned long number;
	int p;
	printf("Enter an integer (q to quit):\n");
	while (scanf("%lu%d", &number,&p) == 2) {
		printf("Binary equivalent: ");
		to_base_n_1(number,p);
		putchar('\n');
		printf("Enter a number and an integer (q to quit):\n");
	}
	printf("Done.\n");
}

void to_base_n(unsigned long n,int p) {
	int r;
	r = n % p;
	if (p == 2) {
		if (n >= 2)
			to_base_n(n / p, p);
		putchar(r == 0 ? '0' : '1');
	}
	if (p == 4) {
		if (n >= 4) {
			to_base_n(n / p, p);
		}
		printf("%d", r);
	}
	if (p == 8) {
		if (n >= 8) {
			to_base_n(n / p, p);
		}
		printf("%d", r);
	}
	
}
void to_base_n_1(unsigned long n, int p) {
	int r;
	r = n % p;
	to_base_n(n / p, p);
	printf("%d", r);

}
//9.11.11
void cpp9_11_11() {
	long data[50] = { 1,1 };
	for (int i = 2; i < 20; i++) {
		data[i] = data[i - 1] + data[i - 2];
	}

	for (int i = 0; i < 20; i++) {
		printf("%ld ", data[i]);
	}
}
int main() {
	//recur();
	//factor();
	//binary();
	//usehotel();
	//cpp9_11_1();
	//cpp9_11_2();
	//cpp9_11_3();
	//cpp9_11_4();
	//cpp9_11_5();
	//cpp9_11_6();
	//cpp9_11_7();
	//cpp9_11_8();
	//cpp9_11_9();
	cpp9_11_10();
	//cpp9_11_11();
	return 0;
}