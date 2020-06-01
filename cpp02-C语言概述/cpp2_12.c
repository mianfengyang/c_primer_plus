#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//2-12-1
int cpp2_12_1() {

	printf("Gustav Mahler\n");
	printf("Gustav\nMahler\n");
	printf("Gustav ");
	printf("Mahler\n");

	return 0;
}
//2-12-2
void cpp2_12_2() {
	printf("杨绵峰\n南京市浦口区");
}

//2-12-3
void cpp2_12_3() {
	int age;
	int age_day;
	printf("请输入你的年龄：");
	scanf_s("%d", &age);
	age_day = age * 365;
	printf("你的年龄是：%d 天数为：%d\n", age, age_day);
}

//2-12-4
void jolly();
void deny();
void cpp2_12_4() {
	jolly();
	jolly();
	jolly();
	deny();
}
void jolly() {
	printf("For he's a jolly good fellow!\n");
}
void deny() {
	printf("Which nobody can deny!\n");
}

//2-12-5
void br();
void ic();
void cpp2_12_5() {
	br();
	printf(", ");
	ic();
	printf("\n");
	ic();
	printf(",\n");
	br();
	printf("\n");
}
void br() {
	printf("Brazil, Russia");
}
void ic() {
	printf("India, China");
}

//2-12-6
void cpp2_12_6() {
	int toes = 10;
	printf("toes=%d\ntoes*2=%d\ntoes*toes=%d\n", toes, toes * 2, toes * toes);
}

//2-12-7
void smile();
void cpp2_12_7() {
	smile();
	smile();
	smile();
	printf("\n");
	smile();
	smile();
	printf("\n");
	smile();
}
void smile() {
	printf("Smile!");
}

//2-12-8
void one_three();
void two();
void cpp2_12_8() {
	printf("starting now:\n");
	one_three();
	two();
	printf("three\n");
	printf("done!\n");
}

void one_three() {
	printf("one\n");
}
void two() {
	printf("two\n");
}