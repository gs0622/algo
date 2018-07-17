#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_set>
using namespace std;

class QuickFindUF
{
    private:
        int *parent, *size, *max, count;

        // find root of p
        int find(int p) {
            while (p != parent[p]) {
                parent[p] = parent[parent[p]]; // path compression
                p = parent[p];
            }
            return p;
        }

    public:
        QuickFindUF(int n=10) {
            parent = new int[n];
            size = new int[n];
            max = new int[n];
            count = n;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
                max[i] = i;
            }
        }
        ~QuickFindUF(void) {
            if (parent)
                delete parent;
            if (size)
                delete size;
            if (max)
                delete max;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unite(int p, int q) {
            int rp = find(p), rq = find(q);
            if (rp == rq) return;

            int maxRP = max[rp];
            int maxRQ = max[rp];

            if (size[rp] < size[rq]) {
                parent[rp] = rq;
                size[rq] += size[rp];
                max[rq] = (maxRP > maxRQ)? maxRP: maxRQ;
            } else {
                parent[rq] = rp;
                size[rp] += size[rq];
                max[rp] = (maxRQ > maxRP)? maxRQ: maxRP;
            }
        }
        int findMax(int p) {
            return max[find(p)];
        }
        void traceP(void) {
            for (int i = 0; i < count; i++)
                cout << find(i) << " ";
            cout << endl;
        }
        void traceG(void) {
            unordered_set<int> us;
            for (int i = 0; i < count; i++) {
                us.insert(find(i));
            }
            // print connected components
            for (auto x: us) cout << x << " ";
            cout << endl;
        }
};

int main(void)
{
    int n, p, q, cnt = 0;
    cin >> n;
    QuickFindUF uf(n);

    while (cin >> p >> q) {
        cout << std::setw(3) <<  p << " - " << q << ": " << uf.isConnected(p, q) << endl;
        if (false == uf.isConnected(p, q)) {
            uf.unite(p, q);
            cnt++;
            if (cnt == n-1)
                break;
        }
    }
    cout << ((cnt == n-1)? "": "not ") << "all unioned" << endl;
    uf.traceG();
    uf.traceP();
    for (int i = 0; i < n; i++)
        cout << uf.findMax(i) << " ";
    cout << endl;
    return 0;
}

