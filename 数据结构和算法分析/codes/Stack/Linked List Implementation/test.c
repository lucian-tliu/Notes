#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"

int main() {
    Stack S = CreateStack();
    printf("Stack is empty: %d\n", IsEmpty(S));

    Push(10, S);
    ElementType topElement = Top(S);
    printf("Top element: %d\n", topElement);

    ElementType poppedElement = Pop(S);
    printf("Popped element: %d\n", poppedElement);

    printf("Stack is empty: %d\n", IsEmpty(S));
    DisposeStack(S);

    return 0;
}