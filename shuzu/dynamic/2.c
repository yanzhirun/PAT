#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void main()
{
	int (*a)[N];
	int i,j;

	if((a =  (int(*)[N])malloc(N*M*sizeof(int))) == NULL)
	{
		printf("failure!");
		exit(0);
	}
	printf("4 X 3 数组 引用创建的数组\n");
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			a[i][j] = i * N + j + 1;
			printf("a[%d][%d] = %d\t",i,j,a[i][j]);
		}
		printf("\n");
	}

	printf("3 X 4 数组方式 引用所创建的数组\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			a[i][j] = i * M + j +1;
			printf("a[%d][%d] = %d\t",i,j,a[i][j]);
		}
		printf("\n");
	}
	free(a);
	
	return ;
}
