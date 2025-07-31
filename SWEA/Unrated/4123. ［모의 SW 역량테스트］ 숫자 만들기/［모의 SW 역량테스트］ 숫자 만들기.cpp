#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<int> num;
vector<char> op;
int mx = -111111111;
int mn = 111111111;

void DFS(int sum, int idx) {
	if (idx == N - 1) {
		mx = max(mx, sum);
		mn = min(mn, sum);
		return;
	}

	if (op[idx] == '+') {
		DFS(sum + num[idx + 1], idx + 1);
	}
	else if (op[idx] == '-') {
		DFS(sum - num[idx + 1], idx + 1);
	}
	else if (op[idx] == '/') {
		DFS(sum / num[idx + 1], idx + 1);
	}
	else {
		DFS(sum * num[idx + 1], idx + 1);
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		num = vector<int>(N);
		op.clear();
		for (int i = 0; i < 4; ++i) {
			int n;
			cin >> n;
			for (int j = 0; j < n; ++j) {
				if (i == 0)
					op.push_back('+');
				else if (i == 1)
					op.push_back('-');
				else if (i == 2)
					op.push_back('*');
				else
					op.push_back('/');
			}
		}
		for (int i = 0; i < N; ++i) 
			cin >> num[i];

		sort(op.begin(), op.end());
		do {
			DFS(num[0], 0);
		} while (next_permutation(op.begin(), op.end()));
		cout << "#" << tc << " " << mx - mn << "\n";
		mx = -111111111;
		mn = 111111111;
	}
}