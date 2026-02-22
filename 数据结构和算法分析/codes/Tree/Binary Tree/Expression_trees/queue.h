// .h文件代码：队列ADT的类型声明
#ifndef _Queue_h
#define _Queue_h

#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef TreeNode* ElementType;

int QueueIsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void QueueMakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* _Queue_h*/