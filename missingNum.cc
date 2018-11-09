/*
Given an array with n elements randomly chosen from 1 to n+1, find the missing one of 1 to n+1
Given an array with n elements randomly chosen from 1 to n+2, find the missing two of 1 to n+2
*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	// O(n) time and space, pigeon hole
	vector<int> missingTwoNum(vector<int>& A) {
		int n = A.size();
		vector<int> B(n+2, 0);
		for (auto a: A)			// for every pigeon a at array A
			B[a-1]=a;		// put a into hole B[a-1]

		vector<int> res;
		for (int i=0; i<n+2; ++i)
			if (B[i]==0)
				res.push_back(i+1);
		return res;
	}
	// O(n) time and space, pigeon hole
	int missingOneNum(vector<int>& A) {
		int n = A.size();
		vector<int> B(n+1, 0);
		for (auto a: A)			// for every pigeon a at array A
			B[a-1]=a;		// put a into hole B[a-1]

		for (int i=0; i<n+1; ++i)
			if (B[i]==0)
				return i+1;
		return 0;
	}
	// O(n) time and space
	int missingOneNum0(vector<int>& A) {
		unordered_set<int> st;
		for (auto n: A)
			st.insert(n);
		for (int i=1; i<=A.size()+1; ++i)	// be careful <= (off-by-one error)
			if (st.count(i)==0)		// search for the missing one
				return i;
		return 0;				// discuss this case
	}
};
int main(){
	Solution s;
	vector<int> A1{4,3,2,1};
	cout << s.missingOneNum(A1) << endl;
	vector<int> A2{2,3,4,5};
	cout << s.missingOneNum(A2) << endl;
	vector<int> A3{1,2};
	cout << s.missingOneNum(A3) << endl;

	vector<int> res;
	vector<int> A4{5,4,3,2};
	res = s.missingTwoNum(A4);
	cout << res[0] << " " << res[1] << endl;
	vector<int> A5{1,2};
	res = s.missingTwoNum(A5);
	cout << res[0] << " " << res[1] << endl;
}
