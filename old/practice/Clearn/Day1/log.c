#include <stdio.h>

int main()
{
	int opt = 0;
	int continue_flag = 1;
	while(continue_flag)
	{
		printf("1.init student info\n");
		printf("2.print student info\n");
		printf("3.search student\n");
		printf("4.delete student\n");
		printf("0.exit\n");
		printf("please input choice:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("init info");
				break;
			case 2:
				printf("print info");
				break;
			case 3:
				printf("search\n");
				break;
			case 4:
				printf("delete\n");
				break;
			case 0:
				continue_flag = 0;
				printf("exit!\n");
				break;
			default:
				printf("wrong input!\n");
		}	
	}
}
