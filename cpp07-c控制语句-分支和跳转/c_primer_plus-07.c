#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define SALARY_PER_HOUR 1000
#define NORMEL_WORK_TIME 40
#define SHUI_300 0.15
#define SHUI_150 0.2
#define SHUI_OTHER 0.25
//7_11_5
void cpp7_11_5() {
	int num;
	for (num = 1; num <= 11; num++) {
		if (num%3==0)
		{
			putchar('$');
		}
		else
			putchar('*');
		//下面这行代码虽然有缩进，但是不属于else分支下，这点要注意！
			putchar('#');
		putchar('%');

	}
	putchar('\n');
}

//7_12_1
void cpp7_12_1() {
	int space = 0;
	int cnt = 0;
	int others = 0;
	printf("请输入内容：");
	char ch = getchar();
	do {
		if (ch == ' ')
			space++;
		else if (ch == '\n')
			cnt++;
		else
			others++;
		ch = getchar();
	} while (ch != '#');
	printf("there are %d space, %d cnt, %d others", space, cnt, others);
}

//7_12_2
void cpp7_12_2() {
	char ch;
	int num_ch = 0;
	printf("请输入内容(# 结束)：");
	ch = getchar();
	do {
		num_ch++;
		printf("%-1c-%-3d ", ch, ch);
		if (num_ch % 8 == 0) {
			printf("\n");
		}
		ch = getchar();
	} while (ch != '#');
	
}

//7_12_3
void cpp7_12_3() {
	int num;
	int num_j = 0;
	int num_h = 0;
	int sum_j = 0;
	int sum_h = 0;
	float av_num_j = 0;
	float av_num_h = 0;
	printf("请输入一个整数值:");
	scanf("%d", &num);
	while (num != 0) {
		if (num % 2 == 0) {
			num_h++;
			sum_h += num;
		}
		else {
			num_j++;
			sum_j += num;
		}
		scanf("%d", &num);
	}
	av_num_j = sum_j / num_j;
	av_num_h = sum_h / num_h;
	printf("偶数个数：%d 偶数平均值：%f\n", num_h, av_num_h);
	printf("奇数个数：%d 奇数平均值：%f\n", num_j, av_num_j);
}

//7_12_4
void cpp7_12_4() {
	char ch;
	int num_replace = 0;
	printf("请输入内容：");
	ch = getchar();
	while (ch != '#') {
		if (ch == '.') {
			ch = '!';
			num_replace++;
		}
		else if (ch == '!') {
			putchar(ch);
			num_replace++;
		}
		putchar(ch);
		ch = getchar();
	}
	//putchar(ch);
	printf("共替换了 %d 次\n", num_replace);
}

//7_12_5
void cpp7_12_5() {
	char ch;
	int num_replace = 0;
	printf("请输入内容：");
	ch = getchar();
	while (ch != '#') {
		switch (ch) {
		case '.':
			ch = '!';
			num_replace++;
			break;
		case '!':
			putchar(ch);
			num_replace++;
			break;
		default:
			break;
		}
		putchar(ch);
		ch = getchar();
	}
	printf("\n共替换了 %d 次\n", num_replace);
}

//7_12_6
void cpp7_12_6() {
	char ch_pre = 'e';
	char ch;
	int num_ei = 0;
	printf("请输入内容（#停止）：");
	while ((ch = getchar()) != '#') {
		if (ch_pre && (ch == 'i')) {
			num_ei++;
		}

		ch = getchar();
	}
	printf("ei 共出现 %d 次", num_ei);
}

//7_12_7
void cpp7_12_7() {
	float work_time;
	float shui_salary;
	float salary;
	printf("请输入工作时间：");
	scanf("%f", &work_time);
	if (work_time <= NORMEL_WORK_TIME) {
		salary = SALARY_PER_HOUR * work_time;
		shui_salary = 300 * SHUI_300 + 150 * SHUI_150 + (salary - 450) * SHUI_OTHER;
	}
	else{
		salary = SALARY_PER_HOUR * NORMEL_WORK_TIME + (work_time - NORMEL_WORK_TIME) * 1.5 * SALARY_PER_HOUR;
		shui_salary = 300 * SHUI_300 + 150 * SHUI_150 + (salary - 450) * SHUI_OTHER;
		
	}
	printf("工资总额 %f 税金 %f 净收入：%f", salary, shui_salary, salary - shui_salary);
}

//7_12_8
void menu() {
	printf("****************************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("%*s%*s%*s\n",15," ",-20,"1)$8.75/hr",-20,"2)$9.33/hr");
	printf("%*s%*s%*s\n", 15, " ", -20, "3)$10.00/hr", -20, "4)$11.20/hr");
	printf("%*s%*s\n",15," ",-20,"5)quit");
	printf("****************************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:");
}
void calc_salary(float rate) {
	float salary;
	float shui;
	float salary_sum;
	float time;
	printf("请输入工作时长：");
	scanf("%f", &time);
	salary = rate * time;
	if (salary <= 300) {
		shui = salary * SHUI_300;
		salary_sum = salary - shui;
	}
	else if (salary >= 450) {
		shui = 300 * SHUI_300 + 150 * SHUI_150;
		salary = salary - shui;
	}
	else {
		shui = 300 * SHUI_300 + 150 * SHUI_150+ (salary-450)*SHUI_OTHER;
		salary = salary - shui;
	}
	printf("rate %f work time %f salary %f\n\n", rate, time, salary);
}
void cpp7_12_8() {
	const float rate1 = 8.75;
	const float rate2 = 9.33;
	const float rate3 = 10.00;
	const float rate4 = 11.20;
	int num;
	menu();
	while (scanf("%d", &num)==1) {
		switch (num) {
		case 1:
			calc_salary(rate1);
			break;
		case 2:
			calc_salary(rate2);
			break;
		case 3:
			calc_salary(rate3);
			break;
		case 4:
			calc_salary(rate4);
			break;
		case 5:
			printf("quit!\n");
			return;
		default:
			printf("请输入正确的选项！\n");
			break;
		}
		menu();
	}
}

