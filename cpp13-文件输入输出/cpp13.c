#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

extern char fullpath[100] = "E:\\project\\cpp\\files\\";
//cpp13.11.1
void cpp13_11_1() {
	int ch;
	FILE* fp;
	char fullpath[512] = "E:\\project\\cpp\\cpp13-文件输入输出\\";
	char str[64];
	printf("请输入你的文件名：");
	scanf("%s", str);
	strcat(fullpath, str);
	unsigned long count = 0;
	if (str == NULL) {
		printf("Usage: %s filename\n", str);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(fullpath, "r")) == NULL) {
		printf("Can't open %s\n", fullpath);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", fullpath, count);
}
void cpp13_11_3() {
	FILE* fp1, *fp2;
	char filename[50] ;
	
	char ch;
	int i = 0;
	char buf[1024] = { 0 };
	printf("请输入文件名：");
	scanf("%s", filename);
	strcat(fullpath, filename);
	//printf("%s\n", fullpath);
	if (filename == NULL) {
		printf("Usage: %s filename\n", filename);
		exit(EXIT_FAILURE);
	}
	if ((fp1 = fopen(fullpath, "r")) == NULL) {
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(fp1)) != EOF) {

		buf[i++] = toupper(ch);
	}
	//printf("%s\n", buf);
	fclose(fp1);
	fp1 = NULL;
	fp2 = fopen(fullpath, "w");
	fputs(buf, fp2);
	/*for (int j = 0; j < strlen(buf); j++) {
		fputc(buf[j], fp2);
	}*/
	fclose(fp2);
	fp2 = NULL;
	
}
void append(FILE* source, FILE* dest) {
	size_t bytes;
	static char temp[4096];
	while ((bytes = fread(temp, sizeof(char), 4096, source))) {
		fwrite(temp, sizeof(char), bytes, dest);
	}
}
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
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
void cpp13_11_5() {
	
}
int main(int argc, char* argv[]) {
	//cpp13_11_1();
	//cpp13_11_3();
	cpp13_11_5();
	return 0;
}