#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;

int partition(int a[], int v, int lo, int hi)
{
	int i = lo-1, j = hi+1;

	while (true) {
        // find item on lo to swap
		while (a[++i] < v);

        // find item on hi to swap
		while (a[--j] > v);

        // check cross
		if (i >= j) break;

		swap(a[i], a[j]);
	}
    // position j is last one on lo invariant part
	//swap(a[lo], a[j]);

    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
	return j;
}

int main(void) {
    int b[10], n[10];
    for (int i = 0; i < 10; i++) b[i] = n[i] = i;
    srand(time(0));
    random_shuffle(b, b+10);
    //random_shuffle(n, n+10);
    /*for (auto x: b) cout << x << " ";
    cout << endl;
    for (auto y: n) cout << y << " ";
    cout << endl;*/

    int lo = 0, hi = 9;
    for (int i = lo; i <= hi; i++) {
        int bolt = b[i];
        int j = partition(n, b[i], lo, hi);
        int nut = n[j];
        int k = partition(b, n[j], lo, hi);
        cout << bolt << ": " << nut << endl;
        lo++;
    }

    //sort(b, n, m, 0, 9);
    for (auto x: b) cout << x << " ";
    cout << endl;
    for (auto y: n) cout << y << " ";
    cout << endl;
    return 0;
}
