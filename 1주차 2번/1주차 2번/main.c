// 2번
#include <stdio.h>

int result[100];
int j = 0;

void factor(int n, int i) {
    if (n == 1) {
        return;
    }
    if (n % i == 0) {
        result[j] = i;
        j++;
        factor(n / i, i);
    } else {
        factor(n, i + 1);
    }
}

int main(void) {
    int n, isPrime = 1;
    printf("n을 입력하세요. ");
    scanf("%d", &n);
    for(int i = 2; i < n; i++) {
        if(n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if(isPrime) {
        printf("1 %d\n", n);
    } else {
        factor(n, 2);
        for(int i = 0; i < j; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    return 0;
}
