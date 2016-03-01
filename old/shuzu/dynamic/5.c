#include <stdio.h>

void main(int argc, char *argv[])
{
	while(argc > 0)
	{
		printf("%s\t",*argv++);
		argc--;
	}

	return ;
}

