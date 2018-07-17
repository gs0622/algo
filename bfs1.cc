#include <iostream>
#include <queue>
using namespace std;
struct node {
	int vertex;
	struct node *next;
};
struct node *list[9];
int visit[9];
void bfs(int s)
{
	std::queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (0 == visit[v]) {
			visit[v] = 1;
			struct node *n = list[v];
			while (n) {
				if (!visit[n->vertex])
					q.push(n->vertex);
				n = n->next;
			}
		}
	}
}

int main(void)
{
	return 0;
}
