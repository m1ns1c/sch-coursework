// 1번
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main(void) {
    Node* root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->right->left = createNode(4);
    root->right->right = createNode(9);

    int choice;
    printf("전위<1> 중위<2> 후위<3> : ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전위 순회 : ");
        preorder(root);
    } else if (choice == 2) {
        printf("중위 순회 : ");
        inorder(root);
    } else if (choice == 3) {
        printf("후위 순회 : ");
        postorder(root);
    }

    printf("\n");
    return 0;
}
