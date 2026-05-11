// 1번
#include <stdio.h>
#define ROW 6
#define COL 10

typedef struct {
    int r;
    int c;
} Point;

int main() {
    int maze[ROW][COL] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,3,1,1,0,0,0,0,1,1},
        {1,0,1,0,0,1,1,0,4,1},
        {1,0,0,0,1,0,0,1,1,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    Point stack[100];
    int visited[ROW][COL] = { 0 };
    int top = -1;
    int i, j;
    int startR, startC;
    int found = 0;
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 3) {
                startR = i;
                startC = j;
            }
        }
    }

    top++;
    stack[top].r = startR;
    stack[top].c = startC;
    visited[startR][startC] = 1;

    while (top != -1) {
        int curR = stack[top].r;
        int curC = stack[top].c;
        int moved = 0;

        for (i = 0; i < 4; i++) {
            int nr = curR + dr[i];
            int nc = curC + dc[i];

            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) continue;

            if (maze[nr][nc] == 4) {
                found = 1;
                for (j = 0; j <= top; j++) {
                    if (maze[stack[j].r][stack[j].c] != 3)
                        maze[stack[j].r][stack[j].c] = 9;
                }
                break;
            }

            if (maze[nr][nc] == 0 && visited[nr][nc] == 0) {
                top++;
                stack[top].r = nr;
                stack[top].c = nc;
                visited[nr][nc] = 1;
                moved = 1;
                break;
            }
        }

        if (found) break;
        if (!moved) {
            top--;
        }
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (found) {
        printf("대박~\n");
    } else {
        printf("헐~ 지못미\n");
    }

    return 0;
}
