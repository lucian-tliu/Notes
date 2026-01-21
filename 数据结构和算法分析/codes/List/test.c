#include "stdio.h"
#include "LinkedList.h"
#include "stdlib.h"

struct Node
{
    int Element;
    struct Node* Next;
};

int main()
{
    List L = NULL;
    Position P;
    int i;

    L = MakeEmpty(L);
    for (i = 1; i <= 10; i++)
    {
        Insert(i * 10, L, L); 
    }
    PrintList(L);

    P = Find(50, L);
    if (!IsLast(P, L))
    {
        printf("Found: %d\n", Retrieve(P));
    }
    else
    {
        printf("Not Found\n");
    }

    Delete(30, L);
    PrintList(L);

    DeleteList(L);
    return 0;
}