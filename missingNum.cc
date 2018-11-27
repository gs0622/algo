/*
Given an array with n elements randomly chosen from 1 to n+1, find the missing one of 1 to n+1
Given an array with n elements randomly chosen from 1 to n+2, find the missing two of 1 to n+2
*/
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> missingTwoNum4(vector<int> A) {
		// let say missing two are x and y, (A[0]^A[1]...A[n-1]) ^ (1^2...^n+2) = x^y
		int n=A.size(), xOR=0;
		for (auto i: A)			xOR^=i;
		for (auto i=1; i<=n+2; ++i)	xOR^=i;

		int x=0, y=0, lsb=xOR & -xOR;
		for (auto i: A)
			if (lsb & i) x^=i;	// group to x
			else y^=i;
		for (auto i=1; i<=n+2; ++i)
			if (lsb & i) x^=i;	// pair is cancelled
			else y^=i;

		if (x > y) x^=y, y^=x, x^=y;	// xor swap as simple sort

		return {x, y};
	}
	// wrong, TBD
	vector<int> missingTwoNum3(vector<int> A) {
		int n=A.size();
		int sum1=(1+n+1)*(n+1)/2;                       // Q to intervier: will this overflow?
		int sum2=(1+n+2)*(n+2)/2;
		int sum3 = accumulate(A.begin(), A.end(), 0);   // equal to A[0]+A[1]+...+A[n-1]
		vector<int> res(2);
		res[0] = sum1-sum3;                             // 1 to n+1 must at least contain one missing
		res[1] = sum2-(sum3+res[0]);
		return res;
	}
	// O(n) time and space by unordered hashset
	vector<int> missingTwoNum2(vector<int> A) {
		vector<int> res;
		unordered_set<int> st(A.begin(), A.end());	// O(n) time and space
		int n=A.size();
		for (auto i=1; i<=n+2; ++i)			// O(n) time count whether the i is in the set
			if (st.count(i)==0)
				res.push_back(i);
		return res;
	}
	vector<int> missingTwoNum1(vector<int> A) { // trick: use copy as input
		int n = A.size();
		A.resize(n+2, 0);
		for (int i=0; i<n+2; ++i) {
			while (A[i]>0 && A[i]!=i+1) {
				A[i]*=-1;
				swap(A[i], A[-A[i]-1]);
			}
		}
		vector<int> res;
		for (int i=0; i<n+2; ++i)
			if (A[i]==0)
				res.push_back(i+1);
		return res;
	}
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
	// O(n) time O(1) space by sum
	int missingOneNum4(vector<int>& A) {
		int a=0, b=0, n=A.size();
		for (int i: A) a+=i;
		for (int i=1; i<=n+1; ++i) b+=i;
		return b-a;
	}
	// O(n) time O(1) space by XOR
	int missingOneNum3(vector<int>& A) {
		int a=0, b=0, n=A.size();
		for (int i: A) a^=i;
		for (int i=1; i<=n+1; ++i) b^=i;
		return a^b;
	}
	// O(n) time and space, pigeon hole
	// O(n) time, O(1) space, pigeon hole, negate as visit, while to deal w/ current position
	// TODO: how to prove O(n) time?
	int missingOneNum2(vector<int>& A) {
		int n = A.size();
		A.push_back(0);
		for (int i=0; i<n+1; ++i) {
			while (A[i]>0 && A[i]!=i+1) {	// trick: think why while works
				A[i]*=-1;		// mark as visited
				swap(A[i], A[(-A[i])-1]);
			}
		}
		for (int i=0; i<n+1; ++i)
			if (A[i]==0)
				return i+1;
		return 0;
	}
	// O(n) time and space, pigeon hole
	int missingOneNum1(vector<int>& A) {
		int n = A.size();
		vector<int> B(n+1, 0);
		for (auto a: A)			// for every pigeon a at array A
			B[a-1]=a;		// put a into hole B[a-1]

		for (int i=0; i<n+1; ++i)
			if (B[i]==0)
				return i+1;
		return 0;
	}
	// O(n) time and space, naive
	int missingOneNum(vector<int>& A) {
		unordered_set<int> st;
		for (auto n: A)
			st.insert(n);
		for (int i=1; i<=(int)A.size()+1; ++i)	// be careful <= (off-by-one error)
			if (st.count(i)==0)		// search for the missing one
				return i;
		return 0;				// discuss this case
	}
};
int main(){
	Solution s;
	vector<int> A1{4,3,2,1};
	cout << s.missingOneNum(A1) << ": " << s.missingOneNum4(A1) << endl;
	vector<int> A2{2,3,4,5};
	cout << s.missingOneNum(A2) << ": " << s.missingOneNum4(A2) << endl;
	vector<int> A3{1,2};
	cout << s.missingOneNum(A3) << ": " << s.missingOneNum4(A3) << endl;

	vector<int> res;
	vector<int> A4{1,2,3,6};	// 1 to 6
	res = s.missingTwoNum(A4);
	cout << res[0] << " " << res[1] << ": ";
	res = s.missingTwoNum4(A4);
	cout << res[0] << " " << res[1] << endl;

	vector<int> A5{1,2};		// 1 to 4
	res = s.missingTwoNum(A5);
	cout << res[0] << " " << res[1] << ": ";
	res = s.missingTwoNum4(A5);
	cout << res[0] << " " << res[1] << endl;
}
