#include "traversals.h"

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    
    printf("%c ", root->data);  // 1. 访问根节点
    preOrder(root->left);       // 2. 递归遍历左子树
    preOrder(root->right);      // 3. 递归遍历右子树
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;
    
    inOrder(root->left);        // 1. 递归遍历左子树
    printf("%c ", root->data);  // 2. 访问根节点
    inOrder(root->right);       // 3. 递归遍历右子树
}

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    
    postOrder(root->left);      // 1. 递归遍历左子树
    postOrder(root->right);     // 2. 递归遍历右子树
    printf("%c ", root->data);  // 3. 访问根节点
}

void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    Queue Q = CreateQueue(100);
    Enqueue(root, Q);

    while (!QueueIsEmpty(Q)) {
        TreeNode* current = FrontAndDequeue(Q);
        printf("%c ", current->data);

        if (current->left != NULL) {
            Enqueue(current->left, Q);
        }
        if (current->right != NULL) {
            Enqueue(current->right, Q);
        }
    }

    DisposeQueue(Q);
}