#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>


//11.5复习题
char* pr(char* str);
void cpp11_12_5() {
	char* x;
	x = pr("Ho Ho Ho!");
}
char* pr(char* str) {
	char* pc;
	pc = str;
	while (*pc) {
		putchar(*pc++);
	}
	do {
		putchar(*--pc);
	} while (pc - str);
	return (pc);
}

//11.8
void test11_8() {
	char str1[] = "gawsie";
	char str2[] = "bletonism";
	char* ps;
	int i = 0;
	for (ps = str1; *ps != '\0'; ps++) {
		if (*ps == 'a' || *ps == 'e') {
			putchar(*ps);
		}
		else {
			(*ps)--;
		}
		putchar(*ps);
	}
	putchar('\n');
	while (str2[i] != '\0') {
		printf("%c", i % 3 ? str2[i] : '*');
		++i;
	}
}

//11.9 s_gets()
char * s_gets(char* st,int n) {
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (st[i] != '\n' && st[i] != '\0') {
			i++;

		}
		if (st[i] == '\n') {
			st[i] = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}
char* s_gets_1(char* st, int n) {
	char* ret_val;
	//int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (*st != '\n' && *st != '\0') {
			st++;

		}
		if (*st == '\n') {
			*st = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}
void s_gets_test() {
	char  m[20];
	s_gets_1(m, 20);
	printf("%s", m);
}

//11.10
int str_len(char* pstr) {
	int ret_len = 0;
	while (*pstr++ != '\0') {
		ret_len++;
	}
	return ret_len;
}
void test_strlen() {
	char m[] = "hello world!";
	int len = str_len(m);
	printf("m len is %d ", len);
}

//11.11
char* s_gets_2(char* st, int n) {
	char* ret_val;
	char* find;
	//int i = 0;
	printf("请输入一些字符：\n");
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		
		if (find) {
			*find = '\0';
		}
		else {
			while (getchar() != '\n') {
				continue;
			}
		}
	}
	return ret_val;
}

//11.12
char* test12(char* p) {
	char* find;
	find = strchr(p, ' ');
	if (find) {
		return find;
	}
	else {
		return NULL;
	}
}
void test12_1() {
	char* res;
	char m1[] = "helloworld";
	char m2[] = "hello world ";
	res = test12(m1);
	printf("%p\n", res);
	res = test12(m2);
	printf("%p", res);
}

