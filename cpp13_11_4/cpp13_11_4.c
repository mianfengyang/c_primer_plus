#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
	int i = 1;
	
	char buf[1024];
	FILE* fp;
	for (; i < argc; i++) {
		char fullpath[100] = "E:\\project\\cpp\\files\\";
		strcat(fullpath, argv[i]);
		fp = fopen(fullpath, "r");
		printf("文件 %s 的内容是：\n", argv[i]);
		while (fgets(buf, 1024, fp) != NULL) {
			fputs(buf, stdout);
		}
		fclose(fp);
		printf("\n");
	}
	printf("Done!");

	return 0;
}