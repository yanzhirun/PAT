#include <stdio.h>

int main()
{
	int a;
	int *pa;
	pa = &a;
	a = 0x11223344;

	if(0x44 == *(char*)pa)
		printf("小端模式\n");
	else
		printf("大端模式\n");
	return 0;
}
