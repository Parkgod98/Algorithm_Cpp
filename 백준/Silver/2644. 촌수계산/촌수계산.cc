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
int n;
vector<vector<int>> v;
int s, e;
vector<int> visited;
int relation;
bool Find = false;

void DFS(int cur, int e, int depth) {
	if (visited[cur])
		return;
	if (cur == e) {
		cout << depth << "\n";
		Find = true;
		return;
	}

	visited[cur] = 1;
	for (int &i : v[cur]) {
		if (!visited[i]) {
			DFS(i, e, depth + 1);
		}
	}


}
int main() {
	cin >> n;

	v = vector<vector<int>>(n + 1);
	cin >> s >> e;
	cin >> relation;

	visited = vector<int>(n + 1);
	for (int i = 0; i < relation; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(s, e, 0);
	if (!Find)
		cout << -1 << "\n";
}  