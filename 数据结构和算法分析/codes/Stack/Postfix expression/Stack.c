#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL)
        printf("Out of space");

    S->Next = NULL;
    return S;
}

void DisposeStack(Stack S)
{
    PtrToNode P, Temp;

    P = S->Next;
    S->Next = NULL;
    while (P != NULL)
    {
        Temp = P->Next;
        free(P);
        P = Temp;
    }
    free(S);
}

void MakeEmpty(Stack S)
{
    if (!IsEmpty(S))
    {
        PtrToNode P, Temp;

        P = S->Next;
        S->Next = NULL;
        while (P != NULL)
        {
            Temp = P->Next;
            free(P);
            P = Temp;
        }
    }
}

void Push(ElementType X, Stack S)
{
    PtrToNode TempNode = (PtrToNode) malloc(sizeof(struct Node));
    if (TempNode == NULL)
    {
        printf("Out of space");
    }
    else
    {
        TempNode->Element = X;
        TempNode->Next = S->Next;
        S->Next = TempNode;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Next->Element;
    printf("Empty Stack");

    return 0;
}

ElementType Pop(Stack S)
{
    PtrToNode FirstNode;
    ElementType TopElement;

    if (IsEmpty(S))
    {
        printf("Empty Stack");
        return 0;
    }
    else
    {
        FirstNode = S->Next;
        TopElement = FirstNode->Element;
        S->Next = FirstNode->Next;
        free(FirstNode);
        return TopElement;
    }
}
