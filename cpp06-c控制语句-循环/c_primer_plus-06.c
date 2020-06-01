#define _CRT_SECURE_NO_WARNINGS 1
#define POWER2(x) (1<<(x))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//�κ�ϰ��14
void cpp14() {
	int k;
	for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k), k * k < 26; k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
}

//6_16_1
void cpp6_16_1() {
	//str[27]���Դ��27���ַ������飬�±��0-26 ����ַ������ĩβ����'\0',�ͼ����ַ����飬Ҳ��һ���ַ���(%s)
	//������־Ҳռ��һ���ֽڵĳ��ȡ�
	char str[27];
	int index = 0;
	char* p = NULL;
	for (char i = 'a'; i <= 'z'; i++) {
		str[index] = i;
		//printf("str[%d] = %c\n", index, i);
		index++;
	}
	printf("%d\n", index);
	//�������д���������ַ������ĩβ���ϡ���������־��'\0'
	str[index] = '\0';
	p = str;
	//ʹ��forѭ���Ե����ַ���ӡ�ַ�������
	for (int i = 0; i < 26; i++) {
		printf("%c ", p[i]);
	}
	//ָ��pָ���ַ�����str���׵�ַstr����һ���ַ�������ˣ�������%s����ӡstr�ַ�����
	//���û�����ַ������ĩβ���Ͻ�����־����ʱʹ��%s��ӡstr�ͻ���������֡�
	printf("\n%s\n", p);
}

//6_16_2
void cpp6_16_2() {
	for (int i = 5; i >0; i--) {
		for (int j = 0; j < i; j++) {
			printf("$");
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 5; j > i; j--) {
			printf("$");
		}
		printf("\n");
	}
	for (int i = 5; i > 0; i--) {
		for (int j = 5; j >= i; j--) {
			printf("$");
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("$");
		}
		printf("\n");
	}
}

//6_16_3
void cpp6_16_3() {
	char ch = 'F';
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= i;j++) {
			printf("%c", ch-j);	
		}	
		printf("\n");
	}
	char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 5; i >= 0; i--) {
		for (int j = 5; j >= i; j--) {
			printf("%c", lets[j]);
		}
		printf("\n");
	}
}

//6_16_4
void cpp6_16_4() {
	char ch = 'A';
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= i; j++,ch++) {
			printf("%c", ch);
			//ch++;
		}
		printf("\n");
	}
}

//6_16_5
void cpp6_16_5() {
	char ch = 0;
	printf("Please input an uppercase letter:");
	scanf("%c", &ch);
	ch = toupper(ch);
	//getchar();

	int length = ch - 'A' + 1;
	for (int i = 0; i < length; i++)
	{
		char temp = 'A' - 1;
		for (int j = 0; j < (length - i - 1); j++)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%c", ++temp);
		}
		for (int j = 0; j < i; j++)
		{
			printf("%c", --temp);
		}

		printf("\n");
	}

}

//6_16_6
void cpp6_16_6() {
	int min_num;
	int max_num;
	int i = 0;
	printf("��������Ĵ�С����������������");
	scanf("%d%d", &min_num, &max_num);
	for (int i = min_num; i <= max_num; i++)
	{
		printf("%5d %5d %5d\n", i, i * i, i * i * i);
	}
}

//6_16_7
void cpp6_16_7() {
	char dw[20] = { 0 };
	char rever_dw[20] = { 0 };
	int dw_length;
	printf("������һ������:");
	scanf("%s", dw);
	printf("%s\n", dw);
	dw_length = strlen(dw);
	dw[dw_length + 1] = '\0';
	//�����ӡ�����ı�ԭ�ַ���
	for (int i = dw_length-1; i >=0 ; i--) {
		printf("%c", dw[i]);
	}
	//��ԭ�ַ��������γ�һ���µ��ַ���
	for (int i = 0; i < dw_length; i++) {
		rever_dw[i] = dw[dw_length - i - 1];
	}
	printf("\n%s\n", rever_dw);
}

//6_16_8
void cpp6_16_8() {
	float num1 = 0;
	float num2 = 0;
	float result = 0;
	printf("������2��������:");
	//1. scanf �������з���ֵ�ģ����ķ���ֵ���Էֳ��������
	//	1) ����������ʾ��ȷ��������ĸ���������ִ�� scanf("%d %d", &a, &b);
	//		����û�����"3 4"��������ȷ���룬����2����ȷ������������������
	//		����û�����"3,4"��������ȷ����a���޷�����b������1����ȷ������һ����������
	//	2) 0����ʾ�û������벻ƥ�䣬�޷���ȷ�����κ�ֵ�����������û��������",3 4"������0��
	//	3) EOF��������stdio.h���涨��ĳ�����ͨ��ֵΪ - 1������ʾ�������Ѿ���������Windows�£��û�����CTRL + Z���ῴ��һ�� ^ Z�ַ����ٰ��»س���������Ҫ�ظ�2�Σ����ͱ�ʾ���������Linux / Unix��ʹ��CTRL + D��ʾ���������

	//	���Կ���ʹ������Ĵ������������룺
	//	while (scanf("%s %c %c", str, &oldchar, &newchar) == 3) /* ��!= EOF , ��ǰ�߸��� */
	//	{
	//		; //����
	//	}

	//2. Ϊʲôǰ�� scanf �ĸ�ʽ�����棬 % s�� % c�м���Ҫ�ո��أ�
	//	������Ϊ���û�ո�Ļ�������oldchar����ľ��ǿո��� = = .

	//3. ˳��˵һ�£�printf�ķ���ֵ��������ַ��������磬printf("1234")�ķ���ֵ��4����printf("1234\n")�ķ���ֵ��5��
		
	while (scanf("%f%f", &num1, &num2)==2) {

		result = (num1 - num2) / (num1 * num2);
		printf("result = %f\n", result);
		printf("������2��������:");
	}
}


