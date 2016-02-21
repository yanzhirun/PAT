#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1,n2;
	int **arr,i,j;
	printf("行数");
	scanf("%d",&n1);
	printf("列数");
	scanf("%d",&n2);
	
	if((arr = (int**)malloc(n1*sizeof(int*))) == NULL)
	{
		printf("failure!");
		return 0;
	}
	
	for(i = 0; i < n1; i++)
	{
		if((arr[i] = (int*)malloc(n2*sizeof(int))) == NULL)
		{
			printf("failure!");
			return 0;
		}
	}
	
	for(i = 0; i < n1; i++)
	{
		for(j = 0; j < n2; j++)
		{
			arr[i][j] = i * n2 + j +1;
			printf("%d\t",arr[i][j]);
		}
	}

	for(i = 0; i < n1; i++)
	{
		free(arr[i]);
	}
	free(arr);

	return ;
}
