// 2번
#include <stdio.h>

#define MAX_SIZE 10

int tree[MAX_SIZE];
int size;

void preorder(int i) {
    if (i > size || tree[i] == 0) return;
    printf("%d ", tree[i]);
    preorder(2 * i);
    preorder(2 * i + 1);
}

void inorder(int i) {
    if (i > size || tree[i] == 0) return;
    inorder(2 * i);
    printf("%d ", tree[i]);
    inorder(2 * i + 1);
}

void postorder(int i) {
    if (i > size || tree[i] == 0) return;
    postorder(2 * i);
    postorder(2 * i + 1);
    printf("%d ", tree[i]);
}

int main(void) {
    size = 7;
    tree[1] = 3;
    tree[2] = 2;
    tree[3] = 5;
    tree[4] = 1;
    tree[5] = 0;
    tree[6] = 4;
    tree[7] = 9;

    int choice;
    printf("전위<1> 중위<2> 후위<3> : ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전위 순회 : ");
        preorder(1);
    } else if (choice == 2) {
        printf("중위 순회 : ");
        inorder(1);
    } else if (choice == 3) {
        printf("후위 순회 : ");
        postorder(1);
    }

    printf("\n");
    return 0;
}
