#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


//5_11_1
void cpp5_11_1() {
	const int time_num = 60;
	int time_h;
	int time_m;
	while (1) {
		printf("请输入一个数值表示分钟：");
		scanf("%d", &time_m);
		if (time_m <= 0) {
			printf("你在玩我吗？我头也不回的走了，bye");
			break;
		}
		else if (time_m < time_num) {
			time_h = 0;
			printf("格式化后的时间为：%d 小时 %d 分钟\n", time_h, time_m);
		}
		else {
			time_h = time_m / time_num;
			time_m = time_m % time_num;
			printf("格式化后的时间为：%d 小时 %d 分钟\n", time_h, time_m);
		}	 
	}
}

//5_11_2
void cpp5_11_2() {
	int num;
	int i = 0;
	printf("请输入一个整数：");
	scanf("%d", &num);
	for (i; i <= 10; i++) {
		printf("%d ", num++);
		//num++;
	}
}

//5_11_3
void cpp5_11_3() {
	int days;
	const int week_day = 7;
	int weeks;
	while (1) {
		printf("请输入天数：");
		scanf("%d", &days);
		if (days <= 0) {
			printf("不玩了，bye");
			break;
		}
		else  {
			weeks = days / week_day;
			printf("%d days are %d weeks,%d days\n", days, weeks, days % week_day);
		}
	}
}

//5_11_4
void cpp5_11_4() {
	const float inches_to_cm = 2.54f;
	const float inch_to_inches = 12.0f;
	float height_cm;
	int height_feet;
	float height_inches;
	while (1) {
		printf("Enter a height in centimeters (<=0 to quit):");
		scanf("%f", &height_cm);
		if (height_cm <= 0) {
			printf("bye");
			break;
		}
		else {
			height_feet = (int)(height_cm / inches_to_cm / inch_to_inches);
			height_inches = ((height_cm / inches_to_cm / inch_to_inches) - (float)((int)(height_cm / inches_to_cm / inch_to_inches))) * 12.0;
			printf("%.1f cm = %d feet, %.1f inches\n", height_cm, height_feet, height_inches);
		}
	}
}

//5_11_5
void cpp5_11_5() {
	int count, sum;
	count = 0;
	sum = 0;
	int num_input;
	printf("请输入兼职天数：");
	scanf("%d", &num_input);
	while (count++ < num_input) {
		sum += count;
	}
	printf("兼职 %d 天，共赚 $%d ", num_input, sum);
}

//5_11_6
void cpp5_11_6() {
	int count, sum;
	count = 0;
	sum = 0;
	int num_input;
	printf("请输入兼职天数：");
	scanf("%d", &num_input);
	while (count++ < num_input) {
		sum += count*count;
	}
	printf("兼职 %d 天，共赚 $%d ", num_input, sum);

}

//5_11_7
void cpp5_11_7_1(double num) {
	double x;
	x = num * num * num;
	printf("%f 的立方是:%f", num, x);
}
void cpp5_11_7() {
	double num;
	printf("请输入一个数用于计算立方值：");
	scanf("%lf", &num); //这里要注意，scanf语句中要接收double类型的值,必须使用lf
	cpp5_11_7_1(num);
}

//5_11_8
void cpp5_11_8() {
	int moduli_fist;
	int moduli_next;
	printf("请输入一个整数作为被模数：");
	scanf("%d", &moduli_fist);
	while (1) {
		printf("请再输入一个整数(0 to quit)：");
		scanf("%d", &moduli_next);
		if (moduli_next <= 0) {
			printf("bye");
			break;
		}
		else {
			printf("%d %% %d is %d\n", moduli_next, moduli_fist,moduli_next % moduli_fist);
		}
	}

}

//5_11_9
void Temperatures(double num_t) {
	const double k = 273.16;
	double temp_c;
	double temp_k;
	temp_c = 5.0 / 9.0 * (num_t - 32.0);
	temp_k = temp_c + k;
	printf("%f 华氏度 = %f 摄氏度，= %f 开氏度\n", num_t, temp_c, temp_k);
}
void cpp5_11_9() {
	double temp_h;
	int rev;
	while (1) {
		printf("请输入一个华氏温度:");
		rev = scanf("%lf", &temp_h);
		/*printf("%d", rev);*/
		if (rev == 'q' || rev != 1) {
			printf("quit");
			break;
		}
		else
			Temperatures(temp_h);
	}
}