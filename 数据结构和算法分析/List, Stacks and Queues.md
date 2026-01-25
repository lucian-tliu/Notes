# List, Stacks and Queues

## 1 Abstract Data Type (ADT)

数据类型(data type) = {对象(objects)} $\cup$ {操作(operations)}

**抽象数据类型(ADT)**是将**对象和运算的规范**（协议），以及它的**表示和具体实现**（用一种具体的语言实现）分离开来的一种做法。

## 2 List ADT

表(List)是一种线性的数据结构。

- Objects：$\{\text{item}_0,\ \text{item}_1,\ \dots,\ \text{item}_n\}$

- Operations：

  | length            | 获得list的长度      |
  | ----------------- | ------------------- |
  | print             | 打印list            |
  | make_empty        | 返回一个空的list    |
  | find $\bigstar$   | 访问第k项           |
  | insert $\bigstar$ | 在第k项后面插入元素 |
  | delete $\bigstar$ | 删除第k项           |
  | find_next         | 查找下一项          |
  | find_previous     | 查找上一项          |


### 2.1 简单的数组实现

数组实现下，List各元素在内存中是顺序储存的

- 数组大小在声明时确定，需要估计表的                                                         大下
- 访问元素 $O(1)$
- 修改元素（插入、删除）$O(N)$

对于频繁插入和删除的表，需要使用链表(Linked List)的形式

### 2.2 链表

- 链表相比数组占用空间更多（额外的指针域），但它不要求空间连续
- 链表查找时间慢（$O(N)$），但插入和删除很快（$O(1)$），通过下面图示可以较为直观地感受到
- 最后一项的指针指向 `NULL`
- 对于**头指针**，我们不将第一项作为头指针，而是采用一个**虚拟节点 (dummy node)**。这个节点数据域为空，指针指向列表中的第一项。这样做的好处是我们在处理头节点时不需要再单独写一个函数

插入：

<img src="./assets/Quicker_20240627_130525.png" alt="img" style="zoom:40%;" />

删除：

<img src="./assets/Quicker_20240627_130545.png" alt="img" style="zoom:40%;" />

代码实现：[List](./codes/List)

> [!caution]
>
> 使用链表常见的错误：
>
> - **内存访问错误 (memory access violation)** 或**段错误 (segmentation violation)**：可能因为错误的初始化，或者引用不存在的指针（该指针已被 `free()` 了）
>
> - 判断何时使用 `malloc()`
>
>   - 如果想要创建一个之前未声明的指向结构的指针，需要用到 `malloc()`
>
>   - 如果想要用指针遍历一遍链表，则无需使用 `malloc()`
>
>     > 注意：`malloc()` 是给指针分配存储空间，而不是用于结构的
>
> - 记得使用 `free()`，尤其是**删除**节点时，否则会带来严重后果

### 2.3 双向链表

图示：

<img src="./assets/Quicker_20240624_180251.png" alt="img" style="zoom:40%;" />

声明：

```c
typedef struct node *node_ptr;
typedef struct node
{
    node_ptr llink;
    element item;
    note_ptr rlink;
};
```

例子：

<img src="./assets/Quicker_20240624_180556.png" alt="img" style="zoom:60%;" />

作用：简化**删除**节点的过程（删除后面的节点不需要全部遍历）

### 2.3 Application

#### 2.3.1 Polynomial ADT

多项式数据结构

- Object：$P(x)=a_1 x^{e_1}+a_2 x^{e_2}+\cdots a_n x^{e_n}$，需要保存一组有序二元数 $\{\langle a_i,e_i|i=1,\cdots,n\rangle\}$

- Operation：

  | Finding degree  | 即 $\max(e_i)$ |
  | --------------- | -------------- |
  | Addition        | 两个多项式相加 |
  | Subtraction     | 两个多项式相减 |
  | Multiplication  | 相乘           |
  | Differentiation | 求导           |


代码实现：[Polynomial ADT](.\codes\Polynomial ADT)（使用数组实现）

#### 2.3.2 MultiLists

问题：有 40000 名学生和 2500 门课，要求列出每门课学生的名单，以及每位学生的课表。**本质**：稀疏矩阵的表示

一种方法是使用二维的列表：每个节点有两个指针：

- 一个指向选这门的的其他学生
- 一个指向这个学生选的其他课程

