#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<int> v;
int cnt;
int N, K;
void DFS(int idx, int sum) {
	if (sum == K) {
		++cnt;
		return;
	}
	if (idx == N)
		return;
	DFS(idx + 1, sum + v[idx]);
	DFS(idx + 1, sum);
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> K;

		v = vector<int>(N);
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		DFS(0,0);
		
		cout << "#" << tc << " " << cnt << "\n";
		cnt = 0;
	}
}