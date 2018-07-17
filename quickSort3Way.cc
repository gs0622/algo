#include <algorithm>
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b, *b = tmp;
}

void sort(int a[], int lo, int hi) {
    if (hi <= lo) return;
    int lt = lo, gt = hi, pivot = a[lo], i = lo;
    while (i <= gt) {
        if      (a[i] < pivot) swap(&a[i++], &a[lt++]);
        else if (a[i] > pivot) swap(&a[i],   &a[gt--]);
        else i++; // equal keys
    }
    // invariant: a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi].
    sort(a, lo, lt-1);
    sort(a, gt+1, hi);
}

int main(void) {
    int a[10] = {1, 2, 3, 3, 3, 6, 7, 7, 9, 10};
    srand(time(0));
    random_shuffle(&a[0], &a[9]);
    for (auto x: a) cout << x << " ";
    cout << endl;
    sort(a, 0, 9);
    for (auto x: a) cout << x << " ";
    cout << endl;
    return 0;
}
