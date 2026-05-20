//1번
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SubwayNode {
    char name[20];
    int isTransfer;
    struct SubwayNode* prev;
    struct SubwayNode* next;
} SubwayNode;

SubwayNode* line1;
SubwayNode* line2;

void init(SubwayNode* head) {
    head->name[0] = '\0';
    head->isTransfer = 0;
    head->prev = head;
    head->next = head;
}

void dinsert_last(SubwayNode* head, char* stationName) {
    SubwayNode* newNode = (SubwayNode*)malloc(sizeof(SubwayNode));
    strcpy(newNode->name, stationName);
    newNode->isTransfer = 0;
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev->next = newNode;
    head->prev = newNode;
}

void update_transfer() {
    SubwayNode* p = line1->next;
    while (p != line1) { p->isTransfer = 0; p = p->next; }
    p = line2->next;
    while (p != line2) { p->isTransfer = 0; p = p->next; }

    p = line1->next;
    while (p != line1) {
        SubwayNode* q = line2->next;
        while (q != line2) {
            if (strcmp(p->name, q->name) == 0) { p->isTransfer = 1; q->isTransfer = 1; }
            q = q->next;
        }
        p = p->next;
    }
}

void print_dlist(SubwayNode* head) {
    SubwayNode* p = head->next;
    while (p != head) {
        printf("%s-", p->name);
        p = p->next;
    }
    printf("\n");
}

void add_station(SubwayNode* head, char* newName, char* prevName) {
    SubwayNode* newNode = (SubwayNode*)malloc(sizeof(SubwayNode));
    strcpy(newNode->name, newName);
    newNode->isTransfer = 0;

    if (strcmp(prevName, "NULL") == 0) {
        SubwayNode* first = head->next;
        newNode->next = first;
        newNode->prev = head;
        head->next = newNode;
        first->prev = newNode;
    } else {
        SubwayNode* p = head->next;
        while (p != head) {
            if (strcmp(p->name, prevName) == 0) {
                newNode->next = p->next;
                newNode->prev = p;
                p->next->prev = newNode;
                p->next = newNode;
                break;
            }
            p = p->next;
        }
    }
    update_transfer();
    printf("역 '%s'이(가) 추가되었습니다.\n", newName);
}

void delete_station(SubwayNode* head, char* stationName) {
    SubwayNode* p = head->next;
    while (p != head) {
        if (strcmp(p->name, stationName) == 0) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            update_transfer();
            printf("역 '%s'이(가) 삭제되었습니다.\n", stationName);
            return;
        }
        p = p->next;
    }
}

int print_way(SubwayNode* head, char* startName, char* endName) {
    SubwayNode* startNode = NULL;
    SubwayNode* p = head->next;
    while (p != head) {
        if (strcmp(p->name, startName) == 0) { startNode = p; break; }
        p = p->next;
    }
    if (!startNode) return 0;

    SubwayNode* cur = startNode->next;
    while (cur != head) {
        if (strcmp(cur->name, endName) == 0) {
            printf("%s", startName);
            SubwayNode* tmp = startNode->next;
            while (tmp != head) {
                printf(" - %s", tmp->name);
                if (strcmp(tmp->name, endName) == 0) break;
                tmp = tmp->next;
            }
            printf("\n");
            return 1;
        }
        cur = cur->next;
    }

    cur = startNode->prev;
    while (cur != head) {
        if (strcmp(cur->name, endName) == 0) {
            printf("%s", startName);
            SubwayNode* tmp = startNode->prev;
            while (tmp != head) {
                printf(" - %s", tmp->name);
                if (strcmp(tmp->name, endName) == 0) break;
                tmp = tmp->prev;
            }
            printf("\n");
            return 1;
        }
        cur = cur->prev;
    }

    return 0;
}

