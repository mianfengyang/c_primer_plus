#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


//cpp13.11.1
void cpp13_11_1() {
	char fullpath[100] = "E:/project/cpp/files/";
	int ch;
	FILE* fp;
	char str[64] = { 0 };
	printf("请输入你的文件名:");
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
	char fullpath[100] = "E:/project/cpp/files/";
	FILE* fp1, *fp2;
	char filename[50] = { 0 };
	
	char ch;
	int i = 0;
	char buf[1024] = { 0 };
	printf("请输入文件名:");
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


void cpp13_11_6() {
	char fullpath[100] = "E:/project/cpp/files/";
	FILE* in, * out;
	int ch;
	char name_in[50] = { 0 };
	char name_out[50] = { 0 };
	int count = 0;
	printf("请输入源文件名：");
	scanf("%s", name_in);
	//printf("请输入目标文件名??);
	strcpy(name_out, name_in);
	strcat(name_out, ".red");
	if (name_in != NULL) {
		strcat(fullpath, name_in);
		if ((in = fopen(fullpath, "r")) == NULL) {
			fprintf(stderr, "Can't open %s file\n", name_in);
			exit(EXIT_FAILURE);
		}
		//fullpath[100] = "E:\\project\\cpp\\files\\";
		strcat(fullpath, ".red");
		printf("新文件名: %s \n", fullpath);
		out = fopen(fullpath, "w+");
		while ((ch = getc(in)) != EOF) {
			if (count++ % 3 == 0) {
				putc(ch, out);
			}
		}
		printf("\n源文件的内容为：\n");
		fseek(in, 0l, SEEK_SET);
		while ((ch = getc(in)) != EOF){
			printf("%c", ch);
		}
		printf("\n\n新文件的内容为：\n");
		fseek(out, 0l, SEEK_SET);
		while ((ch = getc(out)) != EOF) {
			printf("%c", ch);
		}
		if (fclose(in) != 0 || fclose(out) != 0) {
			fprintf(stderr, "Error in closing files\n");
		}
	/*	out = fopen(fullpath, "r");
		
		fclose(out);*/
		printf("\n\nDone!\n");
	}
	else {
		printf("源文件名不能为空！\n");
	}
}

//13.11.7
void cpp13_11_7() {
	char prePath[100] = "E:/project/cpp/files/";
	FILE* fp1, * fp2;
	char file1_name[64] = { 0 };
	char file2_name[64] = { 0 };
	char file1_buf[1024] = { 0 };
	char file2_buf[1024] = { 0 };
	printf("请输??个文件名(空格隔开）：");
	scanf("%s%s", file1_name, file2_name);
	

	if (file1_name != NULL && file2_name != NULL) {
		strcat(prePath, file1_name);
		fp1 = fopen(prePath, "r");
		char prePath[100] = "E:\\project\\cpp\\files\\";
		strcat(prePath, file2_name);
		fp2 = fopen(prePath, "r");
		if (fp1 == NULL) {
			fprintf(stderr, "Can't open %s file\n", file1_name);
			exit(EXIT_FAILURE);
		}
		if (fp2 == NULL) {
			fprintf(stderr, "Can't open %s file\n", file2_name);
			exit(EXIT_FAILURE);
		}
		while (1) {
			int len = 0;
			if (feof(fp1)) {
				printf("%s end  ", file1_name);
			}
			else {
				fgets(file1_buf, 1024, fp1);
				len = strlen(file1_buf);
				file1_buf[len - 1] = 0;
				//去掉每行的换行符，便可以将2个文件中的每一行 只显示在一行
				printf("%s", file1_buf);
			}
			if (feof(fp2)) {
				printf("%s end  ", file2_name);
			}
			else {
				fgets(file2_buf, 1024, fp2);
				len = strlen(file2_buf);
				file2_buf[len - 1] = 0;
				printf("%s", file2_buf);
			}
			printf("\n");
			if (feof(fp1)  && feof(fp2)) {
				break;
			}
		}
		fclose(fp1);
		fclose(fp2);
	}
	else {
		printf("源文件名不能为空！\n");
	}
	
}

int main(int argc, char* argv[]) {
	//cpp13_11_1();
	//cpp13_11_3();
	//cpp13_11_6();
	cpp13_11_7();
	return 0;
}