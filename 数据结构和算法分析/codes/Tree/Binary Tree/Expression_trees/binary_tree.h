#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char data);
void freeTree(TreeNode* root);
void printTree(TreeNode* node, char *prefix, int isLeft);

#endif