<img src="./assets/Quicker_20240308_214222.png" alt="img" style="zoom:66%;" />

实际实现较为复杂。实际上，工程上最常用的用来储存稀疏矩阵的数据结构是 CSR / CSC（压缩行 / 压缩列）。

#### 2.3.3 Cursor Implementation of Linked Lists

前面实现的链表中，每一次添加或者删除节点都会进行 `malloc` 或 `free`，这会有额外的开销。解决的办法就是在开始一次性申请需要的内存（称为 cursor space）

## 3 Stack ADT

### 3.1 ADT

**stack( 栈 )**：一种**LIFO(last-in-first-out，后进先出 )**的列表，即仅在有序列表的顶端 (top) 进行插入和删除操作

- Objects：有限的有序列表

- Operations：

  | `int IsEmpty(Stack S)`                    | 判断栈是否为空     |
  | ----------------------------------------- | ------------------ |
  | `Stack CreateStack()`                     | 创建一个空的栈     |
  | `DisposeStack(Stack S)`                   |                    |
  | `MakeEmpty(Stack S)`                      | 清空栈             |
  | `Push(ElementType X, Stack S)` $\bigstar$ | 将一个元素压入栈顶 |
  | `ElementType Top(Stack S)` $\bigstar$     | 给出栈顶的元素值   |
  | `Pop(Stack S)` $\bigstar$                 | 弹出栈顶元素       |

> [!caution]
>
> - 对**空**的栈使用 `Pop` 或 `Top` 操作将会引发**栈 ADT 错误**
> - 对**满**的栈使用 `Push` 操作将会引发**实现错误 (implementation error)**

### 3.2 Implementation

#### 3.2.1 Linker List Implementation

> [!note]
>
> **Push**：
>
> <img src="./assets/stack_push.gif" style="zoom:40%;" />
>
> **Pop**：
>
> <img src="./assets/stack_pop.gif" style="zoom:50%;" />

代码实现：[链表实现](.\codes\Stack\Linked List Implementation)

> [!note]
>
> 上面的代码中有一些缺点，就是 `Push` 和 `Pop` 操作中会有频繁的 `malloc` 和 `free`，会带来较大的开销。
>
> 改进的方法：额外创建一个栈，用于存放本来应该 `free()` 掉的空间，等到有新的元素需要 `push` 的时候就可以用这个“**回收站**”中的空间，而无需再使用 `malloc()`

#### 3.2.2 Array Implementation

```c
struct  StackRecord {
	int     Capacity ;              /* size of stack */
	int     TopOfStack;          /* the top pointer */
	/* ++ for push, -- for pop, -1 for empty stack */
	ElementType  *Array;    /* array for stack elements */
 }; 
```

代码实现：[数组实现](.\codes\Stack\Array Implementation)

> [!note]
>
> - 栈模型需要**封装**好。也就是说，除了栈相关函数外，代码的其他部分不能使用 `Array` 或 `TopOfStack` 的变量
> - 在执行 `Push` 和 `Pop` 前必须进行**错误检查**

### 3.3 Application

#### 3.3.1 Balancing Symbols

问题：一段文本中存在一些需要两两配对的符号，例如 `(),[],{},"",''`，我们想要检查表达式的括号是否匹配。

思路：

- 当遇到一个 `left (/[/{` 时，将它压入栈内
- 当遇到一个 `right )/]/}` 时，比较它和栈顶元素是否匹配
  - 匹配，pop出栈顶元素
  - 不匹配或者是空栈，Not balanced

```c
Algorithm
{
    Make an Empty stack S;
    while (read in a character c)
    {
        if (c in an opening symbol)
            Push(c, S);
        else if (c is a closing symbol)
        {
            if (S is empty)
            {
                ERROR;
                exit;
            }
            else // stack is okay
            {
                if (Top(S) does not match c)
                {
                    ERROR;
                    exit;
                }
                else 
                    Pop(S);
            }  // end else-stack is okay
        } // end else-if-closing symbol
    } // end while-loop
    if (S is not empty)
        ERROR;
}
```

#### 3.3.2 Postfix Evaluation

数学表达式通常由三种形式

| 名称               | 示例              | 优势           |
| ------------------ | ----------------- | -------------- |
| Infix expression   | a + b * c - d / e | 适合人类阅读   |
| Prefix expression  | - + a * b c / d e |                |
| Postfix expression | a b c * + d e / - | 适合计算机运算 |

