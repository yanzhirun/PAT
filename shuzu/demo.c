#include <stdio.h>
#include <stdlib.h>

void main()
{
	int *pa = (int *)malloc(sizeof(int)*9);
	int i;
	
	for(i = 0; i < 9; i++)
	{
		*(pa+i) = rand()%100;
		printf("*(pa+%d) = %d\t",i,*(pa+i));
		if((i+1)%3 == 0)
			printf("\n");
	}

	free(pa);

	int a =12;
	if(pa!=NULL)
	{
		pa = &a;
		printf("%d\n",*pa);
	}

//定义的指针指向一个不可用的内存，需要赋值为NULL
/*	int *pa;
	*pa = 10;
*/	
	return ;
}
