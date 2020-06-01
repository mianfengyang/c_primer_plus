
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void test01() {
	int num[2][2] = { {1,2},{3,4} };
	int* p = num[0];
	printf("*p=%d **num=%d *(num[0])=%d num[0][0]=%d\n", *p, **num, *(num[0]), num[0][0]);
	printf("p=%p num=%p *num=%p &num[0]=%p &num[0][0]=%p\n", p, num, *num, &num[0], &num[0][0]);
	printf("*(p + 1)=%d\n", *(p + 1));
	printf("*(p + 2)=%d\n", *(p + 2));
	printf("*(*(num+1)+1)=%d\n", *(*(num+1) + 1));
	printf("*(num[0] + 1)=%d\n", *(num[0] + 1));
	printf("*(num[0] + 3)=%d\n", *(num[0] + 3));
}



#define M 3
#define N 5
void cp_ptr(double(*source)[N], double(*target)[N], int rows, int cols);
void dis_arr(double(*arr)[N], int rows, int cols);

void test02() {
	double source[M][N] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	double target[M][N];
	//int rows = 3;
	//int cols = 5;
	cp_ptr(source, target, M, N);
	dis_arr(source, M, N);
	printf("\n");
	dis_arr(target, M, N);

}
void cp_ptr(double(*source)[N], double(*target)[N], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			*(*(target + i) + j) = *(*(source + i) + j);
		}
	}
}
void dis_arr(double(*arr)[N], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.1f ", *(*(arr + i) + j));
		}
	}
}

void test03() {
	const char* mytalents[5] = {
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	printf("sizeof mytalents: %zd", sizeof(mytalents));//32位调试20字节，64位调试40字节
}

void test04() {
	char* pt1 = "Something is pointing at me.";
	printf("%s\n",pt1);
	printf("%s\n",pt1+1);
	printf("%s\n",pt1++);
	printf("%c", pt1[3]);
}

//cpp11.13.1
char* str_get(char* p, int len, int n) {
	printf("please input anything char:\n");
	char ch;
	//char **ret=p;

	int i = 0;
	while ((ch = getchar()) != '#') {
		p[i] = ch;
		//p++;
		i++;
		if (i >= len-1) {
			p[i] = '\0';
			break;
		}
	}
	p[i] = '\0';
	for (int j = 0; j < len; j++) {
		p[j] = p[n++];
		if (p[j] == '\0') {
			break;
		}
	}
	return p;
}

void cpp11_13_1() {
	char str[50];
	str_get(str, 50, 5);
	printf("%s", str);
}

void test05() {
	char str[] = "hello frank";
	printf("%c",str[1]);
	printf("%d", strlen(str));
}

void test06() {
	char str[] = "hello frank";
	int str_len = strlen(str);
	printf("%d", str_len);
}

void test07() {
	//此函数可以去除字符串中的所有空格
	char str[] = "frank   ok   flushdns";
	int i = 0;
	int space = 0;
	int j = 0;
	for (i = 0; i < strlen(str); i++) {
		//判断当前字符是否是空格
		if (isspace(str[i + space])) {
			space += 1;
			j = (i + space);
			//判断当前字符后续是否有连续空格
			while (str[j] == ' ') {
				j++;
				space += 1;
			}
		}
		//将后续字符往前挪动
		str[i] = str[i + space];
	}
	printf("%s\n", str);
}


void remove_blank_char_only_save_one(char* s,char * res){	
	int m = 0;
	int i;

	for (i = 0; s[i] != '\0';){
		//注意判断字符的空格要使用单引号' ',不能使用双引号
		if (s[i] == '\t') {
			s[i] = ' ';
		}
		if (isblank(s[i])){	
			res[m] = s[i];
			m++;
			i++;
			while (isblank(s[i])) {
				i++;
			}
		}
		else {
			res[m] = s[i];
			m++;
			i++;
		}
		
	}
	res[m] = '\0';
	//return res;
}
void remove_blank_on_start(char* s) {
	if (s == NULL || *s == '\0')
	{
		return ;
	}

	int len = 0;
	char* p = s;
	while (*p != '\0' && isspace(*p))
	{
		++p;
		++len;
	}

	memmove(s, p, strlen(s) - len + 1);
	
}
char* remove_blank_on_end(char* str)
{
	if (str == NULL || *str == '\0')
	{
		return str;
	}

	int len = strlen(str);
	char* p = str + len - 1;
	while (p >= str && isspace(*p))
	{
		*p = '\0';
		--p;
	}

	return str;
}
int count_str_words(char* s) {
	int words = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') {
			words += 1;
		}
	}
	return words+1;
}
char * sort_str_by_word_len(char* s, int num) {
	int j = 0, k = 0;
	char t[20];//临时数组，用于交换
	static char des[][20] = { 0 };
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] != ' ') {
			//以空格分割每个单词，当遇到空格之前，把空格之前的字符存到一个二维数组中
			des[j][k++] = s[i];
			
		}
		else {
			//当遇到空格时，添加第一个一维级数组的结束标志，并将J加1开始第二一维数组的赋值，并让K的值归0，从头开始计算。
			
			des[j][k] = '\0';
			j++;
			
			k = 0;
		}
	}
	//使用冒泡法，根据二维数组中各个一维数组的长度进行排序
	for (int m = 0; m < num; m++) {
		for (int n = 0; n < num - m - 1; n++) {
			if (strlen(des[n]) > strlen(des[n + 1])) {
				strcpy(t, des[n]);
				strcpy(des[n], des[n + 1]);
				strcpy(des[n + 1], t);
			}
		}
	}
	return des;
}
void test08() {
	char str[] = "frank ok has t";
	char res[50] = { 0 };
	int n_words = 0;
	char(*p)[20];
	//remove_blank_char_only_save_one(str, res);
	//remove_blank_on_start(res);
	//remove_blank_on_end(res);
	//printf("%s\n", res);
	n_words = count_str_words(str);
	printf("共有%d个单词\n", n_words);
	p = sort_str_by_word_len(str, n_words);
	for (int i = 0; i < n_words; i++) {
		printf("%s ", p[i]);
	}
}
void test09(){
	char str[4][10] = {"ok","hello"};
	printf("%d", strlen(str));
}
void test10() {
	char str = "hello world";
	//toupper(str); toupper函数只能传入一个字符，且要求整形数据，不能对一个字符串操作
	printf("%s", str);
}
int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//cpp11_13_1();
	test10();
	return 0;
}
