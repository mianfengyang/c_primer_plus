#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char * argv[]) {
	char ch;
	char str[100];
	char dst1[100];
	char dst2[100];
	int i = 0;
	int j = 0,k=0;
	int num = 0;
	char** p = &argv[1];
	printf("%s\n", *p);

	printf("please input:\n");
	while ((ch = getchar()) != '#') {
		if (i >= 99) {
			break;
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	setbuf(stdin, NULL);
	if (*p == NULL) {
		printf("%s\n", str);
	}
	else {
		for (num = 0; num < argc; num++) {
			if (strcmp(*p, "-u") == 0) {
				strcpy(dst1, str);
				for (; j < strlen(str); j++) {
					dst1[j] = toupper(str[j]);
				}
				dst1[j] = '\0';
				printf("%s\n", dst1);

			}
			if (strcmp(*p, "-l") == 0) {
				strcpy(dst2, str);
				for (; k < strlen(str); k++) {
					dst2[k] = tolower(str[k]);
				}
				dst2[k] = '\0';
				printf("%s\n", dst2);

			}
			if (strcmp(*p, "-p") == 0) {
				printf("%s\n", str);

			}
			p++;
			if (*p == NULL) {
				break;
			}
		}
	}
	return 0;
}