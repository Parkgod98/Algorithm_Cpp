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
int N, M;
vector<int> v;
int cur = 0;
int ans[8] = { 0 };

void DFS(int depth,int idx) {
	if (depth == M) {
		for (int i = 0; i < M; ++i)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = -1;
	for (int i = idx; i < N; ++i) {
		if (tmp != v[i]) {
			ans[cur] = v[i];
			tmp = v[i];
			cur++;
			DFS(depth + 1, i + 1);
			cur--;
		}
	}
}

int main() {
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	DFS(0,0);
}