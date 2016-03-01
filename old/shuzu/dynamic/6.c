#include <stdio.h>

void copy_string(char from[], char to[])
{
	while(*to++ = *from++);

	return ;
}

void main()
{
	char str[] = "this is a string!!";
	printf("%s\n",str);
	char dec_str[50];

	copy_string(str, dec_str);
	printf("%s\n",dec_str);

	return ;
}


