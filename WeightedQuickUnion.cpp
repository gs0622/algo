#include <iostream>
using namespace std;

class QuickFindUF
{
    private:
        int *id, *cnt, sz;
        int find(int p)
        {
            while (p!=id[p]) p=id[p];
            return p;
        }
    public:
        QuickFindUF(int n=10)
        {
            id = new int[n], cnt = new int[n], sz = n;
            for (int i=0;i<n;i++) id[i] = i;
            cout << "create " << n << " slots" << endl;
        }
        ~QuickFindUF(void)
        {
            cout << "free " << sz << " slots" << endl;
            if (id) delete id;
            if (cnt) delete cnt;
        }
        bool IsConnected(int p, int q)
        {
            return find(p) == find(q);
        }
        void Union(int p, int q)
        {
            int rp = find(p), rq = find(q);
            if (rp==rq) return;
            if (cnt[rp]<cnt[rq]) id[rp]=rq, cnt[rq]+=cnt[rp];
            else id[rq]=rp, cnt[rp]+=cnt[rq];
        }
        void Trace(void)
        {
            for (int i=0;i<sz;i++) cout << id[i] << " ";
            cout << endl;
        }
};

int main(void)
{
    QuickFindUF u1(20);
    u1.Trace();
    u1.Union(1, 2);
    u1.Trace();
    u1.Union(1, 9);
    u1.Trace();
    cout << "(2, 9): " << u1.IsConnected(2, 9) << endl;
    cout << "(3, 9): " << u1.IsConnected(3, 9) << endl;
    return 0;
}

