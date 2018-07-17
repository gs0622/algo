#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPalidrome(string s) {
		for (int i=0, j=s.size()-1; i<j; ++i, --j)
			if (s[i]!=s[j]) return false;
		return true;
	}
};
int main(){
	Solution so;
	string s;
	while (cin >> s)
		cout << so.isPalidrome(s) << endl;
}
