#include <stdio.h>

void copy (FILE * fpin, FILE * fpout)
{
	char ch;
	while((ch = getc(fpin)) != EOF)
	{
		putc (ch, fpout);
	}

	return ;
}

int main()
{
	FILE *fpin, *fpout;
//	char b = 0x34;
//	char a = 0xff;
	char a = 'a';
	char b = '3';
	fpin = fopen ("dat1.dat","wb");
	fpout = fopen ("dat2.dat","wb");
	fputc(b,fpin);
	fputc(a,fpin);
	fputc(b,fpin);
	fclose(fpin);
	fpin = fopen("dat1.dat","rb");
	copy(fpin,fpout);
	fclose(fpin);
	fclose(fpout);

	return 0;
}


