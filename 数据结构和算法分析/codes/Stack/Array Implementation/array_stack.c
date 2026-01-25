#include "array_stack.h"
#include <stdlib.h>

// .c 文件代码：(动态分配)数组方式的实现
#define EmptyTOS (-1)   // 加括号是为了防止运算顺序的错误
#define MintackSize (5) // 同上
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S;

    if (MaxElements < MintackSize)
        Error("Stack size if too small");

    S = (Stack)malloc(sizeof(struct StackRecord));
    if (S == NULL)
        FatalError("Out of space!!!");
    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
        FatalError("Out of Space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty stack");
    return 0; // Return value used to avoid warning
}

void Pop(Stack S)
{
    if (IsEmpty(S))
        Error("Empty stack");
    else
    {
        S->TopOfStack--;
    }
}

// 市面上很多教材都会把 Pop 和 Top 函数集成到 Pop 函数上
// 而本书的作者将两者分开，但他也提供了集成的版本(前面没有写函数原型)
ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty stack");
    return 0; // Return value used to avoid warning
}