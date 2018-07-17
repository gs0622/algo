#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int search3(vector<int>& nums, int target) {
	}
	int search2(vector<int>& nums, int target) {
		int lo=0, hi=nums.size()-1;
		while (lo<hi) {
			int mi=lo+(hi-lo)/2;
			if (nums[mi]<target) lo=mi+1;
			else if (nums[mi]>target) hi=mi;
			else return mi;
		} // lo==hi
		return nums[lo]==target? lo: -1;
	}
	int search1(vector<int>& nums, int target) {
		int lo=0, hi=nums.size()-1;
		while (lo<=hi) {
			int mi=lo+(hi-lo)/2;
			if (nums[mi]<target) lo=mi+1;
			else if (nums[mi]>target) hi=mi-1;
			else return mi;
		}; // lo>hi
		return -1;
	}
};
int main(){
	vector<int> nums(10);
	srand(time(0));
	//generate_n(begin(nums), 10, std::rand);
	//for (auto& n: nums) n %= 11;
	//std::sort(begin(nums), end(nums));
	generate_n(begin(nums), 10, [](){static int i=0; return ++i;});
	//std::random_shuffle(begin(nums), end(nums));
	std::copy(begin(nums), end(nums), std::ostream_iterator<int>(cout, " "));
	cout << endl;
	Solution s;
	cout << s.search1(nums, 10) << endl;
	cout << s.search2(nums, 10) << endl;
}
