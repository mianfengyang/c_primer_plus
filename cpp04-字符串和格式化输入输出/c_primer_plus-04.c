#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h> // 整型限制
#include <float.h> // 浮点型限制
#define DENSITY 62.4
#define PRAISE "You are an extraordinary being."
#define PI 3.141593
#define PAGES 959
#define BLURB "Authentic imitation!"
#define PAGES 336
#define WORDS 65618

//4.1 talkback.c
void talkback() {
	float weight, volume;
	int size, letters;
	char name[40];
	printf("Hi! What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Well, %s, your volume is %2.2f cubic feet.\n",name,volume);
	printf("Also,your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);
}

//4.2 praisel.c
void praise1() {
	char name[40];
	printf("What's you name?");
	scanf("%s", name);
	printf("Hello,%s.%s\n", name, PRAISE);
}

//4.3 praise2.c
void praise2() {
	char name[40];
	printf("What's your name?");
	scanf("%s", name);
	printf("Hello,%s.%s\n", name, PRAISE);
	printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name),sizeof(name));
	printf("The phrase of praise has %zd letters", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n", sizeof(PRAISE));
}

//4.4 PIZZA.C
void pizza() {
	float area, circum, radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = 2.0 * PI * radius;
	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference=%1.2f,area=%1.2f\n", circum, area);
}

//4.5 defines.c
void defines() {
	printf("Some number limits for this system:\n");
	printf("Biggest int: %d\n", INT_MAX);
	printf("Smallest long long: %lld\n", LLONG_MIN);
	printf("One byte = %d bits on this system.\n", CHAR_BIT);
	printf("Largest double: %e\n", DBL_MAX);
	printf("Smallest normal float: %e\n", FLT_MIN);
	printf("float precision = %d digits\n", FLT_DIG);
	printf("float epsilon = %e\n", FLT_EPSILON);
}

//4.6 printout.c
void printout() {
	int	number = 7;
	float pies = 12.75;
	int cost = 7800;
	printf("The %d contestants ate %f berry pies.\n", number,
		pies);
	printf("The value of pi is %f.\n", PI);
	printf("Farewell! thou art too dear for my possessing,\n");
	printf("%c%d\n", '$', 2 * cost);
}

//4.7
void width() {
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);
}

//4.8
void floats() {
	const double RENT = 3852.99; // const变量
	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);
}

//4.9
void flags() {
	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d**% d**\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
}

//4.9
void stringf() {
	printf("[%.2s]\n", BLURB);
	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.5s]\n", BLURB);
}

//4.11
void intconv() {
	short num = PAGES;
	short mnum = -PAGES;
	printf("num as short and unsigned short: %hd %hu\n", num, num);
	printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
	printf("num as int and char: %d %c\n", num, num);
	printf("WORDS as int,short,and char: %d %hd %c\n", WORDS, WORDS, WORDS);
}

//4.12 floatcnv
void floatcnv() {
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;
	printf("%.le %.le %.le %.le\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
}
int main() {
	//talkback();
	//praise1();
	//praise2();
	//pizza();
	//defines();
	//printout();
	//width();
	//floats();
	//flags();
	//stringf();
	//intconv();
	//floatcnv();
	//cpp4_8_1();
	//cpp4_8_2();
	//cpp4_8_3();
	//cpp4_8_4();
	//cpp4_8_5();
	//cpp4_8_6();
	//cpp4_8_7();
	cpp4_8_8();
	return 0;
}