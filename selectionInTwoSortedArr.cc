/*
Selection in two sorted arrays.
Given two sorted arrays a[] and b[], of sizes n1 and n2, respectively,
design an algorithm to find the kth largest key.
The order of growth of the worst case running time of your algorithm should be logn, where n=n1+n2.
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int select(vector<int> a, vector<int> b, int k) {
    int i = 0, x, y, r;
    assert(k <= a.size() + b.size());
    while (i < k) {
        x = a.back(), y = b.back();
        if (x < y)  r = y, b.pop_back();
        else        r = x, a.pop_back();
        i++;
    }
    return r;
}

int main(void) {
    int aa[] = {1, 2, 3};
    int bb[] = {11, 12, 13};
    vector<int> a(aa, aa+3);
    vector<int> b(bb, bb+3);
    cout << select(a, b, 4) << endl;
    return 0;
} 
