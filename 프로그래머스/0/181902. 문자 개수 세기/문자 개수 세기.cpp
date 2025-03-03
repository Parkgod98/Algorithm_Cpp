#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string my_string) {
	map<char, int> mp;
	vector<int> ans;
	for (char& c : my_string) {
		mp[c]++;
	}
	for (char c = 'A'; c <= 'Z'; ++c) {
		if (mp[c])
			ans.push_back(mp[c]);
		else
			ans.push_back(0);
	}
	for (char c = 'a'; c <= 'z'; ++c) {
		if (mp[c])
			ans.push_back(mp[c]);
		else
			ans.push_back(0);
	}
	return ans;
}