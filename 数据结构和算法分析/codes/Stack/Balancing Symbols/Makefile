CC = gcc
CFLAGS = -g -Wall
DEPS = Stack.h balance_symbol.h
OBJ = Stack.o balance_symbol.o test.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm -f *.o test
.PHONY: clean