//cpp11.13.1
void gets_n(char* p, int len, int n) {
	printf("please input anything char:\n");
	char ch;
	int i = 0;
	while ((ch = getchar()) != '#') {
		p[i] = ch;
		i++;
		if (i >= len -1) {
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
}
void cpp11_13_1() {
	char str[50];
	gets_n(str, 50,5);
	printf("总共接收50个字符，将从第5个字符开始显示：\n");
	printf("%s", str);
}
void gets_n_1(char* p, int len, int n) {
	printf("please input anything char:\n");
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n') {
		if (ch == ' ') {
			printf("程序检测到你在第%d位置输入了 空白 字符，程序终止\n", i + 1);
			break;
		}
		if (ch == '\t') {
			printf("程序检测到你在第%d位置输入了 制表 字符，程序终止\n", i + 1);
			break;
		}
		p[i] = ch;
		i++;
		if (i > n - 1) {
			p[i] = '\0';
			break;
		}
	}
	p[i] = '\0';
	if (ch == '\n') {
		printf("程序检测到你在第%d位置输入了 换行 字符，程序终止\n", i + 1);
	}
}
void cpp11_13_2() {
	char str[50];
	int n = 10;
	gets_n_1(str, 50, n);
	printf("\n总共可以接收50个字符，但只接收%d个字符：\n",n);
	printf("当程序遇到第一个空白字符或换行或制表符时会停止。\n");
	printf("%s", str);
}

//11.13.3
void get_word(char* p) {
	int i=0;
	char ch;
	printf("please input:\n");
	while (1) {
		ch = getchar();
		if (!isblank(ch)) {
			break;
		}
	}
	p[i++] = ch;
	while (1) {
		ch = getchar();
		if (isblank(ch)) {
			break;
		}
		p[i++] = ch;
	}
	p[i] = '\0';
}
void cpp11_13_3() {
	char str[15];
	get_word(str);
	printf("%s", str);
}

//11.13.4
void get_word_n(char* p, int n) {
	int i = 0;
	char ch;
	printf("please input:\n");
	while (1) {
		ch = getchar();
		if (!isblank(ch)) {
			break;
		}
	}
	p[i++] = ch;
	while (i<n) {
		ch = getchar();
		if (isblank(ch)) {
			break;
		}
		p[i++] = ch;
	}
	p[i] = '\0';
}
void cpp11_13_4() {
	char str[15];
	get_word_n(str,10);
	printf("%s", str);
}

//cpp11.13.5
int find_str(char* p, char *s) {
	int i = 0;
	for (i = 0; i < strlen(p); i++) {
		if (p[i] == *s) {
			return i;
		}
	}
	return -1;
}
void cpp11_13_5() {
	printf("please input source char(only accept first 20 len):\n");
	char ch;
	char str[20];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		if (i >= 19) {
			break;
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	printf("接收到的字符串为：%s\n", str);
	printf("please input a char for look up:");
	char dst;
	scanf("%c", &dst);
	int res = find_str(str, &dst);
	if (res != -1) {
		printf("0-20个字符中找到字符：%c，位置：%d", dst, res);
	}
	else {
		printf("0-20个字符中未找到字符 %c", dst);
	}
}

//cpp11.13.6
int is_within(char* p, char s) {
	int i = 0;
	for (i = 0; i < strlen(p); i++) {
		if (p[i] == s) {
			return i;
		}
	}
	return 0;
}
void cpp11_13_6() {
	printf("please input source char(only accept first 20 len):\n");
	char ch;
	char str[20];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		if (i >= 19) {
			break;
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	printf("接收到的字符串为：%s\n", str);
	printf("please input a char for look up:");
	char dst = getchar();
	//scanf("%c", &dst);
	int res = is_within(str, dst);
	if (res != 0) {
		printf("0-20个字符中找到字符：%c，位置：%d", dst, res);
	}
	else {
		printf("0-20个字符中未找到字符 %c", dst);
	}

}

//cpp11.13.7
char* mystrncpy(char *s1, char* s2, int n) {
	int s1_len = strlen(s1);
	int j = s1_len;
	for (int i = 0; i < n; i++) {
		s1[j++] = s2[i];
		if (j > 99) {
			break;
		}
	}
	s1[j] = '\0';
	return s1;
}
void cpp11_13_7() {
	char ch;
	char str1[100] = "hello frank";
	char str2[20];
	int i = 0;
	printf("please input str2(only accept 20 len):\n");
	while ((ch = getchar()) != '\n') {
		if (i >= 19) {
			break;
		}
		str2[i++] = ch;
	}
	str2[i] = '\0';
	setbuf(stdin, NULL);
	printf("接收到的字符串为：%s\n", str2);
	char* res = mystrncpy(str1, str2, 10);
	printf("new str1 is :%s", res);
}

//cpp11.13.8
char* string_in(char* p, char* s) {
	int i = 0;
	for (i = 0; i < strlen(p); i++) {
		int j = 0;
		//使用while循环,当找到第一个相同字符时，继续对后续字符进行比较，当把s所有的字符串和原始字符串比较完了且都相同的情况下返回原始字符串中第一个
		//相同字符的地址，p[i+j]是关键。
		while (p[i+j] == s[j++]) {
			if (j >= strlen(s)) {
				return &p[i];
			}
		}
	}
	return NULL;
}
void cpp11_13_8() {
	char ch;
	char str[30] = "this is a good frank";
	char str2[10];
	int i = 0;
	printf("原始字符串为：%s\n", str);
	printf("please input str2(only accept first 20 len):\n");
	while ((ch = getchar()) != '\n') {
		if (i >= 9) {
			break;
		}
		str2[i++] = ch;
	}
	str2[i] = '\0';
	setbuf(stdin, NULL);
	
	char* res = string_in(str, str2);
	if (res != NULL) {
		printf("在str字符中找到子串：%s，内存位置：%p", str2, res);
	}
	else {
		printf("未找到子串 %s", str2);
	}
}

//cpp11.13.9
char* revers_str(char* s) {
	int str_len = strlen(s);
	char temp;
	for (int i = 0; i < str_len / 2; i++) {
		temp = s[i];
		s[i] = s[str_len-i -1];
		s[str_len-i-1] = temp;
	}
	return s;
}
void cpp11_13_9() {
	char ch;
	char str[20];
	int i = 0;
	printf("please input str(only accept first 20 len):\n");
	while ((ch = getchar()) != '\n') {
		if (i >= 19) {
			break;
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	char* res = revers_str(str);
	printf("%s", res);
}

//cpp11.13.10
char* deal_blan(char* s) {
	char* p = s;
	int i = 0;
	while (*p)
	{
		if (!isblank(*p)) {
			s[i++] = *p;
		}
		p++;
	}
	s[i] = '\0';
	return s;

}
void cpp11_13_10() {
	char ch;
	char str[20];
	int i = 0;
	printf("please input str(only accept first 20 len):\n");
	//gets(str);
	//判断当出现连续换行符时，即表示输入了一个空行，此时程序中止
	while (i<19) {
		ch = getchar();
		str[i] = ch;
		if ((str[i] == '\n') && (str[i-1] == '\n')) {
			break;
		}
		i++;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	char* res = deal_blan(str);
	printf("%s", res);
}

//cpp11.13.11
void remove_blank_char_only_save_one(char* s, char* ret) {
	int m = 0;
	int i;

	for (i = 0; s[i] != '\0';) {
		//注意判断字符的空格要使用单引号' ',不能使用双引号
		if (s[i] == '\t') {
			s[i] = ' ';
		}
		if (isblank(s[i])) {
			ret[m] = s[i];
			m++;
			i++;
			while (isblank(s[i])) {
				i++;
			}
		}
		else {
			ret[m] = s[i];
			m++;
			i++;
		}

	}
	ret[m] = '\0';
}
void remove_blank_on_start(char* s) {
	if (s == NULL || *s == '\0')
	{
		return s;
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
void remove_blank_on_end(char* s)
{
	if (s == NULL || *s == '\0')
	{
		return s;
	}

	int len = strlen(s);
	char* p = s + len - 1;
	while (p >= s && isspace(*p))
	{
		*p = '\0';
		--p;
	}
}
int get_str_words_num(char* s, int n) {

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ') {
			n++;
		}
	}
	return n + 1;
}
static char dst[10][50];
void sort_str_by_word_len(char* s, int num) {
	
	int j = 0,k = 0;
	char t[50];//临时数组，用于交换
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] != ' ') {
			//以空格分割每个单词，当遇到空格之前，把空格之前的字符存到一个二维数组中
			dst[j][k++] = s[i];
		}
		else {
			//当遇到空格时，添加第一个一维级数组的结束标志，并将J加1开始第二一维数组的赋值，并让K的值归0，从头开始计算。
			dst[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	//使用冒泡法，根据二维数组中各个一维数组的长度进行排序
	for (int m = 0; m < num; m++) {
		for (int n = 0; n < num - m - 1; n++) {
			if (strlen(dst[n]) > strlen(dst[n + 1])) {
				strcpy(t, dst[n]);
				strcpy(dst[n], dst[n + 1]);
				strcpy(dst[n + 1], t);
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%s ", dst[i]);
	}
}

void case2(char* s) {
	//冒泡排序法
	char temp;
	char res[50];
	strcpy(res, s);
	for (int i = 0; i < strlen(res); i++) {
		for (int j = 0; j < strlen(res) - i - 1; j++) {
			if (res[j] > res[j + 1]) {
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
		}
	}
	printf("%s\n", res);
}
void case3(char* s) {
	
	char res[50];
	int n_words = 0;
	strcpy(res, s);
	char* temp = res;
	remove_blank_char_only_save_one(res, temp);
	remove_blank_on_start(temp);
	remove_blank_on_end(temp);
	n_words = get_str_words_num(temp, n_words);
	sort_str_by_word_len(temp, n_words);
	printf("\n");
}
void menu() {
	printf("=================================================\n");
	printf("1.打印源字符列表	2.ASCII顺序打印\n");
	printf("3.按长度递增打印	4.按第一个单词长度打印\n");
	printf("5.退出\n");
	printf("=================================================\n");
	printf("请输入选项：");
}
void myprint(char* s) {
	int choice;
	menu();
	int n_str = 0;
	while (scanf("%d", &choice) == 1) {
		switch (choice) {
		case 1:
			printf("%s\n", s);
			break;
		case 2:
			case2(s);
			break;
		case 3:
			case3(s);
			break;

		case 4:

			break;
		case 5:
			printf("bye!");
			return;
		default:
			printf("请输入正确的选项:1-5\n");
			break;
		}
		menu();
	}
	
}
void cpp11_13_11() {
	char ch;
	char str[50];
	int i = 0;
	printf("please input 50 char:\n");
	while (i < 49) {
		ch = getchar();
		str[i] = ch;
		if ((str[i] == '\n') && (str[i - 1] == '\n')) {
			break;
		}
		i++;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	myprint(str);
}

//cpp11.13.12
void cpp11_13_12() {
	int num_of_word = 0;
	int num_of_uper = 0;
	int num_of_lower = 0;
	int num_of_num = 0;
	int num_of_punc = 0;
	char ch;
	char str[100];
	int i = 0;
	printf("please input anything:\n");
	while ((ch = getchar()) != EOF) {
		str[i++] = ch;
		if (i > 99) {
			break;
		}
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	for (int j = 0; j < strlen(str); j++) {
		/*if (isblank(str[j])) {
			num_of_word++;
		}*/
		if (ispunct(str[j])) {
			num_of_punc++;
		}
		if (isupper(str[j])) {
			num_of_uper++;
			if (ispunct(str[j + 1]) || isblank(str[j+1])) {
				num_of_word++;
			}
		}
		if (islower(str[j])) {
			num_of_lower++;
			if (ispunct(str[j + 1]) || isblank(str[j + 1])) {
				num_of_word++;
			}
		}
		if (isdigit(str[j])) {
			num_of_num++;
		}
	}
	printf("num_of_word: %d\n", num_of_word);
	printf("num_of_punc: %d\n", num_of_punc);
	printf("num_of_uper: %d\n", num_of_uper);
	printf("num_of_lower: %d\n", num_of_lower);
	printf("num_of_num: %d\n", num_of_num);
}

//cpp11.13.13
void cpp11_13_13() {
	char ch;
	char str[50];
	char ret[10][50] = { 0 };
	int x = 0;
	printf("please input some command:\n");
	while ((ch = getchar()) != '#') {
		str[x++] = ch;
		if (x > 49) {
			break;
		}
	}
	str[x] = '\0';
	setbuf(stdin, NULL);

	int j = 0, k = 0;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] != ' ') {
			//以空格分割每个单词，当遇到空格之前，把空格之前的字符存到一个二维数组中
			ret[j][k++] = str[i];
		}
		else {
			//当遇到空格时，添加第一个一维级数组的结束标志，并将J加1开始第二一维数组的赋值，并让K的值归0，从头开始计算。
			ret[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	for (int m = strlen(ret); m >= 0; m--) {
		printf("%s ", ret[m]);
	}
}

//cpp11.13.14
void cpp11_13_14() {
	//祥见commandline项目
}
//cpp1.13.15
int cpp11_13_15() {
	char ch;
	int str[] = { 0 };
	int i = 0;
	printf("please input something:\n");
	

}
int main(int argc, char* argv[]) {
	
	//cpp11_12_5();
	//s_gets_test();
	//test_strlen();
	//test12_1();
	//cpp11_13_1();
	//cpp11_13_2();
	//cpp11_13_3();
	//cpp11_13_4();
	//cpp11_13_5();
	//cpp11_13_6();
	//cpp11_13_7();
	//cpp11_13_8();
	//cpp11_13_9();
	//cpp11_13_10();
	//cpp11_13_11();
	//cpp11_13_12();
	//cpp11_13_13();
	//cpp11_13_14();
	cpp11_13_15();
	
	return 0;
}