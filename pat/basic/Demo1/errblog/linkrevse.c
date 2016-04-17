#include "stdlib.h"
#include "stdio.h"

typedef struct LINK
{
    int Address;
    int Data;
    int Next;
    struct LINK* p_next;
}LINK;

LINK *creat_link(int N)
{
    int i;
    //创建头结点 初始化
    int Address = 0, Data = 0, Next = 0;
    LINK *pHead = NULL, *pM = NULL, *pCur;
    pHead = (LINK*)malloc(sizeof(LINK));
    if (NULL == pHead)
    {
        printf("func creat_link err");
        return NULL;
    }
    pHead->Address = 0;
    pHead->Data = 0;
    pHead->Next = 0;
    pHead->p_next = NULL;

    //循环创建结点，结点数据从键盘输入
    pCur = pHead;
    for (i = 0; i < N; i++)
    {
        pM = (LINK*)malloc(sizeof(LINK));
        if (NULL == pM)
        {
            printf("func creat_link err\n");
            return NULL;
        }
        scanf("%d%d%d", &Address, &Data, &Next);
        pM->Address = Address;
        pM->Data = Data;
        pM->Next = Next;
        pM->p_next = NULL;
        pCur->p_next = pM;
        pCur = pM;
    }

    return pHead;
}

int link_print(LINK *pHead)
{
    LINK *p = NULL;
    if (NULL == pHead)
    {
        return -1;
    }
    p = pHead->p_next;
    printf ("start\n");
    while(p)
    {
        printf("%d %d %d\n", p->Address, p->Data, p->Next);
        p = p->p_next;
    }
    printf ("end\n");
        return 0;
}

int LINK_destory(LINK *pHead, int y)
{
     LINK *pCur = NULL, *pPre = NULL;
     if (pHead == NULL)
     {
         return -1;
     }


     return 0;
}

int link_change (LINK *pHead, int N, int K)
{
    int i;
    LINK *p = NULL, *q = NULL, *t = NULL;
    if (NULL == pHead)
    {
        printf ("link_change err\n");
        return 0;
    }
    if(NULL == pHead->p_next || NULL == pHead->p_next->p_next)
    {
        return 0;
    }
    p = pHead->p_next;
    q = pHead->p_next->p_next;

    while(NULL != q)
    {
        //逆置之前做一个缓存
        t = q->p_next;
        //逆置
        q->p_next = p;
        // p q 分别后移
        p = q;
        q = t;
    }

    pHead->p_next->p_next = NULL;
    pHead->p_next = p;

    return 0;
}

int main()
{
    int ret = 0, N, K;
    LINK *pHead = NULL;
    scanf ("%d", &N);
    pHead =creat_link(N);
    ret = link_print(pHead);
    link_change(pHead, N , K);
    ret = link_print(pHead);

    return 0;
}
