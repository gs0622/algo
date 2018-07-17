#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	std::priority_queue<int, std::vector<int>, std::less<int> > maxheap;	// smaller half
	std::priority_queue<int, std::vector<int>, std::greater<int> > minheap;	// greater half
	void insert(int v)
	{
		//cout << "insert: " << v << endl;
		if (0 == maxheap.size())
			maxheap.push(v);
		else if (v < maxheap.top())
			maxheap.push(v);
		else
			minheap.push(v);
		int diff = maxheap.size() - minheap.size();
		
		if (diff > 1) {
			minheap.push(maxheap.top());
			maxheap.pop();
		} else if (diff < -1) {
			maxheap.push(minheap.top());
			maxheap.pop();
		}
	}
	double median(void)
	{
		double median;
		int sz1 = minheap.size(), sz2 =  maxheap.size();
		int sum = sz1 + sz2;
		cout << sz1 << ":" << sz2 << endl;
		if (0 == (sum % 2)) median = (minheap.top() + maxheap.top()) / 2;
		else {
			if (sz1 > sz2) median = minheap.top();
			else median = maxheap.top();
		}
		return median;
	}

};

int main(void)
{
	Solution a;
	a.insert(8);
	a.insert(7);
	a.insert(6);
	a.insert(5);
	a.insert(4);
	a.insert(3);
	a.insert(2);
	cout << a.median() << endl;
	a.insert(1);
	cout << a.median() << endl;
}

