#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int K;
	cin >> K;
	
	int sz = s.size();
	vector<vector<int>> v(26, vector<int>(sz+1));
	for (int i = 0; i < sz; ++i) {
		v[s[i] - 'a'][i+1]++;
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 1; j <= sz; ++j) {
			v[i][j] += v[i][j - 1];
		}
	}
	for (int i = 0; i < K; ++i) {
		char c;
		int s, e;
		cin >> c >> s >> e;

		cout << v[c - 'a'][e+1] - v[c - 'a'][s] << "\n";
	}

}
