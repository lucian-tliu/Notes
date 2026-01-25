#include "LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

// 定义节点
struct Node
{
    int Element;
    struct Node* Next;
};

// 创建并初始化一个空链表
List MakeEmpty(List L)
{
    if (L != NULL)
        DeleteList(L);

    L = (List)malloc(sizeof(struct Node));
    if (L == NULL)
        printf("Out of space");

    L->Next = NULL;
    return L;
}

// 判断List是否为空
int IsEmpty(List L)
{
    return L->Next == NULL;
}

// 判断P是否为最后一个节点
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

// 查找元素X的位置
Position Find(int X, List L)
{
    Position P;

    P = L->Next;
    while (P->Next != NULL && P->Element != X)
    {
        P = P->Next;
    }

    return P;
}

// 查找元素X的前一个节点的地址
Position FindPrevious(int X, List L)
{
    Position P;

    P = L->Next;
    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }

    return P;
}

// 删除X元素对应的节点
void Delete(int X, List L)
{
    Position P, TempCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        TempCell = P->Next;
        P->Next = TempCell->Next;
        free(TempCell); // 不要忘记释放资源
    }
}

// 在位置P后面插入新节点
void Insert(int X, List L, Position P)
{
    struct Node* TmpCell;

    TmpCell = (struct Node*)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        printf("Out of space");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

// 删除整个链表
void DeleteList(List L)
{
    Position P, Temp;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Temp = P->Next;
        free(P);
        P = Temp;
    }
}

// 获取链表头节点
Position Header(List L)
{
    return L;
}

// 获取链表第一个节点
Position First(List L)
{
    return L->Next;
}

// 获取下一个节点
Position Advance(Position P)
{
    return P->Next;
}

// 获取节点P的元素值
int Retrieve(Position P)
{
    return P->Element;
}

// 打印链表中的所有元素
void PrintList(List L)
{
    Position P;

    P = L->Next;
    while (P != NULL)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}