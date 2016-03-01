#include <stdio.h>

void print(int n, ...)
{
	int *p,i;
	p = &n + 1;
	for (i = 0; i < n; i++)
		printf("%d\t",p[i]);
	printf("\n");

	return ;
}

int main()
{
	print(12,2,22,222223,332,3,32,2);

	return 0;
}

