//1번
#include <stdio.h>

int main() {
    int x, y; // 좌표 변수
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }; // 보드 초기화
    for (int i = 0; i < 9; i++) { // 9번 돌기
        printf("(x, y) 좌표: ");
        scanf("%d %d", &x, &y); // 입력 받기
        if (board[x][y] == 'o' || board[x][y] == 'x') {  // 만약 좌표찍은 곳에 o나 x가 있으면 다시 입력
            printf("이미 그곳은 돌을 놓았습니다.\n");
            i--; // i 감소
            continue; // 아래 건너뛰기
        }
        if (i % 2 == 0) { // 만약 유저 턴이면 o 놓기
            board[x][y] = 'o';
        }
        else {
            board[x][y] = 'x'; // 만약 유저 턴이면 x 놓기
        }
        for (int i = 0; i < 3; i++) { // 출력하기 위한 for문
            printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]); // 출력
            if (i < 2) {
                printf("---|---|---\n");
            }
        }
    }
    return 0;
}

//2번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int x, y, comX, comY;
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    for (int i = 0; i < 9; i++) { // 9번 돌기
        printf("(x, y) 좌표: ");
        scanf("%d %d", &x, &y); // 입력
        while (1) {
            comX = rand() % 3; // 랜덤으로 값넣기
            comY = rand() % 3;
            if (board[comX][comY] == ' ') { // 만약 공백이면 다시 랜덤값 넣기
                break;
            }
        }
        if (board[x][y] == 'o' || board[x][y] == 'x') {
            printf("이미 그곳은 돌을 놓았습니다.\n"); // 중복이면 다시 입력
            i--;
            continue;
        }
        board[x][y] = 'o'; // o 놓기
        board[comX][comY] = 'x'; // x 놓기
        i++; // 컴퓨터 턴 건너뛰기
        for (int i = 0; i < 3; i++) { // 출력
            printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
            if (i < 2) {
                printf("---|---|---\n");
            }
        }
    }
    return 0;
}
 
//3번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int x, y, comX, comY;
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    for (int i = 0; i < 9; i++) {
        printf("(x, y) 좌표: ");
        scanf("%d %d", &x, &y); // 입력
        while (1) {
            comX = rand() % 3; // 0~2 랜덤 값 저장
            comY = rand() % 3;
            if (board[comX][comY] == ' ') { // 중복이면 다시
                break;
            }
        }
        if (board[x][y] == 'o' || board[x][y] == 'x') { // 돌 중복
            printf("이미 그곳은 돌을 놓았습니다.\n");
            i--;
            continue;
        }
        board[x][y] = 'o';  // o 놓기
        board[comX][comY] = 'x';
        i++;
        for (int i = 0; i < 3; i++) { // 출력
            printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
            if (i < 2) {
                printf("---|---|---\n");
            }
        }
    }
    int owin = 0, xwin = 0; // 누가 이겼는지 알기 위해
    for (int j = 0; j < 3; j++) { // 가로 확인
        if (board[j][0] == board[j][1] && board[j][1] == board[j][2]) {
            if (board[j][0] == 'o') {
                owin = 1;
            }
            else if (board[j][0] == 'x') {
                xwin = 1;
            }
        }
    }
    for (int j = 0; j < 3; j++) { // 세로 확인
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'o') {
                owin = 1;
            }
            else if (board[0][j] == 'x') {
                xwin = 1;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { // 대각선 확인
        if (board[0][0] == 'o') {
            owin = 1;
        }
        else if (board[0][0] == 'x') {
            xwin = 1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) { // 대각선 확인
        if (board[0][2] == 'o') {
            owin = 1;
        }
        else if (board[0][2] == 'x') {
            xwin = 1;
        }
    }
    if (xwin && owin) { // 출력
        printf("둘 다 승리\n");
    }
    else if (xwin) {
        printf("X 승리\n");
    }
    else if (owin) {
        printf("O 승리\n");
    }
    else {
        printf("둘 다 빙고 완성 못함\n");
    }

    return 0;
}
