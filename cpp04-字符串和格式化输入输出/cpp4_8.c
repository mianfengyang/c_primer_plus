#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <float.h>

void cpp4_8_1() {

	char name[40];
	char family_name[40];
	printf("������������ֺ���:");
	scanf("%s", name);
	scanf("%s", family_name);
	printf("%s��%s\n", name, family_name);
	
}

void cpp4_8_2() {
	char name[20];
	char f_name[20];
	int len_name;
	int len_fname;
	printf("������������ֺ���:");
	scanf("%s%s", name,f_name);
	len_name = strlen(name);
	len_fname = strlen(f_name);
	printf("your name have %d charactor and fname have %d charator\n", len_name, len_fname);
	printf("a.\"%s %s\"\n", name,f_name);
	printf("b.\"%20s %20s\"\n", name,f_name);
	printf("c.\"%-20s %-20s\"\n", name, f_name);
	printf("d.%*s %*s", len_name+3, name, len_fname+3, f_name);
}

void cpp4_8_3() {
	float num;
	printf("������һ����������\n");
	scanf("%f", &num);
	printf("num = %f and num =%E", num, num);
}

void cpp4_8_4() {
	float height;
	char name[20];
	printf("��������ߺ�������\n");
	scanf("%f%s", &height, name);
	printf("%s, you are %f feet tall", name, height);
}

void cpp4_8_5() {
	float download_speed;
	float file_size;
	float download_time;
	printf("�����������ٶȣ�Mb/s)���ļ���С��MB)]:\n");
	scanf("%f%f", &download_speed, &file_size);
	download_time = file_size * 8.0 / download_speed;
	printf("At %.2f megabits per second,a file of %.2f megabytes\n downloads in %.2f seconds",
		download_speed, file_size, download_time);
}

void cpp4_8_6() {
	char first_name[20];
	char last_name[20];
	int len_f;
	int len_l;
	printf("�������������\n");
	scanf("%s", first_name);
	len_f = strlen(first_name);
	printf("����������գ�\n");
	scanf("%s", last_name);
	len_l = strlen(last_name);
	printf("%s %s\n", first_name, last_name);
	printf("%*d %*d\n", len_f, len_f,len_l, len_l);
	printf("%s %s\n", first_name, last_name);
	printf("%-*d %-*d\n", len_f, len_f, len_l, len_l);

}

void cpp4_8_7() {
	double num1 = 1.0 / 3.0;
	float num2 = 1.0 / 3.0;
	printf("num1 = %.6f num2 = %.6f\n", num1, num2);
	printf("num1 = %.12f num2 = %.12f\n", num1, num2);
	printf("num1 = %.16f num2 = %.16f\n", num1, num2);
	printf("FLT_DIG = %d DBL_DIG = %d\n", FLT_DIG, DBL_DIG);
}

void cpp4_8_8() {
	const float galon_to_litre = 3.785;
	const float mile_to_km = 1.609;
	float num_mileage;
	float num_gasoline;
	float mile_per_galon;
	float litre_per_handred_km;
	printf("��������̣�Ӣ��������������أ�:\n");
	scanf("%f%f", &num_mileage, &num_gasoline);
	mile_per_galon = num_mileage / num_gasoline;
	litre_per_handred_km = (num_gasoline * galon_to_litre) * 100 / (num_mileage * mile_to_km);
	printf("ÿ�������Ϳ���ʻ %.1f Ӣ��\nÿ100������������ %.1f ��", mile_per_galon, litre_per_handred_km);
}