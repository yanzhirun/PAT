#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void main()
{
	int *a[N];
	int i,j;

	for(i = 0; i < 3; i++)
	{
		if((a[i] = (int *)malloc(M*sizeof(int))) == NULL)
		{
			printf("failure!");
			exit(0);
		}
	}

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			a[i][j] = i * M + j + 1;
			printf("a[%d][%d] = %d\t",i,j,a[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < N; i++)
		free(a[i]);


	return ;
}
