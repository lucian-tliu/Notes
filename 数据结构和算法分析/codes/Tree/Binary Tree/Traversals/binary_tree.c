#include "binary_tree.h" 
#include <string.h>

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printTree(Node* node, char *prefix, int isLeft) {
    if (node == NULL) return;

    printf("%s", prefix);
    printf("%s", isLeft ? "├── " : "└── ");
    printf("%d\n", node->data);

    char newPrefix[100];
    sprintf(newPrefix, "%s%s", prefix, isLeft ? "│   " : "    ");

    if (node->left || node->right) {
        printTree(node->left, newPrefix, 1);
        printTree(node->right, newPrefix, 0);
    }
}