/*q59, sees=676773*/
#include <stdio.h>

struct node {
    int v;
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

void dfs(struct node *p)
{
    /*TBD*/
}

int main(void)
{
    struct node vert[8] = {}; /*A-H*/
    struct node edge[18] = {};
    edge[0].v = VERT('B'), edge[0].next = &edge[1];
    edge[1].v = VERT('F'), edge[1].next = NULL;
    vert[0].v = VERT('A'), vert[0].next = &edge[0]; /*A: B F*/

    edge[2].v = VERT('A'), edge[2].next = NULL;
    vert[1].v = VERT('B'), vert[1].next = &edge[2]; /*B: A*/

    edge[3].v = VERT('D'), edge[3].next = &edge[4];
    edge[4].v = VERT('F'), edge[4].next = &edge[5];
    edge[5].v = VERT('G'), edge[5].next = NULL;
    vert[2].v = VERT('C'), vert[2].next = &edge[3]; /*C: D F G*/

    edge[6].v = VERT('C'), edge[6].next = &edge[7];
    edge[7].v = VERT('G'), edge[7].next = NULL;
    vert[3].v = VERT('D'), vert[3].next = &edge[6]; /*D: C G*/

    edge[8].v = VERT('F'), edge[8].next = NULL;
    vert[4].v = VERT('E'), vert[4].next = &edge[8]; /*E: F*/

    edge[9].v = VERT('G'), edge[9].next = &edge[10];
    edge[10].v = VERT('E'), edge[10].next = &edge[11];
    edge[11].v = VERT('C'), edge[11].next = &edge[12];
    edge[12].v = VERT('A'), edge[12].next = NULL;
    vert[5].v = VERT('F'), vert[5].next = &edge[9]; /*F: G E C A*/

    edge[13].v = VERT('D'), edge[13].next = &edge[14];
    edge[14].v = VERT('F'), edge[14].next = &edge[15];
    edge[15].v = VERT('H'), edge[15].next = &edge[16];
    edge[16].v = VERT('C'), edge[16].next = NULL;
    vert[6].v = VERT('G'), vert[6].next = &edge[13]; /*G: D F H C*/

    edge[17].v = VERT('G'), edge[17].next = NULL;
    vert[7].v = VERT('H'), vert[7].next = &edge[17]; /*H: G*/
    if (1) {
        int i;
        for (i = 0; i < 8; i++) list(&vert[i]);
    }
    return 0;
}
