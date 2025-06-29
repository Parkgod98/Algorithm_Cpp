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
int cnt;

void DFS(int sum, int idx) {
	if (idx == N) {
		if (sum == S) {
			++cnt;
		}
	}
	if (idx >= N)
		return;

	DFS(sum + v[idx], idx + 1);
	DFS(sum, idx + 1);
}

int main() {
	cin >> N >> S;

	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	DFS(0, 0);
	
	if (S == 0)
		cnt--;
	cout << cnt << "\n";
}