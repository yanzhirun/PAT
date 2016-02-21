#include <stdio.h>

int main()
{



/*
        int *pa = (int *)malloc(sizeof(int)*4);
        int i;
        for (i = 0; i < 4; i++)
	{
		*(pa + i) = i + 1;
		printf("*(pa+%d) = %d \n",i,*(pa + i));
	}
	free(pa);
*/

/*大端 小端
	int a;
	int *pa;
	pa = &a;
	a = 0x11223344;
	if(0x44 == *(char*)pa)
		printf("xiaoduan\n");
	else
		printf("daduan\n");
*/
/*	char a[4];
	char (*pa)[4],*pb;

	pa = &a;
	pb = &a[0];
	printf("char pa size :%d\n",sizeof(*pa));
	printf("char pb size :%d\n\n",sizeof(*pb));
	printf("pa = %d \t pa + 1 = %d\n",pa,pa+1);
	printf("pb = %d \t pb + 1 = %d\n",pb,pb+1);
*/
	return 0;
}
