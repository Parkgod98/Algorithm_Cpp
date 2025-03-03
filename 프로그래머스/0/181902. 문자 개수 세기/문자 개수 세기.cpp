#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
	
	vector<int> ans(52, 0);

	for (char& c : my_string) {
		if (c >= 'A' && c <= 'Z')
			ans[c - 'A']++;
		else if (c >= 'a' && c <= 'z')
			ans[c - 'a' + 26]++;
	}
	
	return ans;
}