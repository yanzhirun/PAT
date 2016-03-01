#include <stdio.h>
#include <stdarg.h>


int max (int x, int y)
{
	return x>y?x:y;
}

int min(int x, int y)
{
	return x<y?x:y;
}

void main()
{
	int (*f)( int x, int y) = max;
	printf("max(2,6) = %d\t f(5,4) = %d\t\n",max (2,6),f(5,4));

	f = min;
	printf("min(2,6) = %d\t f(5,4) = %d\t\n",min(2,6),f(5,4));

	return ;
}

/*

void print(int n, ...)
{
	int arg, i;
	va_list p;
	va_start(p, n);
	for(i = 0; i < n; i++)
	{
		arg = va_arg(p, int);
		printf("%d\t",arg);
	}
	printf("\n");
	va_end(p);

	return ;
}

int main()
{
	print(3,32,11,545);

	return 0;
}
*/

