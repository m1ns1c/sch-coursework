// 1번
#include <stdio.h>

int count = 0;
int left = 0;
int right;

int search(int num[], int m) {
    int mid = (left + right) / 2;
    if (num[mid] == m) {
        return count;
    }
    if (num[mid] > m) {
        right = mid - 1;
        count++;
        return search(num, m);
    } else {
        left = mid + 1;
        count++;
        return search(num, m);
    }
}

int main(void) {
    int num[100];
    int n, m;
    printf("n을 입력하세요? ");
    scanf("%d", &n);
    printf("m을 입력하세요? ");
    scanf("%d", &m);
    for(int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    right = n - 1;
    int result = search(num, m) - 1;
    printf("재귀함수를 %d번 호출하였습니다.\n", result);
    return 0;
}
