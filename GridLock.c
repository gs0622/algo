#include <stdio.h>
#include <string.h>

int adj[9][9] = {
    { 0, 1, 0, 1, 1, 1, 0, 1, 0},
    { 1, 0, 1, 1, 1, 1, 1, 0, 1},
    { 0, 1, 0, 1, 1, 1, 0, 1, 0},
    { 1, 1, 1, 0, 1, 0, 1, 1, 1},
    { 1, 1, 1, 1, 0, 1, 1, 1, 1},
    { 1, 1, 1, 0, 1, 0, 1, 1, 1},
    { 0, 1, 0, 1, 1, 1, 0, 1, 0},
    { 1, 0, 1, 1, 1, 1, 1, 0, 1},
    { 0, 1, 0, 1, 1, 1, 0, 1, 0}
};

int visit[9];
int pattern = 0;

void dfs(int s)
{
    int i;
    visit[s] = 1;
    for (i = 0; i < 9; i++) {
        if (adj[s][i] == 1 && !visit[i])
            pattern++, dfs(i);
    }
    visit[s] = 0;
}

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 9; i++) {
        memset(visit, 0, 9*sizeof(int));
        dfs(i);
    }
    printf("%d\n", pattern);
    return 0;
}
