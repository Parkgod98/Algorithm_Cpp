#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N;
vector<int> v,ans;
vector<int> visited;
void DFS(int cur, int start) {
	if (visited[cur] && cur == start) {
		ans.push_back(cur);
		return;
	}
	if (visited[cur])
		return;

	visited[cur] = 1;
	DFS(v[cur], start);
	visited[cur] = 0;
}

int main() {
	cin >> N;
	v = visited = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	for (int i = 1; i <= N; ++i) {
		DFS(i, i);
	}

	cout << ans.size() << "\n";
	for (int &n : ans)
		cout << n << "\n";
}