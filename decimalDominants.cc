#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dominants(int a[], int sz) {
    unordered_map<int, int> m;
    for (int i = 0; i < sz; i++)
        m[a[i]]++;
    int n = m.size();
    vector<int> r;
    for (auto x: m) {
        if (x.second > n/10)
            r.push_back(x.first);
    }
    return r; 
}
int main(void) {
    int a[] = { 1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 5, 6, 6, 7, 8, 9, 10, 10, 10, 10};
    vector<int> r = dominants(a, sizeof(a)/sizeof(int));
    for (auto x: r) cout << x << " ";
    cout << endl;
    return 0;
}
