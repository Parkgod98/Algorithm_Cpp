#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;
map<string, int> mp;

bool compare(string &a, string &b) {

	if (mp[a] != mp[b]) {
		return mp[a] > mp[b];
	}
	else {
		if (a.size() != b.size()) {
			return a.size() > b.size();
		}
		else {
			return a < b;
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;

	vector<string> v;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (s.size() < M)
			continue;
		if (mp.find(s) != mp.end() && s.size() >= M) {
			mp[s]++;
		}
		if (mp.find(s) == mp.end()){
			mp[s] = 1;
			v.push_back(s);
		}
		else {
			mp[s]++;
		}
	}

	sort(v.begin(), v.end(), compare);
	
	for (string &s : v)
		cout << s << "\n";
}  