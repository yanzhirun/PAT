#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int test_yes_no(int num, char test[10][101])
{
	int err = 0;
	int i,j,k;
	int result;
	int length;
	//for (i = 0; i < num; i++)
	//	printf("%s ",test[i]);
//	printf("\n---------\n");

	for (i = 0; i < num; i++)
	{
		length = strlen(test[i]);
	//	printf("lengthof test[%d]:%d",i,length);
		for (j = 0; j < length; j++)
		{
//			printf("\n-------------\n");
//			printf("test[][]:%c\n",test[i][j]);
			if(test[i][j] == 'P' || test[i][j] == 'A' || test[i][j] == 'T')
			{			
//	printf("test[%d]:%sNO\n",i,test[i]);
			result = 1;
			}	
			else
			result =0;
		}
		if(result)
			printf("YES\n");
		else
		printf("NO\n");
	}	
	return err;
}
int main()
{
	int num, i;
	char test[10][101] = {0};
	scanf("%d",&num);
	for (i = 0; i < num; i++)
	{
		scanf("%s",test[i]);
	}

	test_yes_no(num, test);

	return 0;
}


