#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// in: initial seats state B, target seats state A, out: steps required
	// O(V+E) time, O(V) space: V for total vertices in terms of seats states
	int swapSeats(vector<int>& B, vector<int>& A) {
                string AA, BB;
                for (int i=0; i<A.size(); ++i)
                        AA+=A[i]+'0', BB+=B[i]+'0';
                queue<string> q;
                unordered_set<string> visit;                            // hashset of visited state
                q.push(BB);                                             // initial state
                int res=0;
                while (!q.empty()) {
                        int n=q.size();
                        for (int i=0; i<n; ++i) {
                                string CC=q.front(); q.pop();           
                                if (CC==AA)                             // match target, return require steps
                                        return res;                     
                                visit.insert(CC);                       // this state is visited
                                int empty=CC.find('0');                 // locate empty seat 
                                for (int j=0; j<CC.size(); ++j) {       // enumerate all the nearest neighboring states
                                        if (j!=empty) {
                                                swap(CC[j], CC[empty]); 
                                                if (visit.count(CC)==0)    // skip visited states
                                                        q.push(CC);
                                                swap(CC[j], CC[empty]);
                                        }
                                }
                        }
                        ++res;
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
        vector<int> after4{3,4,2,0,1};
        vector<int> after5{3,4,0,2,1};
        vector<int> afterx(before);
	
	cout << s.swapSeats(before, after1) << endl;
	cout << s.swapSeats(before, after2) << endl;
	cout << s.swapSeats(before, after3) << endl;
	cout << s.swapSeats(before, after4) << endl;

	srand(time(0));
	int worse=0, res;
	for (int i=0; i<10; ++i) {	// observation of random
		random_shuffle(afterx.begin(), afterx.end());
		res=s.swapSeats(before, afterx);
		worse=max(res,worse);
		cout << res << ' ';
	}
	cout << endl << "max: " << worse << endl;
}
