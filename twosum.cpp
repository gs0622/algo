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
long arr[MAX];
int main(int argc, char *argv[])
{
    int i, j, c, d;
    long n;
    const int left = -10000, right = 10000;
    std::unordered_map<long, int> m;
    if (1 == argc) return 0;
    cout << argv[1] << endl;
    freopen(argv[1], "r", stdin);
    for (i=0; i<MAX; i++) {
        if (scanf("%ld", &n) == EOF) break;
        arr[i] = n;
        m[n] = i;
        //cout << m[n] << "\t: " << n << endl;
    }
    n = i;
    cout << "n=" << n << endl;
    int bucket[20000+3] = {};
    for (c=0, i=-10000; i<=10000; i++) {
        for (j=0; j<n; j++) {
            auto it = m.find(i-arr[j]);
            if (it != m.end()) {
                if (it->first == arr[j]) continue; /*distinctness check*/
                //if (it->second == j) continue; /*skip self pairing*/
                int sum = it->first + arr[j];
                if (bucket[sum+10000]==1) continue;
                cout << ++c <<  "\t: " << it->first << "\t: " << arr[j] << "\t: " << sum
                << endl;
                bucket[sum+10000]=1;
                //break;
            }
        }
    }
    for (i=0, d=0; i<20000+3; i++) if (bucket[i]==1) d++;
    cout << "total: " << c << ": " << d << endl;
    return 0;
}

