#include <iostream>
using namespace std;

class QuickFindUF
{
    private:
        int *id, sz;
        int find(int p)
        {
            while (p!=id[p]) p=id[p];
            return p;
        }
    public:
        QuickFindUF(int n=10)
        {
            id = new int[n], sz = n;
            for (int i=0;i<n;i++) id[i] = i;
            cout << "create " << n << " slots" << endl;
        }
        ~QuickFindUF(void)
        {
            cout << "free " << sz << " slots" << endl;
            if (id) delete id;
        }
        bool IsConnected(int p, int q)
        {
            //return id[p] == id[q];
            return find(p) == find(q);
        }
        void Union(int p, int q)
        {
            int rp = find(p), rq = find(q);
            if (rp==rq) return;
            id[rp] = rq;
        }
        void Trace(void)
        {
            for (int i=0;i<sz;i++) cout << id[i] << " ";
            cout << endl;
        }
};

int main(void)
{
    QuickFindUF u1(10);
    u1.Trace();
    //u1.Union(1, 2);
    //u1.Trace();
    //u1.Union(1, 9);
    u1.Union(9, 7);
    u1.Union(8, 6);
    u1.Union(5, 3);
    u1.Union(8, 9);
    u1.Union(5, 4);
    u1.Union(4, 0);
    u1.Union(1, 5);
    u1.Union(5, 6);
    u1.Union(2, 1);
    u1.Trace();
    //cout << "(2, 9): " << u1.IsConnected(2, 9) << endl;
    //cout << "(3, 9): " << u1.IsConnected(3, 9) << endl;
    return 0;
}

