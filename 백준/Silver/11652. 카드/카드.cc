#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<long long, int> mp;
	for (int i = 0; i < N; ++i) {
		long long s;
		cin >> s;

		if (mp.find(s) != mp.end())
			mp[s]++;
		else
			mp[s] = 1;
	}

	long long res;
	int mx = -1;
	for (auto &it : mp) {
		if (it.second > mx) {
			mx = it.second;
			res = it.first;
		}
		else if (it.second == mx) {
			if (it.first < res) {
				res = it.first;
			}
		}
	}
	cout << res << "\n";
}