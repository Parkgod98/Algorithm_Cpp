#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
map<int, int> mp;

int main(){
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> v(2*N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	for (int i = N; i < 2*N; ++i)
		v[i] = v[i - N];

	int start = 0;
	int end = k - 1;
	for (int i = start; i <= end; ++i) {
		mp[v[i]]++;
	}

	int mx = mp.size();
	if (mp.find(c) == mp.end()) {
		mx = max(mx, mx + 1);
	}
	while (end < 2*N-1) {
		if (mp[v[start]] == 1) {
			mp.erase(v[start]);
		}
		else {
			mp[v[start]]--;
		}
		start++;
		end++;
		mp[v[end]]++;
		int sz = mp.size();
		mx = max(mx, sz);
		if (mp.find(c) == mp.end()) {
			mx = max(mx, sz + 1);
		}
	}

	cout << mx << "\n";
}