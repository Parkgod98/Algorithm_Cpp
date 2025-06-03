#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	map<string, int> mp;
	for (int i = 0; i < N + M; ++i) {
		string s;
		cin >> s;
		mp[s]++;
	}

	int sum = 0;
	for (auto &it : mp) {
		if (it.second >= 2) {
			++sum;
		}
	}

	cout << sum << "\n";
	for (auto &it : mp) {
		if (it.second >= 2) {
			cout << it.first << "\n";
		}
	}
}