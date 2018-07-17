#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void _reverse(string& s, int i, int j)
{
	while (i < j) {
		// XOR swap
		s[i] ^= s[j], s[j] ^= s[i], s[i] ^= s[j];
		i += 1, j -= 1;
	}
}
/* O(n) time, in-place */
string& reverse(string& s)
{
	int i, j;
	int sz = s.size();
	_reverse(s, 0, sz-1);
	for (i = 0; i < sz; i += 1) {
		if (!isalpha(s[i])) // trim leading non-alpha
			i += 1;
		for (j = i; j < sz; j += 1) {
			if (!isalpha(s[j]))
				break;
		}
		_reverse(s, i, j-1);
		i = j;
	}	
	return s;
}

int main(void)
{
	std::string s0 ("the sky is blue");
	std::string s1 ("  the sky is blue");
	std::string s2 ("the sky is blue  ");
	std::string s3 ("the sky is    blue");
	std::cout << reverse(s0) << endl; 
	std::cout << reverse(s1) << endl; 
	std::cout << reverse(s2) << endl; 
	std::cout << reverse(s3) << endl; 
	return 0;
}
