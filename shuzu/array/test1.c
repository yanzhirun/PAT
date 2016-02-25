#include <stdio.h>

int main()
{
	int a[4];
	int i;
	int *pa;
	int *pb;

	for (i = 0; i < 4; i++)
	{
		a[i] = i *2;
	}
	printf("a的首地址为%d\n",a);
	pa = a;
	for(i = 0; i < 4; i++)
		printf("a[%d] = %d\t",i,*(pa+i));
	printf("\n*(pa+i)间接引用a中pa值为：%d\n",pa);
	
	pb = a;

	for(i = 0;pb < pa+4; )
		printf("a[%d] = %d\t",i,*pb++);
	printf("\n*(pa+i)间接引用a中pb为：%d\n",pb);
	


	return 0;
}
