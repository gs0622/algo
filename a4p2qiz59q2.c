/*quiz59 q2, sees=140286*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    struct node *next;
};

#define VERT(x)  (x-'A')

struct queue {
    struct node *front;
    struct node *back;
    int size;
};

int size(struct queue *q) { return q->size; }

int empty(struct queue *q) { return (0 == size(q)); }

int front(struct queue *q) { return q->front->v; }

void push(struct queue *q, struct node *r)
{
    struct node *p = malloc(sizeof(struct node));
    *p = *r;
    //printf("push %d\n", p->v);
    if (empty(q)) q->front = q->back = p;
    else q->back->next = p, q->back = p;
    q->size += 1;
}

void pop(struct queue *q)
{
    struct node *p = q->front;
    q->size -= 1;
    if (empty(q)) q->back = q->front = NULL;
    else q->front = p->next;
    //printf("pop %d\n", p->v);
    free(p);
}

void list(struct node *p)
{
    if (!p) return;
    else printf("%c: ", p->v + 'A'), p = p->next;
    while (p) printf("%c ", p->v + 'A'), p = p->next;
    puts("");
}

void bfs(struct node *s, struct node *vert)
{
    struct queue q = {};
    int visit[8] = {};
    push(&q, s);
    while (!empty(&q)) {
        int v = front(&q);
        pop(&q);
        if (0 == visit[v]) {
            struct node *p = &vert[v];
            printf("%c ", v + 'A');
            visit[v] = 1;
            while (p->next)
                push(&q, p->next), p = p->next;
        }
    }
}

int main(void)
{
    int i;
    struct node vert[8] = {}; /*A-H*/
    struct node edge[20] = {};
    for (i = 0; i < 8; i++) vert[i].v = VERT('A'+i);
    edge[0].v = VERT('F'), edge[0].next = NULL;
    vert[0].next = &edge[0]; /*A: F*/

    edge[1].v = VERT('C'), edge[1].next = &edge[2];
    edge[2].v = VERT('G'), edge[2].next = &edge[3];
    edge[3].v = VERT('F'), edge[3].next = NULL;
    vert[1].next = &edge[1]; /*B: C G F*/

    edge[4].v = VERT('B'), edge[4].next = &edge[5];
    edge[5].v = VERT('D'), edge[5].next = &edge[6];
    edge[6].v = VERT('G'), edge[6].next = NULL;
    vert[2].next = &edge[4]; /*C: B D G*/

    edge[7].v = VERT('C'), edge[7].next = &edge[8];
    edge[8].v = VERT('G'), edge[8].next = &edge[9];
    edge[9].v = VERT('H'), edge[9].next = NULL;
    vert[3].next = &edge[7]; /*D: C G H*/

    edge[10].v = VERT('F'), edge[10].next = NULL;
    vert[4].next = &edge[10]; /*E: F*/

    edge[11].v = VERT('G'), edge[11].next = &edge[12];
    edge[12].v = VERT('E'), edge[12].next = &edge[13];
    edge[13].v = VERT('A'), edge[13].next = &edge[14];
    edge[14].v = VERT('B'), edge[14].next = NULL;
    vert[5].next = &edge[11]; /*F: G E A B*/

    edge[15].v = VERT('F'), edge[15].next = &edge[16];
    edge[16].v = VERT('D'), edge[16].next = &edge[17];
    edge[17].v = VERT('B'), edge[17].next = &edge[18];
    edge[18].v = VERT('C'), edge[18].next = NULL;
    vert[6].next = &edge[15]; /*G: F D B C*/

    edge[19].v = VERT('D'), edge[19].next = NULL;
    vert[7].v = VERT('H'), vert[7].next = &edge[19]; /*H: D*/

    if (1) {
        bfs(&vert[0], vert);
        puts("");
    } else {
        int i;
        for (i = 0; i < 8; i++) list(&vert[i]);
    }
    return 0;
}
