#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <climits>
using namespace std;
int w[200][200]; /*Graph*/
int d[200], visit[200], prev[200];

void dijkstra(int n)
{
    int i = n, j, min, a, b;

    while (i--) {
        min = INT_MAX, a=0;
        for (j=0; j<n; j++) { /*min*/
            if (!visit[j] && d[j] < min) {
                min = d[j], a = j;
            }
        }
        if (min == INT_MAX) break;
        visit[a] = 1;
        for (b=0; b<n; b++) {
            if (w[a][b] == INT_MAX) continue; /*no edge*/
            if (d[b] > d[a] + w[a][b]) {
                d[b] = d[a] + w[a][b];
                prev[b] = a; 
            }
        }
    }
}
int main(int argc, char **argv)
{
	ifstream ifs;
	int i, j, n = atoi(argv[1]);
	int u, v, weight;
	char *token, *buf = new char[1024];
	string str;

    for (i=0; i<200; i++)
        for (j=0; j<200; j++)
            w[i][j] = INT_MAX;
    w[0][0] = 0;
	ifs.open(argv[2]);
	while (ifs.good()) {
		ifs.getline(buf, 1024);
		token = strtok(buf, "\t\r ");
		if (!token) break;
		u = atoi(token);
		while (token) {
			token = strtok(NULL, ",\r");
			if (!token) break;
			v = atoi(token);
			token = strtok(NULL, "\t ");
			weight = atoi(token);
            w[u-1][v-1] = weight;
			//cout << u << "->" << v << ": " << weight << endl;
		}
	}
    for (i=0; i<200; i++)
        visit[i] = 0, d[i] = INT_MAX, prev[i] = -1;
    d[0] = 0;
    dijkstra(n);

    if (argc < 4) {
        for (i=0; i<n; i++) {
            cout << i+1 << ":" <<d[i] << " ";
            j = i;
            while (prev[j] != -1) {
                cout << j+1 << " ";
                j = prev[j];
            }
            cout << endl;
        }
    } else { /*show these vertices only*/
        /*7,37,59,82,99,115,133,165,188,197*/
        cout << d[6] << ',' << d[36] << ',' << d[58] << ',';
        cout << d[81] << ',' << d[98] << ',' << d[114] << ',';
        cout << d[132] << ',' << d[164] << ',' << d[187] << ',';
        cout << d[196] << endl;
    }
	ifs.close();
	delete[] buf;
	return 0;
}