//6_16_9
float cpp6_16_9_1(float *pnum1,float *pnum2) {
	float result;
	result = (*pnum1 - *pnum2) / (*pnum1 * *pnum2);
	return result;
}
void cpp6_16_9() {
	float num1, num2, result;
	printf("������2��������:");
	while (scanf("%f%f", &num1, &num2) == 2) {
		result = cpp6_16_9_1(&num1,&num2);
		printf("result = %f\n", result);
		printf("������2��������:");
	}
}

//6_16_10
void cpp6_16_10() {
	int lower, upper;
	int square_lower,square_upper;
	int sum;
	printf("Enter lower and upper integer limits:");
	scanf("%d%d", &lower,&upper);
	while (lower < upper) {
		sum = 0;
		square_lower = lower * lower;
		square_upper = upper * upper;
		for (lower; lower <= upper; lower++) {
			sum += lower * lower;
		}
		printf("The sums of the squares from %d to %d is %d\n", square_lower, square_upper, sum);
		printf("Enter the next set of limits:");
		scanf("%d%d", &lower, &upper);
	}
	printf("Done\n");
}

//6_16_11
void cpp6_16_11() {
	int iarray[9];
	printf("please input 8 integer to array:");
	for (size_t i = 0; i < 8; i++)
	{
		scanf("%d", &iarray[i]);
	}
	printf("The array you inputed was:");
	for (int i = 7; i >= 0; i--)
	{
		printf("%d ", iarray[i]);
	}
	printf("\n");
}

//6_16_12
void cpp6_16_12() {
	double sum1, sum2;
	long long num;
	printf("������Ҫ����Ĵ�����");
	scanf("%lld", &num);
	while (num > 0) {
		sum1 = 0.0;
		sum2 = 0.0;
		for (long long i = 1;i<=num; i++) {
			sum1 += (1.0 / (float)i);
			printf("sum1 = %lf\n", sum1);
			if (i % 2 == 0) {
				sum2 -= 1.0 / (float)i;
			}
			else {
				sum2 += 1.0 / (float)i;
			}
		}
		printf("1.0+1.0/2.0+1.0/3.0...����(%lld)�� = %.8lf\n", num, sum1);
		printf("1.0-1.0/2.0+1.0/3.0...����(%lld)�� = %.8lf\n", num, sum2);
		printf("�������ٴμ���Ĵ�����");
		scanf("%lld", &num);
	}
	printf("Done!");
}

//6_16_13
void cpp6_16_13() {
	int data[9];
	int j = 0;
	for (int i = 0; i < 8; i++) {
		data[i] = POWER2(i);
		printf("data[%d] = %d\n", i, data[i]);
	}
	do {
		printf("data[%d] = %d\n", j, data[j++]);
		//j++;
	} while (j < 8);
}

//6_16_14
void cpp6_16_14() {
	double data1[9] = { 0.0 };
	double data2[9] = { 0.0 };
	for (int i = 0; i < 8; i++)
	{
		printf("��Ϊ��һ������data1�ĵ� %d ��ֵ��", i);
		scanf("%lf", &data1[i]);
		
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <= i; j++) {
			data2[i] += data1[j];
			
		}
	}
	for (int i = 0; i < 8; i++) {
		printf("%8.2f", data1[i]);
	}
	printf("\n");
	for (int i = 0; i < 8; i++) {
		printf("%8.2f", data2[i]);
	}
}

//6_16_15
void cpp6_16_15() {
	char data[255];
	int data_len;
	printf("������һ������:");
	scanf("%s", data);
	data_len = strlen(data) - 1;
	for (int i = data_len; i >= 0; i--) {
		printf("%c", data[i]);
	}
}

//6_16_16
void cpp6_16_16() {
	double Dap = 100.0;
	double Dei = 100.0;
	int i = 0;

	do
	{
		i++;
		Dap = Dap + 10;
		Dei = Dei * 1.05;
	} while (Dei < Dap);

	printf("After %d year, Deirdre's account:%lf, Daphne's account:%lf\n", i, Dei, Dap);

}

//6_16_17
void cpp6_16_17() {
	double money = 1000000;
	int i = 0;
	do {
		i++;
		money = money * 1.08;
		money = money - 100000;
	} while ( money >0);
	printf("After %d year money is null\n", i);
}

//6_16_18
void cpp6_16_18() {
	int friend = 5;
	int i = 0;
	do {
		i++;
		friend -= i;
		friend *= 2;
		printf("���� %d �ܺ��������ﵽ%d\n", i, friend);
	} while (friend < 150);
	
}
int main() {
	//cpp14();
	//cpp6_16_1();
	//cpp6_16_2();
	//cpp6_16_3();
	//cpp6_16_4();
	//cpp6_16_5();
	//cpp6_16_6();
	//cpp6_16_7();
	//cpp6_16_8();
	//cpp6_16_9();
	//cpp6_16_10();
	//cpp6_16_11();
	//cpp6_16_12();
	//cpp6_16_13();
	//cpp6_16_14();
	//cpp6_16_15();
	//cpp6_16_16();
	//cpp6_16_17();
	cpp6_16_18();
	return 0;
}