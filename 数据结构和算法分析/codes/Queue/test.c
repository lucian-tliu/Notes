#include "queue.h"
#include "stdlib.h"
#include "stdio.h"

int main() {
    Queue q = CreateQueue(10);
    MakeEmpty(q);
    Enqueue(5, q);
    Enqueue(10, q);
    int front = Front(q);
    printf("Front element: %d\n", front);
    Dequeue(q);
    front = FrontAndDequeue(q);
    DisposeQueue(q);
    return 0;
}