后缀表达式的运算规则：

1. 从左向右扫描，遇到操作数(operands) 就压到栈中
2. 遇到运算符，弹出栈顶的两个元素做运算，再将结果压回栈中
3. 扫描结束后，栈中剩下的数就是运算结果

<img src="./assets/postfix_compute.gif" style="zoom:66%;" />

前缀表达式只需要变为从右向左扫描。

#### 3.3.3 Infix to Postfix

为便于人类阅读，中缀表达式更为常见，因此需要做从中缀到后缀的转换。观察前面的后缀表达式可以发现

- 操作数的顺序不变
- 优先级更高的运算符先出现

因此可以得到对于简单的四则运算的转换规则：

- 遇到操作数直接输出
- 遇到运算符：
  - 如果待判断的运算符的优先级**高于**栈顶运算符，或者栈内无元素，将其压入栈
  - 否则的话，从栈顶开始依次弹出运算符，直到满足条件上面的条件，再将该运算符压入栈中
  - 扫描到表达式结尾后，将栈内运算符依次弹出

> [!note]
>
> 上面的规则还没有考虑到 `()` 导致的优先级变化，考虑到小括号的影响还应加入下面两条规则：
>
> - `(` 在栈外优先级最高，在栈内优先级最低
> - 遇到 `)` 则从栈顶开始弹出运算符，直到遇到 `(`

<img src="./assets/infix_to_postfix.gif" style="zoom:66%;" />

> [!caution]
>
> 上面的规则适用于四则运算，而**不适用于幂运算**，因为幂运算是从右向左结合的。

代码实现：[Postfix expression](.\codes\Stack\Postfix expression)

#### 3.3.4 Function Calls

每一次函数调用产生的数据，包括局部变量 (local variables) 和返回地址 (return address)，都会被存入到**栈帧 (stack frame)**当中，而这个帧会被存到**系统栈 (system stack)**中。

<img src="./assets/Quicker_20240314_171005.png" alt="img" style="zoom:66%;" />

由于系统不会检查栈**溢出 (overflow)**的情况，因此当调用函数过多时会带来灾难性后果（例如：递归函数会不断向栈内写入数据，深度太深的递归会占光内存）

**尾部递归 (tail recursion)**：递归函数在最后一行进行递归调用时，编译器可能会将递归函数改写成循环形式（`goto`，打开编译器优化后），见下面的例子：

```c
// Recursion
void PrintList(List L)
{
    if (L != NULL)
    {
        PrintElement(L->Element);
        PrintList(L->Next);
    }
}  // a bad use of recursion

// Iteration
void PrintList(List L)
{
    top: if (L != NULL)
    {
        PrintElement(L->Element);
        L = L->Next;
        goto top;
    }  // do NOT do this!
}  // compiler removes recursion
```

虽然对于同一问题，非递归的程序往往快于递归，但递归程序通常更加简单和易于理解。

## 4 Queue ADT

### 4.1 ADT

**队列 (queue)**：一种**FIFO(first-in-first-out，先进先出 )**的列表，即在有序列表的一端插入，另一端删除

- **Objects**：拥有 0 个或多个元素的有限有序列表

- Operations：
  |`Int IsEmpty(Queue Q);`|检查队列是否为空|
    | ---- | ---- |
  | `Stack CreateQueue();`|创建队列|
  | `DisposeQueue(Queue Q);`   |  |
  | `MakeEmpty(Queue Q);`|清空队列|
  | `Enqueue(ElementType X, Queue Q);`|入队 |
  | `ElementType Front(Queue Q);`|获得队首元素|
  | `Dequeue(Queue Q);`|出队|

### 4.2 Implementation

[代码实现](.\codes\Queue)中代码中采用了**循环队列 (circular queue)**的方法，能够最大化利用队列的空间。对于循环队列，区分空队列和满队列有 2 种做法：

- 空出一块空间

- 增加一个 `Size` 的字段，用来实时统计队列元素个数，这样无需浪费空间（上述代码便采用这种做法）

  > [!note]
  >
  > 在法 2 中，如果用 `front` 表示队首元素，`size` 表示当前队伍大小，`m` 表示队伍最大大小，则队尾元素 `rear = (front + size - 1) % m`
