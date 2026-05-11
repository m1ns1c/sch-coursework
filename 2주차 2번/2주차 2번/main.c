// 2번
#include <stdio.h>
#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

int main(void) {
    Term A[MAX], B[MAX], C[MAX];
    int a, b;
    int i = 1, j = 1, k = 1;

    printf("Term A를 입력하세요\n");
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].value);
    a = A[0].value;
    for(int n = 1; n <= a; n++) {
        scanf("%d %d %d", &A[n].row, &A[n].col, &A[n].value);
    }

    printf("Term B를 입력하세요\n");
    scanf("%d %d %d", &B[0].row, &B[0].col, &B[0].value);
    b = B[0].value;
    for(int n = 1; n <= b; n++) {
        scanf("%d %d %d", &B[n].row, &B[n].col, &B[n].value);
    }

    C[0].row = A[0].row;
    C[0].col = A[0].col;
    while(i <= a && j <= b) {
        if(A[i].row == B[j].row && A[i].col == B[j].col) {
            int sum = A[i].value + B[j].value;
            if(sum != 0) {
                C[k].row = A[i].row;
                C[k].col = A[i].col;
                C[k].value = sum;
                k++;
            }
            i++; j++;
        } else if(A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while(i <= a) C[k++] = A[i++];
    while(j <= b) C[k++] = B[j++];

    C[0].value = k - 1;
    printf("Result Matrix\n");
    printf("row col value\n");
    printf("%d %d %d\n", C[0].row, C[0].col, C[0].value);
    for(int n = 1; n < k; n++) {
        printf("%d %d %d\n", C[n].row, C[n].col, C[n].value);
    }
    return 0;
}
