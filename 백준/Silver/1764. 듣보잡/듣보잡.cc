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
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		mp[s] = 1;
	}

	map<string, bool> mp2;
	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		if (mp[s] == 1) {
			mp2[s] = true;
		}
	}

	cout << mp2.size() << "\n";
	for (auto &it : mp2) {
		cout << it.first << "\n";
	}
}