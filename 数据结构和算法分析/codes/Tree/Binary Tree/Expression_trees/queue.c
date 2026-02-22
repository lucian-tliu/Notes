#include "queue.h"

// .c 文件代码：(动态分配)数组方式的实现
#define MintackSize (5) // 加括号是为了防止运算顺序的错误
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int QueueIsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    Q->Capacity = MaxElements;
    QueueMakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

void QueueMakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

// 形成循环队列
static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        printf("Full Queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

void Dequeue(Queue Q)
{
    if (QueueIsEmpty(Q))
        printf("Empty Queue");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType Front(Queue Q)
{
    if (QueueIsEmpty(Q)) {
        printf("Empty Queue");
        return NULL;
    }
    return Q->Array[Q->Front];
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q);
    Dequeue(Q);
    return X;
}