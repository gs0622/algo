/*
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> nums{1,1,1,2,2,2,2,3,3,3};
	for (auto n: nums) cout << n << " ";
	cout << endl;
	for (int i=0; i<10; ++i) {
		srand(time(0));
		random_shuffle(nums.begin(), nums.end());
		for (auto n: nums) cout << n << " ";
		cout << endl;
	}
}
