#include <stdio.h>
#include <stdlib.h>

#define N 4

struct stu{
	char *name;
	char *num;
	double score;
	char *sex;
	int age;
}per[N]={
	{"zhang11","201611",333.3,"nv",22},
	{"fan222","2016222",222.2,"nan",33},
	{"wang333","2016333",444.4,"nan",25},
	{"guo444","2016555",123.1,"nv",19}
};

void sort(struct stu *p_per, int n)
{
	int i,j,k;
	struct stu temp;
	
	for(i = 0; i < n - 1; i++)
	{
		k = i;
		for(j = j + 1; j < n; j++)
		{
			if(p_per[j].score > p_per[k].score)
				k = j;
		}
		if(k != i)
		{
			temp = p_per[i];
			p_per[i] = p_per[k];
			p_per[k] = temp;
		}
	}

	return;
}

void print(struct stu *p_per, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("name:%s\tnum:%s\tscore:%.2lf\tsex:%s\tage:%d\n",p_per->name,p_per->num,p_per->score,p_per->sex,p_per->age);
		p_per++;
	}
	return;
}

void main()
{
	sort(per,N);
	print(per,N);

	return;
}


