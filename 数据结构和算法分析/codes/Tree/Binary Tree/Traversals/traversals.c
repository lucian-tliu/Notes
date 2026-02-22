#include "binary_tree.h"
#include "queue.h"

void preOrder(struct Node* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);  // 1. 访问根节点
    preOrder(root->left);       // 2. 递归遍历左子树
    preOrder(root->right);      // 3. 递归遍历右子树
}

void inOrder(struct Node* root) {
    if (root == NULL) return;
    
    inOrder(root->left);        // 1. 递归遍历左子树
    printf("%d ", root->data);  // 2. 访问根节点
    inOrder(root->right);       // 3. 递归遍历右子树
}

void postOrder(struct Node* root) {
    if (root == NULL) return;
    
    postOrder(root->left);      // 1. 递归遍历左子树
    postOrder(root->right);     // 2. 递归遍历右子树
    printf("%d ", root->data);  // 3. 访问根节点
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    Queue Q = CreateQueue(100);
    Enqueue(root, Q);

    while (!IsEmpty(Q)) {
        Node* current = FrontAndDequeue(Q);
        printf("%d ", current->data);

        if (current->left != NULL) {
            Enqueue(current->left, Q);
        }
        if (current->right != NULL) {
            Enqueue(current->right, Q);
        }
    }

    DisposeQueue(Q);
}

int main() {
    system("chcp 65001");  // 设置控制台为UTF-8编码，适用于Windows系统
    // 创建一个简单的二叉树
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Binary Tree Structure:\n");
    printTree(root, "", 0);

    printf("\nPre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(root);
    printf("\n");

    // 释放内存
    freeTree(root);
    return 0;
}