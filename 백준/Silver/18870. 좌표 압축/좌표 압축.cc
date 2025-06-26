#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N), v2(N);
	map<int, int> mp;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		v2[i] = v[i];
	}
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());

	for (int i = 0; i < v2.size(); ++i)
		mp[v2[i]] = i;

	for (int i = 0; i < N; ++i) {
		cout << mp[v[i]] << " ";
	}
}  