#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char * argv[]) {
	char ch;
	FILE* fp1,*fp2;
	
	if (argc < 3) {
		printf("Usage:source filename and dst filename!");
		exit(EXIT_FAILURE);
	}
	fp1 = fopen(argv[1], "rb");
	if (fp1 == NULL) {
		printf("Can't open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fp2 = fopen(argv[2], "wb");
	while ((ch = fgetc(fp1)) != EOF) {
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	fp1 = NULL;
	fp2 = NULL;
	return 0;
}