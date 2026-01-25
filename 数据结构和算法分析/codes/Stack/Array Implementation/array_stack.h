// .h 文件代码：栈 ADT 的类型声明
#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndTop(Stack S);

#endif /* _Stack_h*/