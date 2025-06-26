#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, S;
vector<int> v;
vector<int> ans;
int cnt;
map<string, bool> mp;

void DFS(int sum, int idx, int depth) {
	if (sum == S && depth >=1) {
		string idx = "";
		for (int i = 0; i < ans.size(); ++i) {
			idx += (ans[i] + '0');
		}
		if (mp.find(idx) == mp.end()) {
			++cnt;
			mp[idx] = true;
		}
	}
	if (idx >= N)
		return;

	ans.push_back(idx);
	DFS(sum + v[idx], idx + 1,depth+1);
	ans.pop_back();
	DFS(sum, idx + 1,depth);
}

int main() {
	cin >> N >> S;

	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	DFS(0,0,0);

	cout << cnt << "\n";
}  