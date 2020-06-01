#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

   

//8_11_1
void cpp8_11_1() {
	int count_ch = 0;
	char ch;
	printf("please input some charactor:");
	while ((ch = getchar()) != EOF) {
		//putchar(ch);
		if (ch != '\n') {
			count_ch++;
		}
	}
	printf("there are %d charactor in your input.", count_ch);
}

//8_11_2
void cpp8_11_2() {
	char ch = 0;
	int n_char = 0;
	while ((ch = getchar()) != EOF)
	{
		n_char++;
		if (ch < ' ')
		{
			if ('\t' == ch)
			{
				putchar('\\');
				putchar('t');
				printf(":%d ", ch);
			}
			else if ('\n' == ch)
			{
				putchar('\\');
				putchar('n');
				printf(":%d ", ch);
			}
			else
			{
				putchar('^');
				putchar(ch + 64);
				printf(":%d ", ch);
			}
		}
		else
		{
			putchar(ch);
			printf(":%d ", ch);
		}
		if (n_char % 10 == 0)
		{
			printf("\n");
		}

	}
}

//8_11_3
void cpp8_11_3() {
	int up_count = 0;
	int lo_count = 0;
	char ch;
	printf("���������ݣ�Ӣ���ַ�):");
	while ((ch = getchar()) != EOF) {
		if (isupper(ch)) {
			up_count++;
		}
		if (islower(ch)) {
			lo_count++;
		}
	}
	printf("upper %d lower %d", up_count, lo_count);
}

//8_11_4_1 ͳ�Ƹ����ַ����г��ֵĵ��ʸ�����������ĸ����
void cpp8_11_4_1() {
	char data[] = "  there are some books,, on the desk. we are the desk";
	char* p = data;
	int count_per_word = 0;
	int count_words = 0;
	int total_char = 0;
	while (*p != NULL) {

		//ָ��ָ���ַ����׵�ַ�������ж�ָ��ֵ�Ƿ�Ϊ��ĸ������ĸ�ʹ�ӡ������ָ������ƣ�ͬʱ��ָ���Ƶ��ո�������֮ǰ��ͳ��
		//������ĸ����+1
		if (isalpha(*p)) {
			printf("%c", *p);
			count_per_word++;
			p++;
			//��ָ���Ƶ��ո�������ʱ����ʾһ�����ʵĽ�������ʱ��ͳ�Ƶ��ʵļ�����+1������ӡǰһ�����ʵ���ĸ����������ͳ����ĸ
			//�����ַ�����һ�����ʽ����󣬵�����ĸ��������0����ӡ���з���ͬʱָ���������ƣ���������ǰѭ����������һ�����ʵ��ж�
			if (isspace(*p) || ispunct(*p) ) {
				count_words++;
				printf(" -%d chars", count_per_word);
				total_char += count_per_word;
				count_per_word = 0;
				printf("\n");
				p++;
				continue;
			}
		}

		//���������������� �ո�������ʱ��ָ����������ֱ��������ĸ
		else if (isspace(*p) || ispunct(*p)) {
			p++;
		}
	}
	//��ָ���ƶ�����βʱ�������β�ĵ��ʵ����һ���ַ����ǿո���㣬��ʱ��Ҫ���⴦��
	if (*p == '\0' && (!isspace(*(p - 1)) || !ispunct(*(p - 1)))) {
		count_words++;
		printf(" -%d chars", count_per_word);
		total_char += count_per_word;
	}
	printf("\nthere are %d words %d total char", count_words,total_char);
}

//8_11_4_2 ���������ж�ȡ�ַ��������浽�ַ�������
void from_scanf_to_store() {
	//�����ַ������飬�������û�г�ʼ���������ָ������Ĵ�С���г�ֵ������ɲ�ָ����С���ַ����ȼ���һά�ַ����顣
	char ch[100];
	int len;
	printf("input:");
	//scanf����ʹ��[^\n]�������������г��ֵĿո񡣲��һ����������Ľ�β�Զ���ӽ�����־'\0'��
	scanf("%[^\n]",ch);
	len = strlen(ch);
	//ch[len + 1] = '\0';
	printf("%s\n", ch);
	printf("%d\n", len);
	//�ַ���������±꣬���Ա�����
	for (int i = 0; i <= len; i++) {
		printf("%d\n", ch[i]);
	}
}
void test_strcpy() {
	char buf[100] = "";
	char str[10][100] = {0};
	int i = 0;
	int j = 0;
	printf("input:");
	while (1) {
		//����һ�е�����ŵ�buf��
		fgets(buf, 100, stdin);
		//����⵽���е�ʱ���˳�ѭ������������
		if (buf[0] == '\n' || i>9) {
			break;
		}
		//��������д���������������С�strcpy()������2�������У���һ��Ҫ����ָ������ĵ�ַ���ڶ�������Ҫ����һ������������һ��ָ���ַ��
		//��ά�ַ�������a[3][5]��a[0],a[1],a[2]��ʾ��һ�У��ڶ��У������д洢���ַ������׵�ַ���൱�ڣ�&a[0][0],&a[1][0],&a[2][0]
		strcpy(str[i++], buf);
		//strcpy(&str[i++][0], buf);
		//strcpy(&str[i++][0], &buf);
	}
	printf("your intput is:\n");
	for (j; j < i; j++) {
		printf("%s", str[j]);
	}
	
}

