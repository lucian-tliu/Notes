#include <stdio.h>
#include <stdlib.h>
#include "cursor.h"

#define SPACE_SIZE 100

/* Cursor Node */
struct Node {
    int Element;
    int Next;     // Use int as cursor
};

/* Global cursor space */
static struct Node CursorSpace[SPACE_SIZE];

/* ========== Internal Functions ========== */

static void InitializeCursorSpace() {
    for (int i = 0; i < SPACE_SIZE - 1; i++)
        CursorSpace[i].Next = i + 1;
    CursorSpace[SPACE_SIZE - 1].Next = 0;
}

static int CursorAlloc() {
    int p = CursorSpace[0].Next;
    if (p != 0)
        CursorSpace[0].Next = CursorSpace[p].Next;
    return p;
}

static void CursorFree(int p) {
    CursorSpace[p].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = p;
}

/* ========== ADT API ========== */

List MakeEmpty(List L) {
    if (L != 0)
        DeleteList(L);

    int header = CursorAlloc();
    if (header == 0) {
        printf("Out of space!\n");
        exit(1);
    }

    CursorSpace[header].Next = 0;
    return header;
}

int IsEmpty(List L) {
    return CursorSpace[L].Next == 0;
}

int IsLast(Position P, List L) {
    return CursorSpace[P].Next == 0;
}

Position Find(int X, List L) {
    Position p = CursorSpace[L].Next;
    while (p != 0 && CursorSpace[p].Element != X)
        p = CursorSpace[p].Next;
    return p;
}

Position FindPrevious(int X, List L) {
    Position p = L;
    while (CursorSpace[p].Next != 0 &&
           CursorSpace[CursorSpace[p].Next].Element != X)
        p = CursorSpace[p].Next;
    return p;
}

void Delete(int X, List L) {
    Position p = FindPrevious(X, L);
    Position tmp;

    if (!IsLast(p, L)) {
        tmp = CursorSpace[p].Next;
        CursorSpace[p].Next = CursorSpace[tmp].Next;
        CursorFree(tmp);
    }
}

void Insert(int X, List L, Position P) {
    Position tmp = CursorAlloc();
    if (tmp == 0) {
        printf("Out of space!\n");
        return;
    }

    CursorSpace[tmp].Element = X;
    CursorSpace[tmp].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = tmp;
}

void DeleteList(List L) {
    Position p = CursorSpace[L].Next;
    Position tmp;

    while (p != 0) {
        tmp = p;
        p = CursorSpace[p].Next;
        CursorFree(tmp);
    }
    CursorSpace[L].Next = 0;
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return CursorSpace[L].Next;
}

Position Advance(Position P) {
    return CursorSpace[P].Next;
}

int Retrieve(Position P) {
    return CursorSpace[P].Element;
}

void PrintList(List L) {
    Position p = CursorSpace[L].Next;
    while (p != 0) {
        printf("%d ", CursorSpace[p].Element);
        p = CursorSpace[p].Next;
    }
    printf("\n");
}

/* ========== 初始化入口 ========== */

__attribute__((constructor))
static void Init() {
    InitializeCursorSpace();
}
