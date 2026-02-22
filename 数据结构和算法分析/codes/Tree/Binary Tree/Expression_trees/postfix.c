#include "postfix.h"

#define STACK_MAX 256

/* 用于 postfix_cal 的 double 栈 */
static double dstack[STACK_MAX];
static int dtop = -1;

static void dpush(double x) {
    if (dtop >= STACK_MAX - 1) { printf("Double stack overflow\n"); exit(EXIT_FAILURE); }
    dstack[++dtop] = x;
}
static double dpop(void) {
    if (dtop < 0) { printf("Double stack underflow\n"); exit(EXIT_FAILURE); }
    return dstack[dtop--];
}

/* 用于 infix_to_postfix 的 char 栈 */
static char cstack[STACK_MAX];
static int ctop = -1;

static void cpush(char c) {
    if (ctop >= STACK_MAX - 1) { printf("Char stack overflow\n"); exit(EXIT_FAILURE); }
    cstack[++ctop] = c;
}
static char cpop(void) {
    if (ctop < 0) { printf("Char stack underflow\n"); exit(EXIT_FAILURE); }
    return cstack[ctop--];
}
static int cis_empty(void) { return ctop < 0; }
static char ctop_elem(void) { return ctop >= 0 ? cstack[ctop] : 0; }

double postfix_cal(char *expression)
{
    dtop = -1;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            dpush((double)(expression[i] - '0'));
        }
        else
        {
            double op2 = dpop();
            double op1 = dpop();
            double result;
            switch (expression[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            default:
                printf("Unknown operator: %c\n", expression[i]);
                exit(EXIT_FAILURE);
            }
            dpush(result);
        }
    }

    return dpop();
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
    default:
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{
    ctop = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if (infix[i] == '(')
            {
                cpush(infix[i]);
                continue;
            }
            if (infix[i] == ')')
            {
                while (!cis_empty() && ctop_elem() != '(')
                {
                    postfix[j++] = cpop();
                }
                if (!cis_empty()) cpop(); /* pop the '(' */
                continue;
            }
            while (!cis_empty() && ctop_elem() != '(' &&
                   precedence(ctop_elem()) >= precedence(infix[i]))
            {
                postfix[j++] = cpop();
            }
            cpush(infix[i]);
        }
    }

    while (!cis_empty())
    {
        postfix[j++] = cpop();
    }

    postfix[j] = '\0';
    // printf("Infix Expression:\t %s\n", infix);
    // printf("Postfix Expression:\t %s\n", postfix);
}
