#include <stdio.h>

void main()
{
	char *str = "aaaabbbb1111caacaacaacaadddd44de";
	int *ptr;
	ptr = (int *)str;
	while(*ptr != '\0')
	{
		printf("%s\n",ptr);
		ptr++;
	}
	return ;
}
