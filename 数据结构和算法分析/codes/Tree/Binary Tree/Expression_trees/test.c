#include "postfix.h"   
#include "expr_tree.h"
#include "traversals.h"

int main() {
    system("chcp 65001"); // Set console to UTF-8 to display tree structure correctly

    /* 数值表达式：用于后缀求值（postfix_cal 仅支持数字） */
    char infix_num[100] = "1+2*(3-4)";
    char postfix_num[100];
    infix_to_postfix(infix_num, postfix_num);
    printf("Infix expression (numeric): %s\n", infix_num);
    printf("Postfix expression (numeric): %s\n", postfix_num);
    double result = postfix_cal(postfix_num);
    printf("Result of postfix evaluation: %.2f\n", result);
    printf("------------------------------\n");

    /* 含变量的表达式：用于构造表达式树 */
    char infix[100] = "a+b*(c-e)/(f+g*h)-i";
    char postfix[100];
    infix_to_postfix(infix, postfix);
    printf("Infix expression (with vars): %s\n", infix);
    printf("Postfix expression (with vars): %s\n", postfix);

    TreeNode* exprTree = constructExpressionTree(postfix);

    printf("Pre-order Traversal: ");
    preOrder(exprTree);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(exprTree);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(exprTree);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(exprTree);
    printf("\n");

    printf("Expression Tree:\n");
    printTree(exprTree, "", 0);

    freeTree(exprTree);
    return 0;
}