/* ref: http://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-1-introduction-and-implementation/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int vertex;
	struct node *next;
};

struct edge {
	int src, dest;
};

struct vertex {
	int parent, rank;
};

struct graph {
	int V, E; /* edgesers of vertices and edges */
	struct edge *Edges;
	struct vertex *Vertices;
};

int find(struct vertex *v, int i)
{
	if (v[i].parent != i)
		v[i].parent = find(v, v[i].parent);
	return v[i].parent;
}

void merge(struct vertex *v, int x, int y)
{
	int rx = find(v, x), ry = find(v, y);
	if (v[rx].rank < v[ry].rank) v[rx].parent = ry;
	else if (v[rx].rank > v[ry].rank) v[ry].parent = rx;
	else v[ry].parent = rx, v[rx].rank++;
}

int mincuts(struct graph *g)
{
	int i, u1, u2, v1, v2, cuts = 0, left = g->V, e = g->E;
	struct vertex *v = g->Vertices;
	while (left > 2) {
		i = rand() % g->E;
		v1 = g->Edges[i].src, v2 = g->Edges[i].dest;
		u1 = find(v, v1), u2 = find(v, v2);
		if (u1 == u2) continue; /* same union */
		//printf("V=%3d contracting %3d/%3d - %3d/%3d\n", left, v1, u1, v2, u2);
		merge(g->Vertices, u1, u2);
		left--;
	}
	//printf("e=%3d\n", e);
	for (i=0; i<e; i++) {
		v1 = g->Edges[i].src, v2 = g->Edges[i].dest;
		u1 = find(v, v1), u2 = find(v, v2);
		//printf("%3d - %3d\n", u1, u2);
		//printf("%3d/%3d - %3d/%3d\n", v1, u1, v2, u2);
		if (u1 != u2) cuts++;
	}
	return cuts/2;
}

int main(int argc, char **argv)
{
	char *line = NULL, *token;
	int i, j, k, min, cuts;
	int n = (argc > 2)? atoi(argv[2]): 200;
	int loops = (argc > 3)? atoi(argv[3]): 10;
	size_t len = 0;
	ssize_t read;
	FILE *stream;
	struct graph G = {0};
	int *aux = malloc(n * sizeof(int)); /* temp buf */

	srand(time(NULL));
	stream = fopen(argv[1], "r");
	G.V = n, G.Vertices = malloc((n+1) * sizeof(struct vertex));
	for (i=1; stream && (read = getline(&line, &len, stream)) != -1; i++) {
		int c = 0;
		token = strtok(line, "\t ");
		if (!token) continue;
		//printf("%d :", i);
		token = strtok(NULL, "\t ");
		while (token) { /* scan edges to aux */
			int to = atoi(token);
			if (to == 0) break;
			aux[c++] = to;
			token = strtok(NULL, "\t ");
		}
		G.Edges = realloc(G.Edges, (G.E + c) * sizeof(struct edge));
		for (j=0, k=G.E; j<c; j++) { /* plot edges */
			G.Edges[k].src = i, G.Edges[k++].dest= aux[j];
		}
		G.Vertices[i].parent = i; /* vertex starts from 1 */
		G.E += c;
	}
	min = G.E;
	while (loops--) {
		for (i=1; i<=G.V; i++) {
			G.Vertices[i].parent = i;
			G.Vertices[i].rank = 0;
		}
		cuts = mincuts(&G);
		if (min > cuts) min = cuts;
		printf("%d\n", cuts);
	}
	printf("mincuts=%d\n", min);
	free(line);
	free(G.Edges);
	free(G.Vertices);
	free(aux);
	fclose(stream);
	return 0;	
}