void cpp8_11_4() {

	char text[10][100] = { "" };
	char* pword = NULL;
	int nword[100] = { 0 };
	char buf[100] = "";
	char words[100][100] = { "" };
	char delimiter[] = " ,.?!;:)(\n";
	char res[100][100] = { "" };
	int i=0, j=0;
	int word_count = 0;
	int total_chr = 0;
	int word_chr = 0;
	int word_chr_avg = 0;
	printf("input:");
	while (fgets(buf, 100, stdin) != EOF) {
		strcpy(text[i++], buf);
		if (buf[0] == '\n' || i > 9) {
			break;
		}
		printf("input:");
	}
	for (j=0; j < i; j++) {
		pword = strtok(text[j], delimiter);
		//printf("%s ", pword);
		if (pword) {
			
			strcpy(words[word_count++], pword);
		}
		
		while (true) {
			pword = strtok(NULL, delimiter);
			if (pword ) {
				
				strcpy(words[word_count++], pword);	
			}
			else {
				break;
			}
			//printf("%s ", pword);

		}
	}
	printf("%d\n", word_count);
	int total_cnt = 0;
	strcpy(res[0], words[0]);
	total_cnt = 1;
	nword[0]++;
	for (i = 1; i < word_count; i++) {
		//printf("%s", words[a]);
		if (strlen(words[i]) <= 0)
			continue;
		for (j = 0; j < total_cnt; j++) {
			if (strcmp(res[j], words[i]) == 0) {
				nword[j]++;
				words[i][0] = '\0';
				break;
			}
		}
		if (j >= total_cnt) {
			//puts(text[i]);
			strcpy(res[total_cnt], words[i]);
			nword[total_cnt]++;
			total_cnt++;
			
		}
	}
	for (i = 0; i < total_cnt; i++) {
		printf("%-13s%d:%-5d ", res[i], strlen(res[i]), nword[i]);
		total_chr += strlen(res[i]);
		if ((i + 1) % 4 == 0) {
			printf("\n");
		}
	}

	word_chr_avg = total_chr / total_cnt;
	printf("\nthere %d total char,%d words, %d char per word", total_chr, total_cnt, word_chr_avg);
}
void count_words() {
	char text[10][15] = { "on","the","desk","\n","the","frank","hello","\n","frank"};

	char buf[10][15];
	int nword[10] = { 0 }, total_cnt = 0;
	int i, j;
	strcpy(buf[0], text[0]);
	total_cnt = 1;
	nword[0]++;

	for (i = 1; i < 10; i++) {
		if (strlen(text[i]) <= 1)
			continue;
		for (j = 0; j < total_cnt; j++) {
			if (strcmp(buf[j], text[i]) == 0) {
				nword[j]++;
				text[i][0] = '\0';
				break;
			}
		}
		if (j >= total_cnt) {
			//puts(text[i]);
			strcpy(buf[total_cnt], text[i]);
			nword[total_cnt]++;
			total_cnt++;
		}
	}

	for (i = 0; i < total_cnt; i++) {
		printf("%-13s %d:%-4d", buf[i], strlen(buf[i]), nword[i]);
	}

}
//8_11_5
void guess() {
	int guess = 1;
	char response;
	printf("Pick an integer from 1 to 100.I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\nan n if it is wrong.\n");
	printf("uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'y') {
		if (response == 'n') {
			printf("Well, then, is it %d?\n", ++guess);
		}
		else {
			printf("Sorry,I understand only y or n.\n");
		}
		while (getchar() != '\n') {
			continue;
		}
	}
}
void cpp8_11_5() {
	int data = 43;
	int guess = 0;
	int low = 0;
	int high = 100;
	printf("��������Ϸ��������һ��0 �� 100 ��������");
	while (true) {
		scanf("%d", &guess);
		if (guess > data) {
			high = guess;
			printf("�´��ˣ��ٲ�һ�Σ�%d �� %d) :", low, high);
		}
		else if(guess < data){
			low = guess;
			printf("��С�ˣ��ٲ�һ�Σ�%d �� %d) :", low, high);

		}
		else {
			printf("������");
			break;
		}
	}
}

