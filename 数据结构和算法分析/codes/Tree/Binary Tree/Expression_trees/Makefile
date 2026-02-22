# 定义编译器
CC = gcc
# 定义编译选项：-Wall 显示所有警告, -g 添加调试信息
CFLAGS = -Wall -g

# 定义所有的目标文件 (.o)
OBJS = binary_tree.o expr_tree.o postfix.o queue.o Stack.o test.o traversals.o

# 最终生成的可执行文件名
TARGET = test.exe

# 默认规则：链接所有 .o 文件生成 TARGET
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 将 .c 编译为 .o 的通用规则
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Stack.c 生成 Stack.o
Stack.o: Stack.c
	$(CC) $(CFLAGS) -c Stack.c -o Stack.o

# 清理命令：执行 'make clean' 删掉生成的文件
clean:
	del *.o *.exe