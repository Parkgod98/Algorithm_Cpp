#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<int, bool> mp;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mp[n] = true;
	}

	for (auto it = mp.begin(); it != mp.end(); ++it) {
		cout << it->first << " ";
	}
}