//8_11_6
void menutte() {
	char get_choice(void);
	char get_first(void);
	int get_int(void);
	void count(void);

	int choice;
	//void count(void);

	while ((choice = get_choice()) != 'q') {
		switch (choice) {
		case 'a': printf("Buy low,sell high.\n");
				break;
		case 'b': putchar('\a');
				break;
		case 'c': count();
				break;
		default: printf("Program error!\n");
				break;
		}
	}
	printf("Bye.\n");
}
void count(void) {
	int n, i;
	printf("Count how far? Enter an integer:\n");
	n = get_int();
	for (i = 1; i < n; i++) {
		printf("%d\n", i);
	}
	while (getchar() != '\n') {
		continue;
	}
}
char get_choice(void) {
	int ch;
	printf("Enter the letter of your choice:\n");
	printf("a. advice\t\tb. bell\n");
	printf("c. count\t\tq. quit\n");
	ch = get_first();
	while ((ch < 'a' || ch > 'c') && ch != 'q') {
		printf("Please respond with a, b, c, or q.\n");
		ch = get_first();
	}
	return ch;
}
char get_first(void) {
	int test = getchar();
	while (!isalpha(test) && test == '\n') {
		//printf("Enter error,reinput:");
		test = getchar();
		continue;
	}
	return test;
}
int get_int(void) {
	int input;
	char ch;
	while (scanf("%d", &input) != 1) {
		while ((ch = getchar()) != '\n') {
			putchar(ch);
		}
		printf(" is not an integer.\nPlease enter an  ");
		printf("integer value,such as 25, -178, or 3: ");
	}
	return input;
}

//8_11_8
void cpp8_11_8() {
	char ch;
	char menue();
	void add();
	void subtract();
	void multiply();
	void divide();

	while ((ch = menue()) != 'q') {
		switch (ch) {
		case 'a':add();
			break;
		case 's':subtract();
			break;
		case 'm':multiply();
			break;
		case 'd':divide();
			break;
		default: printf("Please respond with a, s, m, d, or q.\n");
			break;
		}
	}
}

char menue() {
	char choice;
	printf("************************************************\n");
	printf("%-9s%-15s%15s", " ", "a. add","s. subtract\n");
	printf("%-9s%-15s%13s%-9s%-15s", " ", "m. multiply","d. divide\n"," ", "q. quit");
	printf("\n");
	printf("************************************************\n");
	printf("Please enter your choice:");
	choice = get_first();
	//printf("%c\n", choice);
	while (choice == '\n') {
		choice = get_first();
	}
	return choice;
}
float get_num() {
	float num;
	char ch;
	while (scanf("%f", &num) != 1) {
		while ((ch = getchar()) != '\n') {
			putchar(ch);
		}
		printf(" is not an number.\n");
		printf("Please enter a number,such as 2.5,-1.78E8, or 3:");
	}
	return num;
}
void add() {
	printf("Enter first number:");
	float num1 = get_num();
	printf("Enter second number:");
	float num2 = get_num();
	printf("%f + %f = %f\n",num1,num2, (num1 + num2));
}

void subtract() {
	printf("Enter first number:");
	float num1 = get_num();
	printf("Enter second number:");
	float num2 = get_num();
	printf("%f - %f = %f\n",num1,num2, (num1 - num2));
}

void multiply() {
	printf("Enter first number:");
	float num1 = get_num();
	printf("Enter second number:");
	float num2 = get_num();
	printf("%f * %f = %f\n",num1,num2,(num1 * num2));
}
void divide() {
	printf("Enter first number:");
	float num1 = get_num();
	printf("Enter second number:");
	float num2;
	while ((num2 = get_num()) == 0) {
		printf("Enter a number other than 0:");
	}
	printf("%f / %f = %f\n", num1,num2,(num1 / num2));
}
int main() {

	//cpp8_11_1();
	//cpp8_11_2();
	//cpp8_11_3();
	//cpp8_11_4_1();
	//from_scanf_to_store();
	//cpp8_11_4();
	//test_strcpy();
	//count_words();
	//guess();
	//cpp8_11_5();
	//menutte();
	cpp8_11_8();
	return 0;
}