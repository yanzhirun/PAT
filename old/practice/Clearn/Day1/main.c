#include <stdio.h>
#include <string.h>

#define ADMIN_USER_NAME "admin"
#define ADMIN_PASS_WORD "12345"

#define RETRY_NUM 3

int main()
{

	int input_count = 0;
	char username[20] = {0};
	char password[20] = {0};
	while(1)
	{

		printf("please input username:\n");
		scanf("%s",username);
		printf("please input password:\n");
		scanf("%s",password);
		if(strcmp(username,ADMIN_USER_NAME) == 0
			&& strcmp(password,ADMIN_PASS_WORD) == 0)
		{
			printf("usename and password corrct\n");
			break;
		}
		else
		{
			input_count++;
			if(input_count >= RETRY_NUM)
			{
				printf("wrong 3 times. exit\n");
				return 1;
			}
			else
			{
				printf("wrong,please try again\n");
			}
		}
	}
	printf("start & operate\n");
}






