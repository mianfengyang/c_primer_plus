#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cpp1_13() {
	float inch;
	float cm;
	printf("请输入要转换的英寸大小：");
	scanf_s("%f", &inch);
	cm = inch * 2.54;
	printf("%f 英寸转换后的大小为：%f 厘米", inch, cm);

	return 0;
}