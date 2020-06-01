#define _CRT_SECURE_NO_WARNINGS 1
#define POWER2(x) (1<<(x))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

//课后复习题14
void cpp14() {
	int k;
	for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k), k * k < 26; k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
}

//6_16_1
void cpp6_16_1() {
	//str[27]可以存放27个字符的数组，下标从0-26 如果字符数组的末尾加上'\0',就即是字符数组，也是一个字符串(%s)
	//结束标志也占用一个字节的长度。
	char str[27];
	int index = 0;
	char* p = NULL;
	for (char i = 'a'; i <= 'z'; i++) {
		str[index] = i;
		//printf("str[%d] = %c\n", index, i);
		index++;
	}
	printf("%d\n", index);
	//下面这行代码就是在字符数组的末尾加上“结束”标志符'\0'
	str[index] = '\0';
	p = str;
	//使用for循环以单个字符打印字符串数组
	for (int i = 0; i < 26; i++) {
		printf("%c ", p[i]);
	}
	//指针p指向字符数组str的首地址str又是一个字符串，因此，可以用%s来打印str字符串。
	//如果没有在字符数组的末尾加上结束标志，此时使用%s打印str就会有乱码出现。
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
	printf("请输入表格的大小（行数和列数）：");
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
	printf("请输入一个单词:");
	scanf("%s", dw);
	printf("%s\n", dw);
	dw_length = strlen(dw);
	dw[dw_length + 1] = '\0';
	//反序打印，不改变原字符串
	for (int i = dw_length-1; i >=0 ; i--) {
		printf("%c", dw[i]);
	}
	//将原字符串反序形成一个新的字符串
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
	printf("请输入2个浮点数:");
	//1. scanf 函数是有返回值的，它的返回值可以分成三种情况
	//	1) 正整数，表示正确输入参数的个数。例如执行 scanf("%d %d", &a, &b);
	//		如果用户输入"3 4"，可以正确输入，返回2（正确输入了两个变量）；
	//		如果用户输入"3,4"，可以正确输入a，无法输入b，返回1（正确输入了一个变量）。
	//	2) 0，表示用户的输入不匹配，无法正确输入任何值。如上例，用户如果输入",3 4"，返回0。
	//	3) EOF，这是在stdio.h里面定义的常量（通常值为 - 1），表示输入流已经结束。在Windows下，用户按下CTRL + Z（会看到一个 ^ Z字符）再按下回车（可能需要重复2次），就表示输入结束；Linux / Unix下使用CTRL + D表示输入结束。

	//	所以可以使用下面的代码来处理输入：
	//	while (scanf("%s %c %c", str, &oldchar, &newchar) == 3) /* 或!= EOF , 但前者更好 */
	//	{
	//		; //处理
	//	}

	//2. 为什么前面 scanf 的格式串里面， % s和 % c中间需要空格呢？
	//	那是因为如果没空格的话。。。oldchar输入的就是空格了 = = .

	//3. 顺便说一下，printf的返回值是输出的字符数，例如，printf("1234")的返回值是4，而printf("1234\n")的返回值是5。
		
	while (scanf("%f%f", &num1, &num2)==2) {

		result = (num1 - num2) / (num1 * num2);
		printf("result = %f\n", result);
		printf("请输入2个浮点数:");
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
	printf("请输入2个浮点数:");
	while (scanf("%f%f", &num1, &num2) == 2) {
		result = cpp6_16_9_1(&num1,&num2);
		printf("result = %f\n", result);
		printf("请输入2个浮点数:");
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
	printf("请输入要计算的次数：");
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
		printf("1.0+1.0/2.0+1.0/3.0...计算(%lld)次 = %.8lf\n", num, sum1);
		printf("1.0-1.0/2.0+1.0/3.0...计算(%lld)次 = %.8lf\n", num, sum2);
		printf("请输入再次计算的次数：");
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
		printf("请为第一个数组data1的第 %d 个值：", i);
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
	printf("请输入一行内容:");
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
		printf("经过 %d 周后，朋友数达到%d\n", i, friend);
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