#include <algorithm>
#include <iostream>
using namespace std;

class QuickFindUF
{
    private:
        int *id, *cnt, *max, sz;
        int find(int p) {
            while (p != id[p]) p = id[p];
            return p;
        }
    public:
        QuickFindUF(int n=10) {
            id  = new int[n];
            cnt = new int[n];
            max = new int[n];
            sz = n;
            for (int i=0;i<n;i++) id[i] = i, cnt[i] = 1, max[i] = i;
        }
        ~QuickFindUF(void) {
            if (id)  delete id;
            if (cnt) delete cnt;
            if (max) delete max;
        }
        bool IsConnected(int p, int q) {
            return find(p) == find(q);
        }
        int Union(int p, int q) {
            /* delete p */
            int rp = find(p), rq = find(q);
            if (rp == rq) return max[p];
            if (cnt[rp] < cnt[rq])
                id[rp] = rq, cnt[rq] += cnt[rp];
            else
                id[rq] = rp, cnt[rp] += cnt[rq];

            max[p] = std::max(max[p], max[q]);
            return max[p];
        }
        void Trace(void)
        {
            for (int i=0;i<sz;i++) cout << id[i] << " ";
            cout << endl;
        }
};

int main(void)
{
    int successor;
    QuickFindUF u1(20);
    successor = u1.Union(1, 2); // del 1, succ 2
    cout << successor << endl;
    successor = u1.Union(3, 4); // del 3, succ 4
    cout << successor << endl;
    successor = u1.Union(2, 3); // del 2, succ 3->4
    cout << successor << endl;
    successor = u1.Union(18, 19); // del 1, succ 2
    cout << successor << endl;
    return 0;
}

