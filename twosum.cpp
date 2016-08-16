#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define MAX 1000000
void twosum(int arr[], int sz, int sum)
{
    int i, j, postive[MAX] = {}, negative[MAX]={};
    for (i = 0; i < sz; i++) {
        j = sum - arr[i];
        if ((j >= 0) && (1 == postive[j]))
            printf("%d %d\n", arr[i], j);
        else if ((j < 0) && (1 == negative[j * (-1)]))
            printf("%d %d\n", arr[i], j);
        if (arr[i] >= 0) postive[arr[i]] = 1;
        else negative[arr[i] * (-1)] = 1;
    }
}
int arr[MAX];
int main(int argc, char *argv[])
{
    int i, j, n, c;
    const int left = -10000, right = 10000;
    std::unordered_map<int, int> m;
    if (1 == argc) return 0;
    freopen(argv[1], "r", stdin);
    for (i=0; i<MAX; i++) {
        scanf("%d", &n);
        arr[i] = n;
        m[n] = i;
        //cout << m[n] << "\t: " << n << endl;
    }
    for (c=0, i=-10000; i<=10000; i++) {
        for (j=0; j<MAX; j++) {
            auto it = m.find(i-arr[j]);
            if (it != m.end()) {
                //if (it->second <= j) continue;
                cout << ++c <<  ": " << it->first << ": " << it->second << "\t: " << arr[j] << ": " << j
                << endl;
                break;
            }
        }
    }
    cout << "total: " << c << endl;
    return 0;
}

