#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int vertex;
	struct node *next;
};

int main(int argc, char **argv)
{
	char filename[32], *line = NULL, *token;
	int i = 0, n = (argc > 1)? atoi(argv[1]): 200;
	size_t len = 0;
	ssize_t read;
	FILE *f;
	struct node *v = calloc(n, sizeof(struct node));
	struct node **head = calloc(n, sizeof(struct node *));
	int *aux = malloc(n * sizeof(int));

	sprintf(filename, "%d.txt", n);
	f = fopen(filename, "r");
	while(f && (read = getline(&line, &len, f)) != -1) {
		int j, edges = 0;
		token = strtok(line, "\t ");
		if (!token) continue;
		v[i].vertex = atoi(token);
		printf("%d: ", v[i].vertex);
		token = strtok(NULL, "\t ");
		while (token) {
			int to = atoi(token);
			if (to == 0) break;
			//printf("%d ", to);
			aux[edges++] = to;
			token = strtok(NULL, "\t ");
		}
		head[i] = calloc(edges, sizeof(struct node));
		for (j=0; j<edges; j++) {
			head[i][j].vertex = aux[j];
			printf("%d ", aux[j]);
		}
		printf(": %d\n", edges);
		i++;
	}
	for (i=0; i<n; i++) {
		free(head[i]);
	}
	free(line);
	free(v);
	free(head);
	free(aux);
	fclose(f);
	return 0;	
}

