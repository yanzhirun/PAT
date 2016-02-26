#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	N 	3

struct Stu
{
	struct Stu * next;
	char name[10];
	int score;
};

struct Stu_head
{
	struct Stu * head;
};

struct Stu_head * head_create()
{
	struct Stu_head * single_link;
	if((single_link = (struct Stu_head *)malloc(sizeof(struct Stu_head))) == NULL)
	{
		printf("failure!");
		exit(0);
	}

	if(single_link != NULL)
	{
		single_link -> head = NULL;
	}
	return single_link;
}

struct Stu *node_create()
{
	struct Stu * node;
	if((node = (struct Stu *)malloc(sizeof(struct Stu))) == NULL)
	{
		printf("failure!!");
		exit(0);
	}
	
	if(node != NULL)
	{
		node -> next =NULL;
		printf("please input name and score:\n");
		scanf("%s%d",&node -> name, &node -> score);
	}

	return node;
}

void node_append(struct Stu_head * single_link)
{
	struct Stu * node = NULL;
	struct Stu * cursor = NULL;

	node = node_create();

	if(single_link -> head == NULL)
	{
		single_link -> head = node;
	}
	else
	{
		cursor = single_link -> head;
		while(cursor != NULL && cursor -> next != NULL)
		{
			cursor = cursor -> next;
		}
		cursor -> next = node;
	}

	return ;
}

void node_print(struct Stu_head * single_link)
{
	struct Stu * iter = single_link -> head;

	while(iter != NULL)
	{
		printf("%s score:%d\n",iter -> name,iter -> score);
		iter = iter -> next;
	}
	return ;
}

void node_destory(struct Stu * node)
{
	if(node != NULL)
	{
		node -> next = NULL;
		free(node);
	}
	return ;
}

void single_link_destory(struct Stu_head * single_link)
{
	struct Stu * iter = single_link -> head;
	struct Stu * next = NULL;
	
	while(iter != NULL)
	{
		next = iter -> next;
		node_destory(iter);
		iter = next;
	}

	single_link -> head = NULL;
	free(single_link);
	
	return ;
}

int main()
{
	int i;
	struct Stu_head * single_head = head_create();
	for(i = 0; i < N; i++)
		node_append(single_head);
	node_print(single_head);
	
	single_link_destory(single_head);

	return 0;
}

