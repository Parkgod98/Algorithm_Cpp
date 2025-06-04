#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N, P;
vector<int> a, b;
int mx = -1;
void DFS(int idx, char prev, int value) {
	if (idx == N) {
		mx = max(mx, value);
		return;
	}
	if (prev == 'a') {
		DFS(idx + 1, 'a', value + a[idx] -P);
		DFS(idx + 1, 'b', value + b[idx]);
	}
	else if (prev == 'b') {
		DFS(idx + 1, 'a', value + a[idx]);
		DFS(idx + 1, 'b', value + b[idx] - P);
	}
	else {
		DFS(idx + 1, 'a', value + a[idx]);
		DFS(idx + 1, 'b', value + b[idx]);
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> P;

		a = vector<int>(N);
		for (int i = 0; i < N; ++i)
			cin >> a[i];

		b = vector<int>(N);
		for (int i = 0; i < N; ++i)
			cin >> b[i];

		mx = -1;
		DFS(0,' ',0);
		cout << "#" << tc << " " << mx << "\n";
	}
}
