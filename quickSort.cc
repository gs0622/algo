#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

int partition(int a[], int lo, int hi)
{
	int i = lo, j = hi+1, pivot = a[lo];

	while (true) {
        // find item on lo to swap
		while (a[++i] < pivot)
			if (i == hi) break;

        // find item on hi to swap
		while (a[--j] > pivot)
			if (j == lo) break; // redundant since a[lo] as sentinel

        // check cross
		if (i >= j) break;

		swap(a[i], a[j]);
	}
    // position j is last one on lo invariant part
	swap(a[lo], a[j]);

    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
	return j;
}

void sort(int a[], int lo, int hi) {
    // TBD: shuffle before calling-in
    if (hi <= lo) return;
    int j = partition(a, lo, hi);
    sort(a, lo, j-1);
    sort(a, j+1, hi);
}

bool isSorted(int a[], int sz) {
    for (int i = 1; i < sz; i++)
        if (a[i] < a[i-1]) return false;
    return true;
}

// return kth (index from 0) element
int select(int a[], int sz, int k) {
    assert(k >= sz);
    // TBD: shuffle
    int lo = 0, hi = sz - 1;
    while (lo < hi) {
        int j = partition(a, lo, hi);
        if      (j > k) hi = j - 1;
        else if (j < k) lo = j + 1;
        else return j;
    }
    return a[lo];
}

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = i;
    srand(time(0));
    random_shuffle(a, a+10);
    for (auto x: a) cout << x << " ";
    cout << endl;
    sort(a, 0, 9);
    //std::sort(a, a+10);
    for (auto x: a) cout << x << " ";
    cout << endl;
    cout << isSorted(a, 10) << endl;
    return 0;
}
