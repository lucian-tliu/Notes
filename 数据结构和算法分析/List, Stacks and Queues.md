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

- 数组大小在声明时确定，需要估计表的大下
- 访问元素 $O(1)$
- 修改元素（插入、删除）$O(N)$

对于频繁插入和删除的表，需要使用链表(Linked List)的形式

### 2.2 链表

- 链表相比数组占用空间更多（额外的指针域），但它不要求空间连续
- 链表查找时间慢（$O(N)$），但插入和删除很快（$O(1)$），通过下面图示可以较为直观地感受到
- 最后一项的指针指向`NULL`
- 对于**头指针**，我们不将第一项作为头指针，而是采用一个**虚拟节点 (dummy node)**。这个节点数据域为空，指针指向列表中的第一项。这样做的好处是我们在处理头节点时不需要再单独写一个函数

插入：

<img src="./assets/Quicker_20240627_130525.png" alt="img" style="zoom:50%;" />

删除：

<img src="./assets/Quicker_20240627_130545.png" alt="img" style="zoom:50%;" />

代码实现：[List](./codes/List)

