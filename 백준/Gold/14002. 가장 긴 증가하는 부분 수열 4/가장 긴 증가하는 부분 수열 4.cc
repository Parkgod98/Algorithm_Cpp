#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v,dp;
vector<int> tracking;

void Print(int cur) {
	if (cur == -1)
		return;
	Print(tracking[cur]);
	cout << v[cur] << " ";
}
int main() {
	cin >> N;
	v = vector<int>(N);
	tracking = vector<int>(N,-1);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	dp = vector<int>(N, 1);

	int mx = 0;
	int mx_idx = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					tracking[i] = j;
				}
			}
			
		}
	}

	for (int i = 0; i < N; ++i) {
		if (mx < dp[i]) {
			mx = dp[i];
			mx_idx = i;
		}
	}

	cout << mx << "\n";
	Print(mx_idx);
	cout << "\n";
}