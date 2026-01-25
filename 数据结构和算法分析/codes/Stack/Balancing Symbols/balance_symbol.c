#include "balance_symbol.h"

int BalanceSymbol(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen failed");
        return 1;
    }
    Stack S = CreateStack();
    if (!S) {
        fclose(fp);
        return 1;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '(' || ch == '{' || ch == '[') {
            Push(ch, S);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (IsEmpty(S)) {
                printf("Unmatched closing symbol: %c\n", ch);
                DisposeStack(S);
                fclose(fp);
                return 1;
            }
            char top = Pop(S);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                printf("Mismatched symbols: %c and %c\n", top, ch);
                DisposeStack(S);
                fclose(fp);
                return 1;
            }
        }
    }
    if (!IsEmpty(S)) {
        printf("Unmatched opening symbols remain in stack.\n");
        DisposeStack(S);
        fclose(fp);
        return 1;
    }
    printf("All symbols are balanced.\n");
    fclose(fp);
    return 0;
}