#include <stdio.h>

struct stu1
{
	char * array[7];
	int a;
}stu1;

struct stu2
{
	char* array[7];
}stu2;

void main()
{
	printf("sizeof(stu2)=%d\n",sizeof(stu2));
	printf("sizeof(stu1)=%d\n",sizeof(stu1));
	return ;
}

