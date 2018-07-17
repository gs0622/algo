#include <iostream>
#include <unordered_map>
using namespace std;
class TwoSum {

	private:
		typedef pair<int, int> value_t;
		std::unordered_map<int, int> um;
	public:
		void add(int input) {
			int cnt = um.count(input);
			value_t v = {input, cnt+1};
			um.insert(v);
			std::cout << "add: " << input << ": "<< v.second << endl;
		}
		int find(int value) {
			std::cout << "find: " << value <<  endl;
			for (const auto& x: um) {
				auto y = um.find(value - x.first);
				if (y != um.end()) {
					if (y->first == x.first) {
						std::cout << "dup: count=" << x.second << ": " << y->second  << endl;
						y++;
						std::cout << "dup: count=" << x.second << ": " << y->second  << endl;
						//continue;
					}
					std::cout << x.first << ": "
						<< y->first << endl;
					//return 1;
				}
			}
			return 0;
		}
		void dump(void)
		{
			for (const auto& x: um)
				std::cout << x.first << ": " << um.count(x.first) << ": " << x.second << endl;
		}
};

int main(void)
{
	TwoSum t;
	t.add(-1);
	t.add(1);
	t.add(2);
	t.add(2);
	t.add(3);
	t.add(-2);
	t.dump();
	//t.find(0);
	//t.find(3);
	//t.find(4);
	return 0;
}
