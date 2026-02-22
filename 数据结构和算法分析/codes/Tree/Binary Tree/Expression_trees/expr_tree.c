#include "expr_tree.h"

TreeNode* constructExpressionTree(char* postfix) {
    Stack nodeStack = CreateStack();
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        
        // If the token is an operand, create a new node and push it onto the stack
        if (isalnum(token)) {
            TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->data = token;
            newNode->left = NULL;
            newNode->right = NULL;
            Push(newNode, nodeStack);
        }
        // If the token is an operator, pop two nodes from the stack,
        // create a new operator node, and push it back onto the stack
        else {
            TreeNode* rightNode = Pop(nodeStack);
            TreeNode* leftNode = Pop(nodeStack);
            
            TreeNode* operatorNode = (TreeNode*)malloc(sizeof(TreeNode));
            operatorNode->data = token;
            operatorNode->left = leftNode;
            operatorNode->right = rightNode;
            
            Push(operatorNode, nodeStack);
        }
    }
    
    // The final node on the stack is the root of the expression tree
    TreeNode* root = Pop(nodeStack);
    DisposeStack(nodeStack);
    return root;
}