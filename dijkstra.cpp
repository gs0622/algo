#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int w[200][200]; /*Graph*/
int d[200], visit[200], prev[200];
void dijkstra(int n)
{
    int i, j, alt, min, a;

    for (i=0; i<n; i++) {
        min = 1000000, a=0;
        for (j=0; j<n; j++) { /*min*/
            if (!visit[j] && d[j] < min)
                min = d[j], a = j;
                //cout << i << ": " << min << ": "<< j << endl;
        }
        if (min == 1000000) break;
        cout << i+1 << ": " << a << ": " << min << endl;
        visit[a] = 1;
        for (j=0;j<n;j++) {
            if (w[a][j] == 1000000) continue; /*no edge*/
            alt = d[a] + w[a][j];
            if (alt < d[j]) {
                d[j] = alt;
                prev[j] = a; 
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
            w[i][j] = 1000000;
    w[0][0] = 0;
	ifs.open(argv[2]);
	while (ifs.good()) {
		ifs.getline(buf, 1024);
		token = strtok(buf, "\t\r");
		if (!token) break;
		u = atoi(token);
		while (token) {
			token = strtok(NULL, ",\r");
			if (!token) break;
			v = atoi(token);
			token = strtok(NULL, "\t ");
			weight = atoi(token);
            w[u-1][v-1] = weight;
			cout << u << "->" << v << ": " << weight << endl;
		}
	}
    for (i=0; i<200; i++)
        visit[i] = 0, d[i] = 1000000, prev[i] = -1;
    d[0] = 0;
    dijkstra(n);
    /*7,37,59,82,99,115,133,165,188,197*/
#if 1
    for (i=0; i<n; i++) {
        cout << i+1 << ":" <<d[i] << " ";
        j = i;
        while (prev[j] != -1) {
            cout << j+1 << " ";
            j = prev[j];
        }
        cout << endl;
    }
#else
    cout << d[6] << ',' << d[36] << ',' << d[58] << ',';
    cout << d[81] << ',' << d[98] << ',' << d[114] << ',';
    cout << d[132] << ',' << d[164] << ',' << d[187] << ',';
    cout << d[196] << endl;
#endif
	ifs.close();
	delete[] buf;
	return 0;
}
