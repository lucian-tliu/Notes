#include "postfix.h"

int main()
{
    char infix[] = "2+5*((3*2)-7/(4+5))";
    char postfix[100];
    infix_to_postfix(infix, postfix);

    double result = postfix_cal(postfix);
    double expected = 2 + 5 * ((3 * 2) - 7 / (4. + 5));
    printf("Result:  \t %.2f\n", result);
    printf("Expected:\t %.2f\n", expected);
    return 0;
}