#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// in: initial seats state B, target seats state A, out: steps required
	// O(V+E) time, O(V) space: V for total vertices in terms of seats states
	int swapSeats(vector<int>& B, vector<int>& A) {
                int cnt=0;
                queue<vector<int>> q;
                q.push(B);
                while (!q.empty()) {
                        int n=q.size();
                        for (int i=0; i<n; ++i) {
                                vector<int> C=q.front(); q.pop();       // C for candidate vector state
                                if (C==A)
                                        return cnt;
                                int empty;                              // index of 0, aka. empty seat
                                for (int j=0; j<C.size(); ++j) {        // O(n) to find empty seat
                                        if (C[j]==0) {
                                                empty=j;
                                                break;
                                        }       
                                }       
                                for (int j=0; j<C.size(); ++j)          // O(n) to enumarate all next states
                                        if (j!=empty) {
                                                swap(C[j],C[empty]);
                                                q.push(C);
                                                swap(C[j],C[empty]);
                                        }       
                        }               
                        ++cnt;
                }       
                return -1;
	}
};
int main(){
	Solution s;
	vector<int> before{1,2,0,3,4};
	// e.g., 12034 has 4 neighbors 10234, 02134, 12304, 12430.
	vector<int> after1{1,0,2,3,4};
        vector<int> after2{1,4,2,3,0};
        vector<int> after3{0,4,2,3,1};
        vector<int> after4{0,2,1,3,4};
        vector<int> after5{0,4,3,2,1};
	cout << s.swapSeats(before, after1) << endl;
	cout << s.swapSeats(before, after2) << endl;
	cout << s.swapSeats(before, after3) << endl;
	cout << s.swapSeats(before, after4) << endl;
	cout << s.swapSeats(before, after5) << endl;
}