//7_12_9


void cpp7_12_9() {
	int input = 0;

	printf("please input the upper number:");
	scanf_s("%d", &input);

	int i = 0;
	int j = 0;
	int num = 0;
	for (i = 2; i <= input; i++)
	{
		for (j = 2; j < sqrt((double)i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			num++;
			
			printf("%d ", i);
			if (num % 5 == 0)
				printf("\n");
		}
	}
}

//7_12_10
void cpp7_12_10_menu() {
	printf("****************************************************************************\n");
	printf("%*s%*s", 16, " ", -10, "1)单身");
	printf("%*s%*s\n", 16, " ", -10, "2)户主");
	printf("%*s%*s", 16, " ", -8, "3)已婚，共有");
	printf("%*s%*s\n", 14, " ", -8, "4)已婚，离异");
	printf("****************************************************************************\n");
	printf("请选择（1~4）：");
}
void calc_taxes(int choice) {
	float income;
	float tax;
	printf("请输入你的收入：");
	scanf("%f", &income);
	tax = choice * 0.15 + 0.28 * (income - choice);
	printf("choice %d tax %f\n", choice, tax);
}
void cpp7_12_10() {
	const float single_tax = 17850;
	const float householder = 23900;
	const float married_share = 29750;
	const float divorced = 14875;
	int choice;
	float rate;
	cpp7_12_10_menu();
	while (scanf("%d", &choice) == 1) {
		switch ( choice)
		{
		case 1:
			rate = single_tax;
			calc_taxes(rate);
			break;
		case 2:
			rate = householder;
			calc_taxes(rate);
			break;
		case 3:
			rate = married_share;
			calc_taxes(rate);
			break;
		case 4:
			rate = divorced;
			calc_taxes(rate);
			break;
		default:
			printf("bye!");
			return;
		}
		cpp7_12_10_menu();
	}
}

//7_12_11
void cpp7_12_11_menu() {
	printf("****************************************************************************\n");
	printf("%*s%*s", 16, " ", -10, "a)洋蓟");
	printf("%*s%*s\n", 16, " ", -10, "b)甜菜");
	printf("%*s%*s", 16, " ", -10, "c)胡罗卜");
	printf("%*s%*s\n", 16, " ", -9, "q)结算退出");
	printf("****************************************************************************\n");
	printf("请选择（a~c, q to quit）：");
}
void print_price_weight(float choice, float weight, char* pname) {
	if (weight != 0) {
		printf("%-8s 售价 %-10.2f 重量 %-10.2f 订单价 $%-10.2f\n", pname, choice, weight,choice*weight);
	}
		
}
void calc_sum( float total_weight, float total_price) {
	float yunfei = 0;
	float zhekou = 0;
	printf("订单总价 $%.2f", total_price);
	if (total_weight <= 5) {
		yunfei = 6.5;
	}
	else if (total_weight <= 20) {
		yunfei = 14.0;
	}
	else {
		yunfei = 14.0 + (total_weight - 20.0) * 0.5;
	}
	if (total_price >= 100) {
		zhekou = total_price * 0.05;
		
	}
	total_price += yunfei;
	total_price -= zhekou;
	
	printf("\n总重量 %.2f 折扣 %.2f 运费和包装费 %.2f 费用总额 $%.2f\n", total_weight, zhekou,yunfei,total_price);
	
	
}
void cpp7_12_11() {
	float weight;
	float weight_yl = 0.0f;
	float weight_tc = 0.0f;
	float weight_hlb = 0.0f;
	float total_weight;
	float total_price;
	char choice;
	char name1[20] = "洋蓟";
	char name2[20] = "甜菜";
	char name3[20] = "胡罗卜";
	cpp7_12_11_menu();
	
	while (scanf("%c", &choice)==1) {
		switch (choice) {
		case 'a':
			printf("请输入要购买的重量:");
			scanf("%f", &weight);
			weight_yl += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'b':
			printf("请输入要购买的重量:");
			scanf("%f", &weight);
			weight_tc += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'c':
			printf("请输入要购买的重量:");
			scanf("%f", &weight);
			weight_hlb += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'q':
			total_weight = weight_hlb + weight_tc + weight_yl;
			total_price = 2.05 * weight_yl + 1.15 * weight_tc + 1.09 * weight_hlb;
			printf("订单信息如下：\n");
			printf("****************************************************************************\n");
			print_price_weight(2.05,weight_yl,name1);
			print_price_weight(1.15, weight_tc, name2);
			print_price_weight(1.09, weight_hlb, name3);
			printf("****************************************************************************\n");
			calc_sum(total_weight, total_price);
			return;
		default:
			printf("请输入正确的选项!");
			break;
		}

		cpp7_12_11_menu();
		scanf("%c", &choice);
	}
	
	
}
int main() {

	//cpp7_11_5();
	//cpp7_12_1();
	//cpp7_12_2();
	//cpp7_12_3();
 	//cpp7_12_4();
	//cpp7_12_5();
	//cpp7_12_6();
	//cpp7_12_7();
	//cpp7_12_8();
	//cpp7_12_9();
	//cpp7_12_10();
	cpp7_12_11();
	return 0;
}