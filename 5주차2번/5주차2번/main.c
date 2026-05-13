#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordNode {
    char english[30];
    char korean[30];
    struct wordNode* prev;
    struct wordNode* next;
} wordNode;

wordNode* head = NULL;

void addWord() {
    char english[30];
    char korean[30];

    printf("영어: ");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = 0;

    printf("뜻: ");
    fgets(korean, sizeof(korean), stdin);
    korean[strcspn(korean, "\n")] = 0;

    wordNode* newNode = (wordNode*)malloc(sizeof(wordNode));
    strlcpy(newNode->english, english, sizeof(newNode->english));
    strlcpy(newNode->korean, korean, sizeof(newNode->korean));
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    if (strcmp(english, head->english) < 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    wordNode* cur = head;
    while (cur->next != NULL && strcmp(english, cur->next->english) > 0) {
        cur = cur->next;
    }

    newNode->next = cur->next;
    newNode->prev = cur;
    if (cur->next != NULL) {
        cur->next->prev = newNode;
    }
    cur->next = newNode;
}

void deleteWord() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    char english[30];
    printf("단어: ");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = 0;

    wordNode* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->english, english) == 0) {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            } else {
                head = cur->next;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            free(cur);
            return;
        }
        cur = cur->next;
    }

    printf("'%s' 단어를 찾을 수 없습니다.\n", english);
}

void searchWord() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    char english[30];
    printf("단어: ");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = 0;

    wordNode* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->english, english) == 0) {
            printf("%s 뜻은 %s입니다.\n", cur->english, cur->korean);
            return;
        }
        cur = cur->next;
    }

    printf("'%s' 단어를 찾을 수 없습니다.\n", english);
}

void printAll() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    wordNode* cur = head;
    while (cur != NULL) {
        printf("%s(%s)", cur->english, cur->korean);
        if (cur->next != NULL) printf(" - ");
        cur = cur->next;
    }
    printf("\n");
}

void exam() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    int correct = 0;
    int wrong = 0;

    wordNode* cur = head;
    while (cur != NULL) {
        char answer[30];
        printf("%s: ", cur->english);
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(answer, cur->korean) == 0) {
            correct++;
        } else {
            wrong++;
        }
        cur = cur->next;
    }

    printf("%d개 정답, %d개 오답입니다.\n", correct, wrong);
}

int main(void) {
    int choice;

    while (1) {
        printf("\n추가<1> 삭제<2> 검색<3> 모두보기<4> 시험<5> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            addWord();
            break;
        case 2:
            deleteWord();
            break;
        case 3:
            searchWord();
            break;
        case 4:
            printAll();
            break;
        case 5:
            exam();
            break;
        default:
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}
