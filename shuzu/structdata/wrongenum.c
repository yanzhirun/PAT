#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

enum Bool{
	True,
	False
};

enum Bool is_number(char c)
{
	if(c >= '0' && c <= '9')
		return True;
	else
		return False;
}

void main()
{
	char c;
	enum Bool ret;
	while(1)
	{
		printf("\nInput:\n");
		c = getch();
		putchar(c);
		ret = is_number(c);
		if(ret)
			printf("\n输入的是数字");
		else
			printf("\n输入的是非数字");
	}
	
	return ;
}