int print_way_transfer(SubwayNode* fromHead, SubwayNode* toHead, char* startName, char* endName) {
    SubwayNode* startNode = NULL;
    SubwayNode* p = fromHead->next;
    while (p != fromHead) {
        if (strcmp(p->name, startName) == 0) { startNode = p; break; }
        p = p->next;
    }
    if (!startNode) return 0;

    SubwayNode* tr = fromHead->next;
    while (tr != fromHead) {
        if (!tr->isTransfer) { tr = tr->next; continue; }

        SubwayNode* trInTo = toHead->next;
        while (trInTo != toHead) {
            if (strcmp(trInTo->name, tr->name) == 0) break;
            trInTo = trInTo->next;
        }
        if (trInTo == toHead) { tr = tr->next; continue; }

        SubwayNode* endNode = toHead->next;
        while (endNode != toHead) {
            if (strcmp(endNode->name, endName) == 0) break;
            endNode = endNode->next;
        }
        if (endNode == toHead) { tr = tr->next; continue; }

        int fwd = 0;
        SubwayNode* chk = startNode->next;
        while (chk != fromHead) {
            if (strcmp(chk->name, tr->name) == 0) { fwd = 1; break; }
            chk = chk->next;
        }

        printf("%s", startName);
        if (fwd) {
            SubwayNode* tmp = startNode->next;
            while (tmp != fromHead && strcmp(tmp->prev->name, tr->name) != 0) {
                printf(" - %s", tmp->name);
                tmp = tmp->next;
            }
        } else {
            SubwayNode* tmp = startNode->prev;
            while (tmp != fromHead && strcmp(tmp->next->name, tr->name) != 0) {
                printf(" - %s", tmp->name);
                tmp = tmp->prev;
            }
        }
        printf(" - %s(환승)", tr->name);

        int fwd2 = 0;
        chk = trInTo->next;
        while (chk != toHead) {
            if (strcmp(chk->name, endName) == 0) { fwd2 = 1; break; }
            chk = chk->next;
        }
        if (fwd2) {
            SubwayNode* tmp = trInTo->next;
            while (tmp != toHead) {
                printf(" - %s", tmp->name);
                if (strcmp(tmp->name, endName) == 0) break;
                tmp = tmp->next;
            }
        } else {
            SubwayNode* tmp = trInTo->prev;
            while (tmp != toHead) {
                printf(" - %s", tmp->name);
                if (strcmp(tmp->name, endName) == 0) break;
                tmp = tmp->prev;
            }
        }
        printf("\n");
        return 1;
    }
    return 0;
}

int main(void) {
    line1 = (SubwayNode*)malloc(sizeof(SubwayNode));
    line2 = (SubwayNode*)malloc(sizeof(SubwayNode));
    init(line1);
    init(line2);

    char pLine[100];
    FILE* in = fopen("1호선.txt", "r");
    while (fscanf(in, "%s", pLine) == 1) dinsert_last(line1, pLine);
    fclose(in);

    in = fopen("2호선.txt", "r");
    while (fscanf(in, "%s", pLine) == 1) dinsert_last(line2, pLine);
    fclose(in);

    update_transfer();

    int cmd;
    while (1) {
        printf("추가<1> 삭제<2> 노선출력<3> 경로<4> : ");
        if (scanf("%d", &cmd) != 1) break;

        if (cmd == 1) {
            char newName[100], prevName[100], nextName[100];
            printf("1> 역 추가\n");
            printf("역 이름: "); scanf("%s", newName);
            printf("이전 역: "); scanf("%s", prevName);
            printf("다음 역: "); scanf("%s", nextName);

            int inLine1 = 0, inLine2 = 0;
            SubwayNode* p = line1->next;
            while (p != line1) { if (strcmp(p->name, prevName)==0){inLine1=1;break;} p=p->next; }
            p = line2->next;
            while (p != line2) { if (strcmp(p->name, prevName)==0){inLine2=1;break;} p=p->next; }

            if (!inLine1 && !inLine2) {
                p = line1->next;
                while (p != line1) {
                    if (strcmp(p->name, nextName)==0) {
                        inLine1 = 1;
                        if (p->prev != line1) strcpy(prevName, p->prev->name);
                        else strcpy(prevName, "NULL");
                        break;
                    }
                    p = p->next;
                }
                if (!inLine1) {
                    p = line2->next;
                    while (p != line2) {
                        if (strcmp(p->name, nextName)==0) {
                            inLine2 = 1;
                            if (p->prev != line2) strcpy(prevName, p->prev->name);
                            else strcpy(prevName, "NULL");
                            break;
                        }
                        p = p->next;
                    }
                }
            }

            if (inLine1) add_station(line1, newName, prevName);
            else if (inLine2) add_station(line2, newName, prevName);

        } else if (cmd == 2) {
            char delName[100];
            printf("2>역 삭제\n");
            printf("역 이름: "); scanf("%s", delName);

            int found = 0;
            SubwayNode* p = line1->next;
            while (p != line1) { if (strcmp(p->name, delName)==0){found=1;break;} p=p->next; }
            if (found) delete_station(line1, delName);
            else delete_station(line2, delName);

        } else if (cmd == 3) {
            printf("1호선 : "); print_dlist(line1);
            printf("2호선 : "); print_dlist(line2);
            printf("\n");

        } else if (cmd == 4) {
            char startName[100], endName[100];
            printf("4> 경로\n");
            printf("출발 역: "); scanf("%s", startName);
            printf("도착 역: "); scanf("%s", endName);

            int hasWay = print_way(line1, startName, endName);
            if (!hasWay) hasWay = print_way(line2, startName, endName);
            if (!hasWay) hasWay = print_way_transfer(line1, line2, startName, endName);
            if (!hasWay) hasWay = print_way_transfer(line2, line1, startName, endName);
            if (!hasWay) printf("존재하는 경로가 없습니다.\n");
            printf("\n");
        }
    }

    return 0;
}