#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void main()
{
	char *str = "hello world !! !!  ";
	printf("%s\n",str);

	printf("*(str+3)=%c\t",*(str+3));
	printf("*str+3=%c\t",*str+3);
	printf("\n\n\n");
	while(*str != '\0')
		printf("%c+",*str++);	
	printf("\n");
	return ;
}
