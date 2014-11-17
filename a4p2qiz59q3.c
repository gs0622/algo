/*quiz59 q3, sees=926242*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;
    int visit;
    struct node *next;
};

#define VERT(x)  (x-'A')

void list(struct node *p)
{
    if (!p) return;
    else printf("%c: ", p->v + 'A'), p = p->next;
    while (p) printf("%c ", p->v + 'A'), p = p->next;
    puts("");
}

void dfs(struct node *s, struct node *vert)
{
    struct node *p = &vert[s->v];
    if (1 == p->visit) return;
    printf("%c ", p->v + 'A');
    p->visit = 1;
    while (p->next) {
        dfs(&vert[p->next->v], vert);
        p = p->next;
    }
}

int main(void)
{
    struct node vert[10] = {}; /*A-J*/
    struct node edge[22] = {};
    edge[0].v = VERT('G'), edge[0].next = &edge[1];
    edge[1].v = VERT('F'), edge[1].next = NULL;
    vert[0].v = VERT('A'), vert[0].next = &edge[0]; /*A: G F*/

    edge[2].v = VERT('H'), edge[2].next = NULL;
    vert[1].v = VERT('B'), vert[1].next = &edge[2]; /*B: H*/

    edge[3].v = VERT('D'), edge[3].next = &edge[4];
    edge[4].v = VERT('I'), edge[4].next = NULL;
    vert[2].v = VERT('C'), vert[2].next = &edge[3]; /*C: D I*/

    edge[5].v = VERT('E'), edge[5].next = &edge[6];
    edge[6].v = VERT('I'), edge[6].next = &edge[7];
    edge[7].v = VERT('C'), edge[7].next = NULL;
    vert[3].v = VERT('D'), vert[3].next = &edge[5]; /*D: E I C*/

    edge[8].v = VERT('D'), edge[8].next = &edge[9];
    edge[9].v = VERT('J'), edge[9].next = &edge[10];
    edge[10].v = VERT('I'), edge[10].next = NULL;
    vert[4].v = VERT('E'), vert[4].next = &edge[8]; /*E: D J I*/

    edge[11].v = VERT('G'), edge[11].next = &edge[12];
    edge[12].v = VERT('A'), edge[12].next = NULL;
    vert[5].v = VERT('F'), vert[5].next = &edge[9]; /*F: G A*/

    edge[13].v = VERT('F'), edge[13].next = &edge[14];
    edge[14].v = VERT('A'), edge[14].next = NULL;
    vert[6].v = VERT('G'), vert[6].next = &edge[13]; /*G: F A*/

    edge[15].v = VERT('B'), edge[17].next = NULL;
    vert[7].v = VERT('H'), vert[7].next = &edge[15]; /*H: B*/

    edge[16].v = VERT('D'), edge[16].next = &edge[17];
    edge[17].v = VERT('J'), edge[17].next = &edge[18];
    edge[18].v = VERT('E'), edge[18].next = &edge[19];
    edge[19].v = VERT('C'), edge[19].next = NULL;
    vert[8].v = VERT('I'), vert[8].next = &edge[16]; /*I: D J E C*/

    edge[20].v = VERT('E'), edge[20].next = &edge[21];
    edge[21].v = VERT('I'), edge[21].next = NULL;
    vert[9].v = VERT('J'), vert[9].next = &edge[20]; /*J: E I*/

    if (0) {
        dfs(&vert[0], vert);
        puts("");
    } else {
        int i;
        for (i = 0; i < 10; i++) list(&vert[i]);
    }
    return 0;
}
