#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void append(FILE* source, FILE* dest) {
	size_t bytes;
	static char temp[4096];
	while ((bytes = fread(temp, sizeof(char), 4096, source))) {
		fwrite(temp, sizeof(char), bytes, dest);
	}
}

int main(int argc, char* argv[]) {
	FILE* fdst, * fs;
	int files = 0;
	int ch;
	char fullpath[100] = "E:\\project\\cpp\\files\\";
	
	puts("Enter name of first source file and dst file (empty line to quit):");
	if (argc < 3) {
		printf("Usage: source filename destionation file.\n");
		exit(EXIT_FAILURE);
	}
	else {
		strcat(fullpath, argv[argc - 1]);
		fdst = fopen(fullpath, "a+");
		for (int i = 1; i < argc-1; i++) {
			char fullpath[100] = "E:\\project\\cpp\\files\\";
			strcat(fullpath, argv[i]);
			if (strcmp(fullpath, argv[argc-1]) == 0) {
				fputs("Can't append file to itself\n", stderr);
			}
			else if ((fs = fopen(fullpath, "r")) == NULL) {
				fprintf(stderr, "Can't open %s\n", argv[i]);
			}
			else {
				if (setvbuf(fs, NULL, _IOFBF, BUFSIZ) != 0) {
					fputs("Can't creat input buffer\n", stderr);
				}
				
				append(fs, fdst);
				if (ferror(fs) != 0) {
					fprintf(stderr, "Error in reading file %s", argv[i]);
				}
				if (ferror(fdst) != 0) {
					fprintf(stderr, "Error in writing file %s", argv[argc-1]);
				}
				fclose(fs);
				files++;
				printf("File %s appended.\n", argv[i]);
				
			}
		}
		printf("Done appending. %d files appended.\n", files);
		rewind(fdst);
		printf("%s contents:\n", argv[argc - 1]);
		while ((ch = getc(fdst)) != EOF) {
			putchar(ch);
		}
		puts("\n\nDone displaying.\n");
		fclose(fdst);
	}

	return 0;
}