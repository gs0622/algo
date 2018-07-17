#include <bits/stdc++.h>
using namespace std;
class Solution {
	unordered_map<string,string> m;
public:
	// 62^digit, e.g. 62^6=56,800,235,584
	string myhash(string s, int digit) {
		const string ss{"1234567890abcdefghijklmnopqrstuvwzyzABCDEDGHIJKLMNOPQRSTUVWXYZ"};
		hash<string> h;
		size_t d = h(s);
		string key;
		while (digit--)
			key += ss[d%62], d/=62;
		m[key] = s;
		return key;
	}
	string myvalue(string key) {
		return m[key];
	}
};
int main(){
	Solution so;
	string s;
	while (cin >> s) {
		string key = so.myhash(s, 7);
		cout << "key: " << key << endl;
		cout << "val: " << so.myvalue(key) << endl;
	}
}
