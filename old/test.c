#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a = 1,*pa;
	int b = 2,*pb;
	double c = 3,*pc;
	pa = &a;
	pb = &b;
	pc = &c;
	printf("char pa size : %d\n",sizeof(pa));
	printf("char pb size : %d\n",sizeof(pb));
	printf("char pc size : %d\n",sizeof(pc));

	printf("char  size of (*pa):%d\n",sizeof(*pa));
	printf("char  size of (*pb):%d\n",sizeof(*pb));
	printf("char  size of (*pc):%d\n",sizeof(*pc));

	printf("char a address:%d\n",pa);
	printf("char b address:%d\n",pb);
	printf("char c address:%d\n",pc);
	
	return 0;
}
