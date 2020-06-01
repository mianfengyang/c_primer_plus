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
		//�������д�����Ȼ�����������ǲ�����else��֧�£����Ҫע�⣡
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
	printf("���������ݣ�");
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
	printf("����������(# ����)��");
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
	printf("������һ������ֵ:");
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
	printf("ż��������%d ż��ƽ��ֵ��%f\n", num_h, av_num_h);
	printf("����������%d ����ƽ��ֵ��%f\n", num_j, av_num_j);
}

//7_12_4
void cpp7_12_4() {
	char ch;
	int num_replace = 0;
	printf("���������ݣ�");
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
	printf("���滻�� %d ��\n", num_replace);
}

//7_12_5
void cpp7_12_5() {
	char ch;
	int num_replace = 0;
	printf("���������ݣ�");
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
	printf("\n���滻�� %d ��\n", num_replace);
}

//7_12_6
void cpp7_12_6() {
	char ch_pre = 'e';
	char ch;
	int num_ei = 0;
	printf("���������ݣ�#ֹͣ����");
	while ((ch = getchar()) != '#') {
		if (ch_pre && (ch == 'i')) {
			num_ei++;
		}

		ch = getchar();
	}
	printf("ei ������ %d ��", num_ei);
}

//7_12_7
void cpp7_12_7() {
	float work_time;
	float shui_salary;
	float salary;
	printf("�����빤��ʱ�䣺");
	scanf("%f", &work_time);
	if (work_time <= NORMEL_WORK_TIME) {
		salary = SALARY_PER_HOUR * work_time;
		shui_salary = 300 * SHUI_300 + 150 * SHUI_150 + (salary - 450) * SHUI_OTHER;
	}
	else{
		salary = SALARY_PER_HOUR * NORMEL_WORK_TIME + (work_time - NORMEL_WORK_TIME) * 1.5 * SALARY_PER_HOUR;
		shui_salary = 300 * SHUI_300 + 150 * SHUI_150 + (salary - 450) * SHUI_OTHER;
		
	}
	printf("�����ܶ� %f ˰�� %f �����룺%f", salary, shui_salary, salary - shui_salary);
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
	printf("�����빤��ʱ����");
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
			printf("��������ȷ��ѡ�\n");
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
	printf("%*s%*s", 16, " ", -10, "1)����");
	printf("%*s%*s\n", 16, " ", -10, "2)����");
	printf("%*s%*s", 16, " ", -8, "3)�ѻ飬����");
	printf("%*s%*s\n", 14, " ", -8, "4)�ѻ飬����");
	printf("****************************************************************************\n");
	printf("��ѡ��1~4����");
}
void calc_taxes(int choice) {
	float income;
	float tax;
	printf("������������룺");
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
	printf("%*s%*s", 16, " ", -10, "a)��");
	printf("%*s%*s\n", 16, " ", -10, "b)���");
	printf("%*s%*s", 16, " ", -10, "c)���޲�");
	printf("%*s%*s\n", 16, " ", -9, "q)�����˳�");
	printf("****************************************************************************\n");
	printf("��ѡ��a~c, q to quit����");
}
void print_price_weight(float choice, float weight, char* pname) {
	if (weight != 0) {
		printf("%-8s �ۼ� %-10.2f ���� %-10.2f ������ $%-10.2f\n", pname, choice, weight,choice*weight);
	}
		
}
void calc_sum( float total_weight, float total_price) {
	float yunfei = 0;
	float zhekou = 0;
	printf("�����ܼ� $%.2f", total_price);
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
	
	printf("\n������ %.2f �ۿ� %.2f �˷ѺͰ�װ�� %.2f �����ܶ� $%.2f\n", total_weight, zhekou,yunfei,total_price);
	
	
}
void cpp7_12_11() {
	float weight;
	float weight_yl = 0.0f;
	float weight_tc = 0.0f;
	float weight_hlb = 0.0f;
	float total_weight;
	float total_price;
	char choice;
	char name1[20] = "��";
	char name2[20] = "���";
	char name3[20] = "���޲�";
	cpp7_12_11_menu();
	
	while (scanf("%c", &choice)==1) {
		switch (choice) {
		case 'a':
			printf("������Ҫ���������:");
			scanf("%f", &weight);
			weight_yl += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'b':
			printf("������Ҫ���������:");
			scanf("%f", &weight);
			weight_tc += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'c':
			printf("������Ҫ���������:");
			scanf("%f", &weight);
			weight_hlb += weight;
			//calc_cpp7_12_11(2.05,weight,name1);
			break;
		case 'q':
			total_weight = weight_hlb + weight_tc + weight_yl;
			total_price = 2.05 * weight_yl + 1.15 * weight_tc + 1.09 * weight_hlb;
			printf("������Ϣ���£�\n");
			printf("****************************************************************************\n");
			print_price_weight(2.05,weight_yl,name1);
			print_price_weight(1.15, weight_tc, name2);
			print_price_weight(1.09, weight_hlb, name3);
			printf("****************************************************************************\n");
			calc_sum(total_weight, total_price);
			return;
		default:
			printf("��������ȷ��ѡ��!");
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