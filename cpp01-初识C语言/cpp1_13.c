#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cpp1_13() {
	float inch;
	float cm;
	printf("������Ҫת����Ӣ���С��");
	scanf_s("%f", &inch);
	cm = inch * 2.54;
	printf("%f Ӣ��ת����Ĵ�СΪ��%f ����", inch, cm);

	return 0;
}