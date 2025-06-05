#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> mp;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		if (mp.find(s) == mp.end())
			mp[s] = 1;
		else{
			++mp[s];
		}
	}

	int mx = -1;
	string res = "";
	for (auto &it : mp) {
		if (it.second > mx) {
			mx = it.second;
			res = it.first;
		}
		else if (it.second == mx) {
			if (it.first < res)
				res = it.first;
		}
	}
	cout << res << "\n";

}
