// 이 모든 문제의 scanf오류는 SDL검사를 아니요로 설정하여 풀었습니다.
 
// 1번
#include <stdio.h>
#include <math.h> // pow함수 사용

int main() {
    double x, result;
    printf("x의 값을 입력하시오: ");
    scanf("%lf", &x); // double 변수 입력받기
    result = (pow(x, 3) * 3) - (pow(x, 2) * 7) + 9; // 방정식 계산
    printf("다항식의 값은 %lf입니다.\n", result); // 출력
    return 0;
}

// 2번
#include <stdio.h>
#include <math.h> // pow함수 사용

int main() {
    double result;
    for (double i = -100.0; i <= 100.0; i += 0.01) { // -100부터 100까지 0.01씩 증가
        result = (2 * pow(i, 2)) + (5 * i) - 3; // 방정식 계산
        if (fabs(result) < 1e-6) { // 계산한 값이 0과 근접한 경우 정확한 값은 데이터 분실로 인해 안나옴
            printf("2차식이 0이 되는 근은 %lf입니다.\n", i); // 출력
        }
    }
    return 0;
}

// 3번
#include <stdio.h>

int main() {
    char c;
    printf("입력 문자: ");
    scanf("%c", &c); // 문자 입력
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { // 모음일 경우
        printf("'%c'는 모음\n", c);
    }
    else { // 모음이 아닐 경우
        printf("'%c'는 자음\n", c);
    }
    return 0;
}

// 4번
#include <stdio.h>

int main() {
    char ch;
    printf("아무 문자나 입력하세요: ");
    scanf(" %c", &ch); // 입력
    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) { // 문자일 경우
        printf("%c는 알파벳입니다.\n", ch);
    }
    else if ('0' <= ch && ch <= '9') { // 숫자일 경우
        printf("%c는 숫자입니다.\n", ch);
    }
    else { // 둘 다 아닐 경우
        printf("%c는 특수 문자입니다.\n", ch);
    }
    return 0;
}

// 5번
#include <stdio.h>
#include <stdlib.h>  // rand함수 사용

int main() {
    int user, com;

    printf("가위, 바위, 보 게임에 오신 것을 환영합니다.\n");
    printf("하나를 선택하세요 (가위=0, 바위=1, 보=2): ");
    scanf("%d", &user); // 입력

    com = rand() % 3;       // 0~2 중 무작위 선택

    printf("사용자=%d\n", user);
    printf("컴퓨터=%d\n", com);

    if (user == com) { // 둘이 같을 경우
        printf("비겼습니다.\n");
    }
    else if ((user == 0 && com == 2) || (user == 1 && com == 0) || (user == 2 && com == 1)) { // 유저가 이긴 경우
        printf("사용자 승리\n");
    }
    else { // 컴퓨터가 이긴 경우
        printf("컴퓨터 승리\n");
    }
    return 0;
}
