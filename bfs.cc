#include <iostream>
#include <queue>
using namespace std;
int adj[9][9];
int visit[9];
void bfs(int s)
{
	std::queue<int> q;
	visit[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < 9; i += 1) {
			if (adj[v][i] && !visit[i]) {
				visit[v] = 1;
				q.push(i);
			}
		}
	}
}

struct node {
	int data; struct node *next;
};
void add(struct node **ref, int data)
{
	struct node *n = new struct node;
}

int main(void)
{
	return 0;
}
