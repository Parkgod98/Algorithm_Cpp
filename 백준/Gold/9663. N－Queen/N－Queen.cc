#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int cnt = 0;
vector<int> v;
void DFS(int cur) {
	if (cur == N + 1) {
		++cnt;
		return;
	}
	for (int i = 1; i <= N; ++i) {
		bool Can = true;
		for (int j = 1; j < cur; ++j) {
			if ((v[j] == i) || (abs(cur - j) == abs(i - v[j]))) {
				Can = false;
			}
		}
		if (Can) {
			v[cur] = i;
			DFS(cur + 1);
			v[cur] = 0;
		}
	}
}
int main() {
	cin >> N;

	v = vector<int>(N+1);

	DFS(1);

	cout << cnt << "\n";
}