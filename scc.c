/* ref: http://www.geeksforgeeks.org/strongly-connected-components/
 *      http://www.geeksforgeeks.org/connectivity-in-a-directed-graph/
 *      https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_EDGES	8388608 /*2^23*/
#define MAX_VERTICES	1048576 /*2^20*/

struct edge {
	int src, dest;
};

struct vertex {
	struct edge* start; /* start of edges  */
	int outdegree, visit;
};

struct graph {
	struct edge E[MAX_EDGES];
	struct vertex V[MAX_VERTICES]; /* pointer to edges*/
	int e, v; /* counters of vertices and edges */
};

static struct graph G;
static struct graph Grev;/* for G-rev*/

int cmp1(const void *p, const void *q)
{
	struct edge *r = (struct edge *)p, *s = (struct edge *)q;
	return (r->src - s->src);
}

int cmp2(const void *p, const void *q)
{
	int i = *(int *)p, j = *(int *)q;
	return (j - i); /* decending */
}

int finish[MAX_VERTICES]; /* for phase1 */
int scc[MAX_VERTICES]; /* for phase2 */
int top[MAX_VERTICES]; /* for result */
int finishtime; /* for phase1 */
int sccgroup; /* for phase2 */

void dfs1(struct graph *g, int v)
{
	int i;
	struct edge *e;
	g->V[v].visit = 1;
	e = g->V[v].start;
	for (i=0; i<g->V[v].outdegree; i++)
		if (g->V[e[i].dest].visit == 0)
			dfs1(g, e[i].dest);
	finish[finishtime++] = v;
	//printf("f[%d]=%d\n", finishtime-1, v);
}

void dfs2(struct graph *g, int v)
{
	int i;
	struct edge *e;
	g->V[v].visit = 1;
	e = g->V[v].start;
	for (i=0; i<g->V[v].outdegree; i++)
		if (g->V[e[i].dest].visit == 0)
			dfs2(g, e[i].dest);
	scc[v] = sccgroup;
	//printf("scc[%d]=%d\n", v, sccgroup);
}

void dfsloop_phase1(struct graph *g)
{
	int i;
	finishtime = 1;
	for (i=1; i<=g->v; i++) /* index is 1 base */
		if (g->V[i].visit == 0)
			dfs1(g, i);
}

void dfsloop_phase2(struct graph *g)
{
	int i;
	sccgroup = 0;
	for (i=g->v; i>=1; i--) { /* index is 1 base */
		if (g->V[finish[i]].visit == 0) {
			dfs2(g, finish[i]);
			sccgroup++;
		}
	}

}
int main(int argc, char **argv)
{
	char *token, *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *stream;
	int i, j, u, v, old, max = 0;

	if (argc < 2) return 0;
	//printf("%s\n", argv[1]);
	stream = fopen(argv[1], "r");

	for (i=0, j=0, old = -1; stream && (read = getline(&line, &len, stream)) != -1; i++) {
		//printf("%s", line);
		token = strtok(line, "\t ");
		u = atoi(token);
		token = strtok(NULL, "\t ");
		v = atoi(token);
		G.E[i].src = u;
		G.E[i].dest = v;
		if (u > max) max = u;
		if (v > max) max = v;
		if (u != old) {
			assert(G.E[i].src == u);
			G.V[u].start = &G.E[i];
			G.V[u].outdegree = 1;
			old = u;
		} else {
			G.V[u].outdegree++;
		}
		//printf("%d -> %d\n", u, v);
	}
	G.e = Grev.e = i;
	G.v = Grev.v = max;
	printf("e=%d v=%d\n", G.e, G.v);
	//printf(" -- %d\n", G.e);
	for (i=0; i<Grev.e; i++) {
		Grev.E[i].src = G.E[i].dest;
		Grev.E[i].dest = G.E[i].src;
		//printf("%d -> %d\n", Grev.E[i].src, Grev.E[i].dest);
	}
	qsort(&Grev.E[0], Grev.e, sizeof(struct edge), cmp1);
	for (i=j=0, old=-1; i<Grev.e; i++) {
		u = Grev.E[i].src;
		if (u != old) {
			assert(Grev.E[i].src == u);
			Grev.V[u].start = &Grev.E[i];
			Grev.V[u].outdegree = 1;
			old = u;
		} else {
			Grev.V[u].outdegree++;
		}
		//printf("%d -> %d\n", Grev.E[i].src, Grev.E[i].dest);
	}
	dfsloop_phase1(&Grev);
	dfsloop_phase2(&G);
	for (i=1; i<=G.v; i++) {
		top[scc[i]]++;
	}
	qsort(top, G.v, sizeof(int), cmp2);
	printf("%d,%d,%d,%d,%d\n", top[0], top[1], top[2], top[3], top[4]);
	free(line);
	fclose(stream);
	return 0;	
}


