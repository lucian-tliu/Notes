#include "postfix.h"

double postfix_cal(char *expression)
{
    Stack operands;
    operands = CreateStack();
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            Push((double)(expression[i] - '0'), operands);
        }
        else
        {
            double op2 = Pop(operands);
            double op1 = Pop(operands);
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
                DisposeStack(operands);
                exit(EXIT_FAILURE);
            }
            Push((ElementType)result, operands);
        }
    }

    return Pop(operands);
}

int precedence(char op)
{
    /* Define operator precedence in the Stack */
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
    Stack operators = CreateStack();
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if (infix[i] == '(')
            {
                Push((ElementType)infix[i], operators);
                continue;
            }
            if (infix[i] == ')')
            {
                while (!IsEmpty(operators) && (char)Top(operators) != '(')
                {
                    char topOp = (char)Pop(operators);
                    postfix[j++] = topOp;
                }
                Pop(operators); // pop the '('
                continue;
            }
            while (!IsEmpty(operators) && 
            precedence((char)Top(operators)) >= precedence(infix[i]))
            {
                char topOp = (char)Pop(operators);
                postfix[j++] = topOp;
            }
            Push((ElementType)infix[i], operators);
        }
    }

    while (!IsEmpty(operators))
    {
        char topOp = (char)Pop(operators);
        postfix[j++] = topOp;
    }

    postfix[j] = '\0';
    printf("Infix Expression:\t %s\n", infix);
    printf("Postfix Expression:\t %s\n", postfix);
    DisposeStack(operators);
}