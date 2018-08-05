#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// O(n) time, O(n) space
	// 0123 -> 3210
	// e.g., 0123 - 3120 - 3021 - 3201 - 3210
	int swapSeats3(vector<int> B, vector<int> A) {
		int steps=0, tmp;
		unordered_map<int,int> mp;
		for (int i=0; i<B.size(); ++i)			// O(n) space
			mp[B[i]]=i;
		for (int i=0; i<B.size(); ++i) {
			if (B[i]!=A[i]) {
				//steps+=B[i]? 2:1;
				if (B[i]!=0) {			// step-1: switch incorrect person to empty
					tmp = B[i];
					swap(B[i], B[mp[0]]);
					mp[tmp]=mp[0], mp[0]=i;	// tricky: B[i] has been changed
					++steps;
					//if (B==A) break;	// save step-2, but costs O(n)
				}
				if (A[i]==0) continue;		// save step-2
				swap(B[i], B[mp[A[i]]]);	// step-2: move correct one to here
				//tmp=mp[A[i]], mp[A[i]]=i, mp[0]=tmp;
				swap(mp[A[i]], mp[0]);
				++steps;
			}
		}
		assert(A==B);
		return steps;
	}
	// O(n^2) time, O(1) space
	int swapSeats2(vector<int> B, vector<int> A) {
		int steps=0, pos;
		for (int i=0; i<B.size(); ++i) {
			if (B[i]!=A[i]) {
				//steps+=B[i]? 2:1;
				if (B[i]!=0) {			// step-1: switch incorrect person to empty
					pos=std::distance(B.begin(),find(B.begin(), B.end(), 0));
					swap(B[i], B[pos]);
					++steps;
					//if (B==A) break;	// save step-2, but costs O(n)
				}
				if (A[i]==0) continue;		// save step-2
				pos=std::distance(B.begin(),find(B.begin(), B.end(), A[i]));
				swap(B[i], B[pos]);		// step-2: move correct one to here
				++steps;
			}
		}
		assert(A==B);
		return steps;
	}
	// two-end BFS
	int swapSeats1(vector<int>& B, vector<int>& A) {
		if (A==B) return 0;
		int dist=0;
		set<vector<int>> head, tail, *phead, *ptail;
		head.insert(B), tail.insert(A);
		while (!head.empty() && !tail.empty()) {
			if (head.size()<tail.size()) phead=&head,ptail=&tail;
			else phead=&tail,ptail=&head;
			set<vector<int>> tmp;
			for (auto it=phead->begin(); it!=phead->end(); ++it) {
				vector<int> C=*it;
				int empty = std::distance(C.begin(), find(C.begin(),C.end(), 0));
				for (int j=0; j<C.size(); ++j) {
					if (j!=empty) {
						swap(C[j],C[empty]);
						if (ptail->count(C))
							return dist+1;
						tmp.insert(C);
						swap(C[j],C[empty]);
					}
				}
			}
			swap(*phead,tmp);
			++dist;
		}
		return -1;
	}
	// BFS
	// in: initial seats state B, target seats state A, out: steps required
	// O(V+E) time, O(V) space: V for total vertices in terms of seats states
	int swapSeats(vector<int> B, vector<int> A) {
		int dist=0;
		queue<vector<int>> q;
		q.push(B);
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				vector<int> C=q.front(); q.pop();	// C for candidate vector state
				if (C==A)
					return dist;
				int empty = std::distance(C.begin(), find(C.begin(),C.end(), 0));
				for (int j=0; j<C.size(); ++j) {	// O(n) to enumarate all next states
					if (j!=empty) {
						swap(C[j],C[empty]);
						q.push(C);
						swap(C[j],C[empty]);
					}
				}
			}
			++dist;
		}
		return -1;
	}
};
int main(){
	Solution s;

	vector<int> c1{0,1};
	vector<int> c2{1,0};
	cout << s.swapSeats(c1, c1) << ' ' << s.swapSeats1(c1, c1) << ' ';
	cout << s.swapSeats2(c1, c1) << ' ' << s.swapSeats3(c1, c1) << endl;
	cout << s.swapSeats(c1, c2) << ' ' << s.swapSeats3(c1, c2) << ' ';
	cout << s.swapSeats2(c1, c2) << ' ' << s.swapSeats3(c1, c2) << endl;

	vector<int> c2b{0,1,2};
	vector<int> c2a{2,1,0};//1
	cout << s.swapSeats(c2b, c2a) << ' ' << s.swapSeats1(c2b, c2a) << ' ';
	cout << s.swapSeats2(c2b, c2a) << ' ' << s.swapSeats3(c2b, c2a) << endl;

	vector<int> c3b{0,1,2,3,4};
	vector<int> c3a{4,3,2,1,0};
	cout << s.swapSeats(c3b, c3a) << ' ' << s.swapSeats1(c3b, c3a) << ' ';
	cout << s.swapSeats2(c3b, c3a) << ' ' << s.swapSeats3(c3b, c3a) << endl;

	int n=4;
	vector<int> c4b(n),c4a;
	generate_n(begin(c4b), n, [](){static int i=0; return i++;});
	c4a=c4b;
	srand(time(0));
	int worse=0, res,res1,res2,res3;
	for (int i=0; i<10; ++i) {	// observation of random
		random_shuffle(c4a.begin(), c4a.end());
		res=s.swapSeats(c4b, c4a);
		res1=s.swapSeats1(c4b, c4a);
		res2=s.swapSeats2(c4b, c4a);
		res3=s.swapSeats3(c4b, c4a);
		worse=max(res,worse);
		cout << res << ':' << res1 << ':' << res2 << ':' << res3 << ' ';
		if (res!=res2) {
			cout << endl; for_each(c4a.begin(), c4a.end(), [](int n){cout<<n<<' ';});cout<<endl;
		}
	}
	cout << endl << "max: " << worse << endl;

}
