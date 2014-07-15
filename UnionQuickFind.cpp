#include <iostream>
using namespace std;

class QuickFindUF
{
    private:
        int *id, sz;
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
            return id[p] == id[q];
        }
        void Union(int p, int q)
        {
            if (IsConnected(p, q)) return;
            for (int i=0, pid=id[p];i<sz;i++)
                if (id[i]==pid) id[i] = id[q];
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

