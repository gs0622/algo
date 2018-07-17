#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n>0) && (n & (n-1))==0;
	}
	bool isPowerOfTwo2(int n) {
		return (n>0) && (__builtin_popcount(n)==1);
	}
	bool isPowerOfTwo1(int n) {
		if (n<=0) return false;
		while (n!=1) {
			if (n%2==1) return false;
			n/=2;
		}
		return true;
	}
};
int main(){
	Solution s;
	cout << s.isPowerOfTwo(4) << endl;	// true
	cout << s.isPowerOfTwo(7) << endl;	// false
	cout << s.isPowerOfTwo(0) << endl;	// false
	cout << s.isPowerOfTwo(-2) << endl;	// false
}
