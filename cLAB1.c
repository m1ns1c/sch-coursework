// 이 모든 문제의 scanf오류는 SDL검사를 아니요로 설정하여 풀었습니다.

//1.
#include <stdio.h>

int main() {
    char carModel; // 자동차 모델 저장
    int people; // 사람인원 저장
    double yunbi; // 연비 저장
    long km; // 주행거리 저장
    long long price; // 가격 저장
 // 입력 받기
    printf("자동차의 모델 : ");
    scanf("%c", &carModel); // 문자 하나는 character로 해야함
    scanf("%c", &carModel);
    printf("자동차의 승차인원 : ");
    scanf("%d", &people);
    printf("자동차의 연비 : ");
    scanf("%lf", &yunbi); // 실수는 double
    printf("자동차의 주행거리 : ");
    scanf("%ld", &km); // long int
    printf("자동차의 가격 : ");
    scanf("%lld", &price); // long long int
 // 출력 하기
    printf("자동차의 모델은 %c 입니다.\n", carModel);
    printf("자동차의 승차인원은 %d 입니다.\n", people);
    printf("자동차의 연비는 %lf 입니다.\n", yunbi);
    printf("자동차의 주행거리는 %ld 입니다.\n", km);
    printf("자동차의 가격은 %lld 입니다.\n", price);
    return 0;
}

//2.
#include <stdio.h>

int main() {
    int a = 1, b = 8, c = 7; // 각 a, b, c에 1, 8, 7 저장
    int max = a > b ? a : b; // 삼항연산자로 크기 비교하고 max에 저장
    max = c > max ? c : max;
    printf("%d, %d, %d 중에서 가장 큰 수는 %d입니다.\n", a, b, c, max); // 출력
    return 0;
}

//3.
#include <stdio.h>

int main() {
    int inMoney, obPrice, modPrice;
    printf("투입한 돈: ");
    scanf("%d", &inMoney);
    printf("물건 값: ");
    scanf("%d", &obPrice);
    modPrice = inMoney - obPrice; // 거스름 돈 계산하고 변수에 저장
    printf("거스름돈: %d\n\n", modPrice);
    printf("100원의 동전의 개수: %d\n", modPrice / 100); // 100원 동전 개수 계산
    printf("10원의 동전의 개수: %d\n", (modPrice % 100) / 10); // 10원 동전 개수 계산
    printf("1원의 동전의 개수: %d\n", ((modPrice % 100) % 10) / 1); // 1원 동전 개수 계산
    return 0;
}

//4.
#include <stdio.h>

int main() {
    int a, b;
 // 입력 받기
    printf("첫 번째 정수를 입력하시오: ");
    scanf("%d", &a);
    printf("두 번째 정수를 입력하시오: ");
    scanf("%d", &b);
    printf("몫은 %d이고 나머지는 %d입니다.\n", a / b, a % b); // 몫과 나머지 계산 후 출력
    return 0;
}

//5.
#include <stdio.h>

int main() {
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d", &n); // 입력 받기
    printf("백의 자리수: %d\n", n / 100); // 백의 자리수 계산
    printf("십의 자리수: %d\n", (n % 100) / 10); // 십의 자리수 계산
    printf("일의 자리수: %d\n", ((n % 100) % 10) / 1); // 일의 자리수 계산
    return 0;
}

//6.
#include <stdio.h>

int main() {
    double a, b;
    printf("2개의 실수를 입력하시오: ");
    scanf("%lf %lf", &a, &b); // 실수 두 개 입력받기
    int c = a, d = b; // 정수로 변환해 강제 내림 시키기
    printf("합의 정수부 = %d\n", c + d); // 두 수를 더하여 출력
    return 0;
}

//7.
#include <stdio.h>

int main() {
    int road = 60, moonRoad = 383000;
    printf("왕복 출퇴근 거리: %d\n", road);
    printf("달까지의 거리: %d\n\n", moonRoad);
    road *= 2; // 왕복이니까 X 2
    int temp = ((double)moonRoad / road + 0.5); // 달거리를 실수로 변환후 road에 0.5를 더해 반올림 시키기
    int year = temp / 365; // 년도 계산
    int month = (temp % 365) / 30; // 달 계산
    int day = (temp % 365) % 30; // 일 계산
    printf("%d년 %d월 %d일 후 출퇴근 거리가 달까지의 거리가 됩니다.\n", year, month, day); // 출력
    return 0;
}
