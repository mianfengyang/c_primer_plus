#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//3_11_1 ���������������������
void cpp3_11_1_int_float_err() {
	int a = 2147483647;
	int a1 = 0-2147483648-1;
	int b = a + 1;
	float num_f_max = 3.4e38;
	float num_f_min = 1.175494351e-38;
	printf("b = %d up_erro\n a1 = %d down_error\n", b, a1);
	printf("float up_erro:%e\nfloat down_error:%f\n", num_f_max * 100.0f, num_f_min - 2.0f);
}


//3_11_2 ��ӡ�Ӽ��̽��յ�ASCII��ֵ
void cpp3_11_2_print_ascii() {
	int input_num;
	printf("������һ��32-127������\n");
	scanf_s("%d", &input_num);
	printf("�������ASCII��ֵΪ��%d ��Ӧ���ַ�Ϊ��%c", input_num, input_num);
}

//3_11_3 ����һ����������ӡ�ı�
void cpp3_11_3_alarm_print() {
	printf("\a");
	printf("Startled by the sudden sound,Sally shouted,\n");
	printf("\"By the Great Pumpkin, what was that!\"");
}

//3_11_4
void cpp3_11_4_print_float() {
	float input_num;
	printf("������һ��������:\n");
	scanf_s("%f", &input_num);
	printf("����������ǣ�%f\nָ����ʽΪ��%e\np������ʽΪ��%a",input_num,input_num,input_num);
}

//3_11_5
void cpp3_11_5_calc_age_to_sec() {
	int age;
	double age_sec;
	printf("������������䣺\n");
	scanf_s("%d", &age);
	age_sec = age * 3.156e7;
	printf("%d ��Ӧ������Ϊ��%f", age, age_sec);
}

//3_11_6
void cpp3_11_6_calc_h2o_num() {
	double m_h2o = 3.0e-23;
	long double num_h2o;
	int num;
	printf("������ˮ�Ŀ�������\n");
	scanf_s("%d", &num);
	num_h2o = (double)num * 950 / m_h2o;
	printf("%d ����ˮ�� %lE ��ˮ����", num, num_h2o);
	
}

//3_11_7
void cpp3_11_7_height_inchi() {
	float inch;
	float height;
	printf("�����������ߣ�Ӣ�磩��\n");
	scanf_s("%f", &inch);
	height = inch * 2.54f;
	printf("������Ϊ %f Ӣ�磬%f ����", inch, height);
}

//3_11_8
void cpp3_11_8_calc_cup() {
	float num_cups;
	printf("�����뱭����\n");
	scanf_s("%f", &num_cups);
	printf("%f �� = %f Ʒ��\n = %f ��˾\n = %f ����\n = %f ����",
		num_cups, num_cups * 0.5, num_cups * 8.0, num_cups * 8.0 * 2.0, num_cups * 8.0 * 2.0 * 3.0);
}