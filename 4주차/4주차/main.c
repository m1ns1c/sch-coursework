#include <stdio.h>
#include <string.h>
#define MAX 6
#define titleMax 20

typedef struct {
    char music[MAX][titleMax];
    int front;
    int rear;
} PlayList;

void initQueue(PlayList *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(PlayList *q) {
    return q->front == q->rear;
}

int isFull(PlayList *q) {
    return (q->rear + 1) % MAX == q->front;
}

void ADD(PlayList *q, char song[]) {
    if (isFull(q)) {
        printf("플레이리스트가 다 찼습니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->music[q->rear], song);
    printf("%s 추가완료\n", song);
}

void playSong(PlayList *q) {
    char temp[titleMax];
    if (isEmpty(q)) {
        printf("재생할 곡이 없습니다.\n");
        return;
    }
    q->front = (q->front + 1) % MAX;
    strcpy(temp, q->music[q->front]);
    printf("%s 재생\n", temp);
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->music[q->rear], temp);
}

void print(PlayList *q) {
    if (isEmpty(q)) {
        printf("플레이리스트가 비어있습니다.\n");
        return;
    }
    printf("플레이리스트: ");
    int i = q->front;
    while (1) {
        i = (i + 1) % MAX;
        printf("%s ", q->music[i]);
        if (i == q->rear) break;
    }
    printf("\n");
}

int main(void) {
    PlayList q;
    initQueue(&q);
    ADD(&q, "A");
    ADD(&q, "B");
    ADD(&q, "C");
    print(&q);
    playSong(&q);
    print(&q);
    ADD(&q, "D");
    ADD(&q, "E");
    ADD(&q, "F");
    print(&q);
    return 0;
}
