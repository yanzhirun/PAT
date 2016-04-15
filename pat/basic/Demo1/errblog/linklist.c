#include "stdlib.h"
#include "stdio.h"

typedef struct Node
{
    int Address;
    int Data;
    int Next;
    struct Node *p_next;
}SLIST;

SLIST *Creat_SList(int N)
{
    //建立带有头结点
    int i;
    int Address = 0, Data = 0, Next = 0;
    SLIST *pHead = NULL, *pM = NULL, *pCur;
    pHead = (SLIST *)malloc(sizeof(SLIST));
    pHead -> Data = 0;
    pHead -> p_next = NULL;

    //循环创建 N 个节点，结点数据域从键盘输入
    pCur = pHead;

    for (i = 0; i < N; i++)
    {
        pM = (SLIST *)malloc (sizeof (SLIST));
        if (pM == NULL)
        {
            SList_destory(pHead);
            return NULL;
        }
        printf ("\nPlease enter the data of node(Address Data Next):\n");
        scanf("%d%d%d", &Address, &Data, &Next);
        pM -> Address = Address;
        pM -> Data = Data;
        pM -> Next = Next;
        pM -> p_next = NULL;
        //新结点入链
        pCur->p_next = pM;
        //新结点变成当前结点
        pCur = pM;
        //新结点入链
    }
    //-1 作为输入结束标志
    //malloc新结点 新结点入链表

    return pHead;
}

    int SList_destory (SLIST *pHead, int y)
{
     SLIST *pCur = NULL, *pPre = NULL;
     if (pHead == NULL)
     {
         return -1;
     }

     pPre = pHead;
     pCur = pHead->p_next;

     while (pCur)
     {
          if (pCur->Data == y)
          {
              break;
          }
          pPre = pCur;
          pCur = pCur->p_next;
     }
     if (pCur == NULL)
     {
          printf ("no node\n");
          return -2;
     }
     pPre->p_next = pCur->p_next;
     free(pCur);

     return 0;
}

int SList_print(SLIST *pHead)
{
    SLIST *p = NULL;
    if (pHead == NULL)
    {
        return -1;
    }
    p = pHead->p_next;
    printf ("\nBegin:\n");
    while (p)
    {
        printf ("%d %d %d\n", p->Address, p->Data, p->Next);
        p =p->p_next;
    }
    printf ("\nEnd\n");

    return 0;
}

int SList_Node_Insert(SLIST *pHead, int x, int Address, int Data, int Next)
{
    SLIST *pCur = NULL, *pPre = NULL, *pM = NULL;
    if (pHead == NULL)
    {
        return -1;
    }
    pPre = pHead;
    pCur = pHead -> p_next;
    pM = (SLIST *)malloc(sizeof(SLIST));
    pM -> Address = Address;
    pM -> Data = Data;
    pM -> Next = Next;
    pM -> p_next = NULL;

    while (pCur)
    {
        if (pCur -> Data == x)
        {
            break;
        }
        pCur = pCur -> p_next;
    }
    pM -> p_next = pPre -> p_next;
    pPre -> p_next = pM;

    return 0;
}

int main()
{
    SLIST *pHead = NULL;
    int N,i;
    scanf ("%d", &N);
    pHead = Creat_SList(N);
    SList_print (pHead);


    return 0;
}
