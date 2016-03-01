#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

void main()
{
	int *a[M],b[M][N];
	int i,j;

	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			b[i][j] = i + j;
		}
	}	

	for(i = 0; i < M; i++)
	{
		a[i] = b[i];
	}

	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("a[%d][%d] = %d\t",i,j,a[i][j]);
		}
		printf("\n");
	}


	
	return ;
}
