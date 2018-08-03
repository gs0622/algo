#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int distance(vector<int>& A, vector<int>& B) {
		int res=0;
		for (int i=0; i<A.size(); ++i) if (A[i]!=B[i]) ++res;
		string AA, BB;
		for (int i=0; i<A.size(); ++i)
			AA+=A[i]+'0', BB+=B[i]+'0';
		return res;
	}
	int distance(string& A, string& B) {
		int res=0;
		for (int i=0; i<A.size(); ++i) if (A[i]!=B[i]) ++res;
		string AA, BB;
		for (int i=0; i<A.size(); ++i)
			AA+=A[i]+'0', BB+=B[i]+'0';
		return res;
	}
	int swapSeats6(vector<int>& B, vector<int>& A) {
		vector<int> C=B;	// backup, O(n) copy
		int cnt=0, empty=std::distance(B.begin(),find(B.begin(), B.end(), 0));			// locate empty slot
		unordered_map<int,int> mp;
		for (int i=0; i<B.size(); ++i)
			mp[B[i]]=i;
		for (int i=0; i<B.size(); ++i) {
			if (B[i]!=A[i]) {
				if (i!=mp[0]) {
					int tmp=B[i];
					swap(B[i], B[empty]);
					mp[tmp]=empty;
					empty=i,mp[0]=i;
					cnt+=1;
				}
				swap(B[mp[A[i]]],B[i]);
				empty=mp[A[i]];
				mp[A[i]]=i,mp[0]=empty;
				cnt+=1;
			}
		}
		assert(A==B);
		B=C;			// restore, O(n) copy
		return cnt;
	}
	// buggy
	int swapSeats5(vector<int>& B, vector<int>& A) {
		if (B==A) return 0;					// O(n)
		unordered_map<int,int> mp;
		vector<int> stk;
		for (int i=0; i<B.size(); ++i) mp[B[i]]=i;
		int cnt=0, rev=0;
		for (int i=0; i<B.size(); ++i) {
			if (A[i]!=0 && B[i]!=A[i]) ++cnt;		// exclude 0, count how many ppl are not in final index
			if (A[i]) stk.push_back(mp[A[i]]);
		}
		function<bool(vector<int>&)> isSorted=[](vector<int>& nums) {
			for (int i=1; i<nums.size(); ++i)
				if (nums[i]<nums[i-1]) return false;
			return true; 
		};
		rev=!isSorted(stk);
		return rev? cnt+1: cnt;
	}
	// two-end BFS
	int swapSeats4(vector<int>& B, vector<int>& A) {
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
	int swapSeats3(vector<int>& B, vector<int>& A) {
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
	// DFS backtracking
	int swapSeats2(vector<int>& B, vector<int>& A) {
		string AA, BB;
		for (int i=0; i<A.size(); ++i)
			AA+=A[i]+'0', BB+=B[i]+'0';
		stack<pair<string,int>> stk;
		stk.push({BB,0});
		unordered_set<string> visit;				// hashset of visited state
		while (!stk.empty()) {
			auto top=stk.top(); stk.pop();
			string CC=top.first;
			int steps=top.second;
			visit.insert(CC);
			if (CC==AA) return steps; 
			int dist=distance(AA,CC);
			int empty=CC.find('0');
			for (int i=0; i<CC.size(); ++i) {
				if (i!=empty) {
					swap(CC[i], CC[empty]);
					int dd=distance(AA,CC);
					if (dd<=dist && visit.count(CC)==0)
						stk.push({CC, steps+1});
					swap(CC[i], CC[empty]);
				}
			}
		}
		return -1;
	}
	// BFS, wrong?
	int swapSeats1(vector<int>& B, vector<int>& A) {
		string AA, BB;
		for (int i=0; i<A.size(); ++i)
			AA+=A[i]+'0', BB+=B[i]+'0';
		queue<string> q;
		q.push(BB);
		int res=0;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				auto CC=q.front(); q.pop();
				if (CC==AA) return res;
				int d=distance(AA,CC);
				int empty=CC.find('0');
				for (int j=0; j<CC.size(); ++j) {	// enumerate all the nearest neighboring states
					if (j!=empty) {
						swap(CC[j], CC[empty]);
						int dd=distance(AA,CC);
						if (dd<=d) q.push(CC);
						swap(CC[j], CC[empty]);
					}
				}
			}
			++res;
		}
		return -1;

	}
	// in: initial seats state B, target seats state A, out: steps required
	// O(V+E) time, O(V) space: V for total vertices in terms of seats states
	int swapSeats(vector<int>& B, vector<int>& A) {
		string AA, BB;
		for (int i=0; i<A.size(); ++i)
			AA+=A[i]+'0', BB+=B[i]+'0';
		queue<string> q;
		unordered_set<string> visit;				// hashset of visited state
		q.push(BB);						// initial state
		int res=0;
		while (!q.empty()) {
			int n=q.size();
			for (int i=0; i<n; ++i) {
				string CC=q.front(); q.pop();
				if (CC==AA)                             // match target, return require steps
					return res;
				visit.insert(CC);			// this state is visited
				int empty=CC.find('0');			// locate empty seat
				for (int j=0; j<CC.size(); ++j) {	// enumerate all the nearest neighboring states
					if (j!=empty) {
						swap(CC[j], CC[empty]);
						if (visit.count(CC)==0)	// skip visited states
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
/*
	cout << s.swapSeats4(before, after1) << ' ' << s.swapSeats5(before, after1) << endl;
	cout << s.swapSeats4(before, after2) << ' ' << s.swapSeats5(before, after2) << endl;
	cout << s.swapSeats4(before, after3) << ' ' << s.swapSeats5(before, after3) << endl;
	cout << s.swapSeats4(before, after4) << ' ' << s.swapSeats5(before, after4) << endl;

	vector<int> c1{0,1};
	vector<int> c2{1,0};
	cout << s.swapSeats4(c1, c1) << ' ' << s.swapSeats5(c1, c1) << endl;
	cout << s.swapSeats4(c1, c2) << ' ' << s.swapSeats5(c1, c2) << endl;
*/
	vector<int> c3b{0,1,2,3};
	vector<int> c3a1{1,2,3,0};//3 3
	vector<int> c3a2{3,2,1,0};//4 4
	vector<int> c3a3{1,0,2,3};//1 1
	vector<int> c3a4{1,0,3,2};//4 3
	vector<int> c3a5{0,1,3,2};//3 2
	vector<int> c3a6{0,2,3,1};//4 3
	cout << s.swapSeats4(c3b, c3a1) << ' ' << s.swapSeats6(c3b, c3a1) << endl;
	cout << s.swapSeats4(c3b, c3a2) << ' ' << s.swapSeats6(c3b, c3a2) << endl;
	cout << s.swapSeats4(c3b, c3a3) << ' ' << s.swapSeats6(c3b, c3a3) << endl;
	cout << s.swapSeats4(c3b, c3a4) << ' ' << s.swapSeats6(c3b, c3a4) << endl;
	cout << s.swapSeats4(c3b, c3a5) << ' ' << s.swapSeats6(c3b, c3a5) << endl;
	cout << s.swapSeats4(c3b, c3a6) << ' ' << s.swapSeats6(c3b, c3a6) << endl;

	vector<int> c4b{0,1,2};
	vector<int> c4a{2,1,0};
	cout << s.swapSeats4(c4b, c4a) << ' ' << s.swapSeats5(c4b, c4a) << endl;

	vector<int> c5b{0,1,2,3,4};
	vector<int> c5a{4,3,2,1,0};
	cout << s.swapSeats(c5b, c5a) << ' ' << s.swapSeats5(c5b, c5a) << endl;

	srand(time(0));
	int worse=0, res, res1;
	for (int i=0; i<10; ++i) {	// observation of random
		random_shuffle(c5a.begin(), c5a.end());
		res=s.swapSeats4(c5b, c5a);
		res1=s.swapSeats6(c5b, c5a);
		if (res!=res1) {
			cout << endl;
			for (auto n: c5a) cout << n <<  ' ';
			cout << endl;
		}
		worse=max(res,worse);
		cout << res << ":" << res1 << ' ';
	}
	cout << endl << "max: " << worse << endl;

}
