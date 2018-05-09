#include <bits/stdc++.h>
using namespace std;
class Solution {
	bool isSorted(vector<int>& nums, int lo, int hi) {
		for (int i=lo+1; i<=hi; ++i)
			if (nums[i]<nums[i-1]) return false;
		return true;
	}
	bool isSorted(vector<int>& nums) {
		for (int i=1; i<nums.size(); ++i)
			if (nums[i]<nums[i-1]) return false;
		return true;
	}
	int partition(vector<int>& nums, int lo, int hi) {
		auto it = std::partition(begin(nums)+lo, begin(nums)+hi, [&](int n){ return n<nums[hi]; });
		int j = distance(begin(nums), it);
		swap(nums[hi], nums[j]);
		return j;
	}
public:
	int select(vector<int>& nums, int k) {
		int lo=0, hi=nums.size()-1;
		assert(k>=0 && k<nums.size());
		while (lo <= hi) {
			//auto j = distance(begin(nums),
			//	std::partition(begin(nums)+lo, begin(nums)+hi, [&](int n){
			//		return n<nums[hi];
			//	}));
			//swap(nums[hi], nums[j]);
			int j = partition(nums, lo, hi);

			if (j<k) lo=j+1;
			else if (j>k) hi=j-1;
			else return nums[j];
		}
		throw runtime_error("error");
		return -1;
	}

	void sort(vector<int>& nums, int lo, int hi) { // not include hi, use hi as pivot
		if (hi<=lo) return;

		// partition
		//auto j = distance(begin(nums),
		//		std::partition(begin(nums)+lo, begin(nums)+hi,
		//			[&](int n){return n<nums[hi]; }));
		//swap(nums[hi], nums[j]);
		int j = partition(nums, lo, hi);

		// divide
		sort(nums, lo, j-1);
		sort(nums, j+1, hi);

		assert(isSorted(nums, lo, hi));
	}
};
int main(){
	Solution s;
	vector<int> nums(10);
	srand(time(0));
	generate_n(begin(nums), 10, [](){ return rand()%100; });
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << endl;

	s.sort(nums, 0, distance(begin(nums), end(nums)));
	copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
	cout << endl;
	assert(is_sorted(begin(nums), end(nums)));

	random_shuffle(begin(nums), end(nums));
	cout << s.select(nums, 0) << endl;
	cout << s.select(nums, 5) << endl;
}
