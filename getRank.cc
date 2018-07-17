#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	int indexOf(vector<int> nums, int x) {
		int mi, lo = 0, hi = nums.size()-1;
		while (lo <= hi) {
			mi = lo + (hi - lo)/2;
			if (nums[mi] < x) lo = mi+1;
			else if (nums[mi] > x) hi = mi-1;
			else return mi;
		}
		return -1;
	}
public:
	int getRankOfNumber(vector<int>& nums, int x) {
		int idx;
		std::sort(nums.begin(), nums.end());
		if (nums.size() == 0 || x == nums[0]) return 0;
		for (idx = 1; idx < nums.size(); idx++) {
			if (x < nums[idx]) {
				if (x != nums[idx-1])
					return idx;
				else
					return idx-1;
			}
		}
		return idx;
	}
};

int main() {
	vector<int> nums {5, 1, 4, 4, 5, 9, 7, 13, 3};
	//std::sort(nums.begin(), nums.end());
	Solution s;
	cout << "1: " << s.getRankOfNumber(nums, 1) << endl;	
	cout << "3: " << s.getRankOfNumber(nums, 3) << endl;	
	cout << "4: " << s.getRankOfNumber(nums, 4) << endl;
	cout << "5: " << s.getRankOfNumber(nums, 5) << endl;
	for (auto x: nums) cout << x << " ";
	cout << endl; 
}
