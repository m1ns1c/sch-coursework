// 1번
#include <stdio.h>
#define MAX 100

typedef struct {
    int coef;
    int exp;
} Term;

int main(void) {
    Term A[MAX], B[MAX], C[MAX];
    int a = 0, b = 0, i = 0, j = 0, k = 0;

    int dA;
    printf("첫번째 다항식의 가장 높은 지수는? ");
    scanf("%d", &dA);
    for(int i = 0; i <= dA; i++) {
        int coef;
        printf("지수 %d 의 계수는? ", i);
        scanf("%d", &coef);
        if(coef != 0) {
            A[a].coef = coef;
            A[a].exp = i;
            a++;
        }
    }

    int dB;
    printf("두번째 다항식의 가장 높은 지수는? ");
    scanf("%d", &dB);
    for(int i = 0; i <= dB; i++) {
        int coef;
        printf("지수 %d 의 계수는? ", i);
        scanf("%d", &coef);
        if(coef != 0) {
            B[b].coef = coef;
            B[b].exp = i;
            b++;
        }
    }

    i = j = k = 0;
    while(i < a && j < b) {
        if(A[i].exp == B[j].exp) {
            C[k].coef = A[i].coef + B[j].coef;
            C[k].exp = A[i].exp;
            i++; j++; k++;
        } else if(A[i].exp > B[j].exp) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while(i < a) C[k++] = A[i++];
    while(j < b) C[k++] = B[j++];

    printf("덧셈 결과 : ");
    printf("%d", C[0].coef);
    for(int i = 1; i < k; i++) {
        if(i > 0) printf(" + ");
        printf("%dx^%d", C[i].coef, C[i].exp);
    }
    printf("\n");
    return 0;
}
