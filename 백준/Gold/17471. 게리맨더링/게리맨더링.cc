#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;
int N;
#define INF 99999999
vector<int> num;
vector<vector<int>> v;
vector<bool> selected;
int mn = INF;

bool Connected() {
	queue<int> q1, q2;
	vector<bool> visited1(N + 1,false), visited2(N + 1,false);
	for (int i = 1; i <= N; ++i) {
		if (selected[i] && q1.size() == 0) {
			q1.push(i);
			visited1[i] = 1;
		}
		if (!selected[i] && q2.size() == 0) {
			q2.push(i);
			visited2[i] = 1;
		}
	}

	while (!q1.empty()) {
		int n = q1.front();
		q1.pop();

		for (int &node : v[n]) {
			if (!visited1[node] && selected[node]) {
				visited1[node] = 1;
				q1.push(node);
			}
		}
	}
	while (!q2.empty()) {
		int n = q2.front();
		q2.pop();

		for (int &node : v[n]) {
			if (!visited2[node] && !selected[node]) {
				visited2[node] = 1;
				q2.push(node);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (visited1[i] != selected[i])
			return false;
	}
	for (int i = 1; i <= N; ++i) {
		if (visited2[i] != !selected[i])
			return false;
	}
	return true;
}

int Calculate() {
	int sum1, sum2;
	sum1 = sum2 = 0;

	for (int i = 1; i <= N; ++i) {
		if (selected[i])
			sum1 += num[i];
		else
			sum2 += num[i];
	}

	return abs(sum1 - sum2);
}
void Comb(int k, int depth, int idx) {
	if (depth == k) {
		if (Connected()) {
			mn = min(Calculate(),mn);
			return;
		}
		return;
	}

	for (int i = idx; i <= N; ++i) {
		selected[i] = true;
		Comb(k, depth + 1, i + 1);
		selected[i] = false;
	}
}

int main() {
	cin >> N;
	num = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> num[i];

	v = vector<vector<int>>(N + 1);
	selected = vector<bool>(N + 1,false);
	for (int i = 1; i <= N; ++i) {
		int n;
		cin >> n;

		for (int j = 0; j < n; ++j) {
			int k;
			cin >> k;
			v[i].push_back(k);
		}
	}

	for (int i = 1; i < N; ++i) {
		Comb(i, 0, 1);
	}
	if (mn == INF)
		cout << -1 << "\n";
	else
		cout << mn << "\n";
}
