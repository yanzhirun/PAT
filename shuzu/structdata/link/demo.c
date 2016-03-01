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
		printf("failure!!\n");
		exit(0);
	}
	if(single_link != NULL)
	{
		single_link -> head = NULL;
	}

	return single_link;
}

struct Stu * node_create()
{
	struct Stu * node;
	if((node = (struct Stu *) malloc (sizeof(struct Stu))) == NULL)
	{
		printf("failure!!\n");
		exit(0);
	}	
	
	if(node != NULL)
	{
		node -> next = NULL;
		printf("please input name score of student:");
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
	}

	return ;
}

struct Stu * node_search(struct Stu_head * single_link, char * name)
{
	struct Stu * pos = NULL;
	pos = single_link -> head;
	while(pos != NULL)
	{
		if(strcmp(pos -> name, name) == 0)
			return pos;
		else
			pos = pos -> next;
	}

	if(pos == NULL)
	{
		printf("find no one matched!\n");
		exit(0);
	}
	
	return NULL;
}

void node_insert(struct Stu * pos)
{
	struct Stu * new_node;
	
	printf("please insert one:");
	new_node = node_create();

	new_node -> next = pos -> next;
	pos -> next = new_node;

	return ;
}

void node_print(struct Stu_head * single_link)
{
	struct Stu * iter = single_link -> head;
	
	while(iter != NULL)
	{
		printf("%s 's score is:%d\n",&iter -> name,&iter -> score);
		iter = iter -> next;
	}
	
	return ;
}

void delete_node(struct Stu_head * single_link, struct Stu * node)
{
	struct Stu * node_prev, * tmp;
	tmp = single_link -> head;
	if(tmp == node)
		single_link -> head =tmp -> next;
	else
	{
		while(tmp != node)
		{
			node_prev = tmp;
			tmp = tmp -> next;
		}
		node_prev -> next = tmp -> next;
	}
	tmp -> next = NULL;
	free(tmp);

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
	char name[10];
	struct Stu * search_node;
	struct Stu_head * single_head = head_create();
	for(i = 0; i < N; i++)
		node_append(single_head);

	node_print(single_link);
	
	printf("please input the name you want to search in nodes:");
	scanf("%s",name);
	search_node = node_search(single_head, name);

	node_insert(single_head);
	
	printf("\nafter insert the node\n");
	node_print(single_head);
	
	delete_node(single_head, search_node);
	
	printf("\ndelete the node\n");
	node_print(single_head);

	single_link_destory(single_head);

	return 0;
}

