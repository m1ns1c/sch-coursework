    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct musicNode {
        char title[20];
        char artist[20];
        struct musicNode* link;
    } musicNode;

    musicNode* head = NULL;

    void addMusic() {
        char title[20];
        char artist[20];

        printf("제목: ");
        scanf(" %[^\n]", title);

        printf("아티스트: ");
        scanf(" %[^\n]", artist);

        musicNode* newNode = (musicNode*)malloc(sizeof(musicNode));
        strlcpy(newNode->title, title, sizeof(newNode->title));
        strlcpy(newNode->artist, artist, sizeof(newNode->artist));
        newNode->link = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->link = head;
        }
        else {
            musicNode* cur = head;
            while (cur->link != head) {
                cur = cur->link;
            }
            cur->link = newNode;
            newNode->link = head;
        }
    }

    void deleteMusic() {
        if (head == NULL) {
            printf("리스트가 비어있습니다.\n");
            return;
        }

        char title[20];
        printf("제목: ");
        scanf(" %[^\n]", title);

        musicNode* cur = head;
        musicNode* prev = NULL;

        musicNode* last = head;
        while (last->link != head) {
            last = last->link;
        }

        if (strcmp(head->title, title) == 0) {
            if (head->link == head) {
                free(head);
                head = NULL;
            }
            else {
                last->link = head->link;
                free(head);
                head = last->link;
            }
            return;
        }

        prev = head;
        cur = head->link;
        while (cur != head) {
            if (strcmp(cur->title, title) == 0) {
                prev->link = cur->link;
                free(cur);
                return;
            }
            prev = cur;
            cur = cur->link;
        }

        printf("'%s' 음악을 찾을 수 없습니다.\n", title);
    }

    void repeatPlay() {
        if (head == NULL) {
            printf("리스트가 비어있습니다.\n");
            return;
        }

        int count = 0;
        musicNode* cur = head;
        while (cur->link != head) {
            count++;
            cur = cur->link;
        }
        count++;

        int repeat;
        scanf("%d", &repeat);

        int total = count * repeat;
        printf("재생할 음악 수: %d\n", total);

        cur = head;
        int i;
        for (i = 0; i < total; i++) {
            printf("%s(%s)", cur->title, cur->artist);
            cur = cur->link;
            if (i < total - 1) printf("-");
        }
        printf("\n");
    }

    void playOnce() {
        if (head == NULL) {
            printf("리스트가 비어있습니다.\n");
            return;
        }

        int count = 0;
        musicNode* cur = head;
        while (cur->link != head) {
            count++;
            cur = cur->link;
        }
        count++;

        printf("재생할 음악 수: %d\n", count);

        cur = head;
        int i;
        for (i = 0; i < count; i++) {
            printf("%s(%s)", cur->title, cur->artist);
            cur = cur->link;
            if (i < count - 1) printf("-");
        }
        printf("\n");
    }

    void printList() {
        if (head == NULL) {
            printf("리스트가 비어있습니다.\n");
            return;
        }

        musicNode* cur = head;
        int first = 1;
        while (cur->link != head) {
            if (!first) printf("-");
            printf("%s(%s)", cur->title, cur->artist);
            first = 0;
            cur = cur->link;
        }
        if (!first) printf("-");
        printf("%s(%s)\n", cur->title, cur->artist);
    }

    int main(void) {
        int choice;

        while (1) {
            printf("\n추가<1> 삭제<2> 반복재생<3> 한번재생<4> 음악리스트<5> ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                deleteMusic();
                break;
            case 3:
                repeatPlay();
                break;
            case 4:
                playOnce();
                break;
            case 5:
                printList();
                break;
            default:
                printf("잘못된 입력입니다.\n");
            }
        }

        return 0;
    }
