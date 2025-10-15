#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N;
vector<int> v;
map<int, bool> mp;
map<int, int> mpc;
int main() {
	cin >> N;
	v = vector<int>(N);
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		mpc[v[i]]++;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int sum = v[i] + v[j];
			if (mpc.find(sum) != mpc.end()) {
				if (v[i] == sum && v[j] == sum && mpc[sum] == 2)
					continue;
				else if (v[i] == sum || v[j] == sum) {
					if (mpc[sum] >= 2)
						mp[sum] = 1;
				}
				else {
					mp[sum] = 1;
				}
			}
			
		}
	}

	for (int i = 0; i < N; ++i)
		if (mp.find(v[i]) != mp.end())
			++cnt;

	cout << cnt << "\n";
}
