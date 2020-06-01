#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//3_11_1 整数，浮点数上溢和下溢
void cpp3_11_1_int_float_err() {
	int a = 2147483647;
	int a1 = 0-2147483648-1;
	int b = a + 1;
	float num_f_max = 3.4e38;
	float num_f_min = 1.175494351e-38;
	printf("b = %d up_erro\n a1 = %d down_error\n", b, a1);
	printf("float up_erro:%e\nfloat down_error:%f\n", num_f_max * 100.0f, num_f_min - 2.0f);
}


//3_11_2 打印从键盘接收的ASCII码值
void cpp3_11_2_print_ascii() {
	int input_num;
	printf("请输入一个32-127的数：\n");
	scanf_s("%d", &input_num);
	printf("你输入的ASCII数值为：%d 对应的字符为：%c", input_num, input_num);
}

//3_11_3 发出一声警报，打印文本
void cpp3_11_3_alarm_print() {
	printf("\a");
	printf("Startled by the sudden sound,Sally shouted,\n");
	printf("\"By the Great Pumpkin, what was that!\"");
}

//3_11_4
void cpp3_11_4_print_float() {
	float input_num;
	printf("请输入一个浮点数:\n");
	scanf_s("%f", &input_num);
	printf("你输入的数是：%f\n指数形式为：%e\np记数形式为：%a",input_num,input_num,input_num);
}

//3_11_5
void cpp3_11_5_calc_age_to_sec() {
	int age;
	double age_sec;
	printf("请输入你的年龄：\n");
	scanf_s("%d", &age);
	age_sec = age * 3.156e7;
	printf("%d 对应的秒数为：%f", age, age_sec);
}

//3_11_6
void cpp3_11_6_calc_h2o_num() {
	double m_h2o = 3.0e-23;
	long double num_h2o;
	int num;
	printf("请输入水的夸脱数：\n");
	scanf_s("%d", &num);
	num_h2o = (double)num * 950 / m_h2o;
	printf("%d 夸脱水含 %lE 个水分子", num, num_h2o);
	
}

//3_11_7
void cpp3_11_7_height_inchi() {
	float inch;
	float height;
	printf("请输入你的身高（英寸）：\n");
	scanf_s("%f", &inch);
	height = inch * 2.54f;
	printf("你的身高为 %f 英寸，%f 厘米", inch, height);
}

//3_11_8
void cpp3_11_8_calc_cup() {
	float num_cups;
	printf("请输入杯数：\n");
	scanf_s("%f", &num_cups);
	printf("%f 杯 = %f 品脱\n = %f 盎司\n = %f 汤勺\n = %f 茶勺",
		num_cups, num_cups * 0.5, num_cups * 8.0, num_cups * 8.0 * 2.0, num_cups * 8.0 * 2.0 * 3.0);
}