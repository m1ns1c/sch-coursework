// 2번
#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 10

typedef struct {
    int r;
    int c;
} Point;

void printMaze(int maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isMeet(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2)
        return 1;
    if (abs(r1 - r2) + abs(c1 - c2) == 1)
        return 1;
    return 0;
}

int moveOneTurn(int maze[ROW][COL], Point stack[], int* top, int visited[ROW][COL], int me, int target) {
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };
    int i;
    int curR = stack[*top].r;
    int curC = stack[*top].c;
    int moved = 0;

    for (i = 0; i < 4; i++) {
        int nr = curR + dr[i];
        int nc = curC + dc[i];

        if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;

        if (maze[nr][nc] == target) {
            return 2;
        }

        if (maze[nr][nc] == 0 && visited[nr][nc] == 0) {
            maze[curR][curC] = 9;
            (*top)++;
            stack[*top].r = nr;
            stack[*top].c = nc;
            visited[nr][nc] = 1;
            maze[nr][nc] = me;
            moved = 1;
            break;
        }
    }

    if (!moved) {
        if (*top > 0) {
            maze[curR][curC] = 9;
            (*top)--;
            curR = stack[*top].r;
            curC = stack[*top].c;
            maze[curR][curC] = me;
            return 1;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int maze[ROW][COL] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,3,0,0,0,0,0,4,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    Point momStack[100];
    Point cheonStack[100];
    int momVisited[ROW][COL] = { 0 };
    int cheonVisited[ROW][COL] = { 0 };
    int momTop = -1;
    int cheonTop = -1;
    int i, j;
    int momR, momC;
    int cheonR, cheonC;
    int resultMom, resultCheon;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 3) {
                momR = i;
                momC = j;
            }
            if (maze[i][j] == 4) {
                cheonR = i;
                cheonC = j;
            }
        }
    }

    momTop++;
    momStack[momTop].r = momR;
    momStack[momTop].c = momC;
    momVisited[momR][momC] = 1;

    cheonTop++;
    cheonStack[cheonTop].r = cheonR;
    cheonStack[cheonTop].c = cheonC;
    cheonVisited[cheonR][cheonC] = 1;

    printMaze(maze);

    while (1) {
        if (isMeet(momStack[momTop].r, momStack[momTop].c, cheonStack[cheonTop].r, cheonStack[cheonTop].c)) {
            printf("대박~\n");
            break;
        }

        resultMom = moveOneTurn(maze, momStack, &momTop, momVisited, 3, 4);
        printMaze(maze);

        if (resultMom == 2 || isMeet(momStack[momTop].r, momStack[momTop].c, cheonStack[cheonTop].r, cheonStack[cheonTop].c)) {
            printf("대박~\n");
            break;
        }

        if (isMeet(cheonStack[cheonTop].r, cheonStack[cheonTop].c, momStack[momTop].r, momStack[momTop].c)) {
            printf("대박~\n");
            break;
        }

        resultCheon = moveOneTurn(maze, cheonStack, &cheonTop, cheonVisited, 4, 3);
        printMaze(maze);

        if (resultCheon == 2 || isMeet(cheonStack[cheonTop].r, cheonStack[cheonTop].c, momStack[momTop].r, momStack[momTop].c)) {
            printf("대박~\n");
            break;
        }

        if (resultMom == 0 && resultCheon == 0) {
            printf("헐~ 지못미\n");
            break;
        }
    }

    return 0;
}
