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
vector<int> arr;
vector<vector<int>> v;
void DFS(int node, int prev) {
	if (arr[node] != -1)
		return;

	arr[node] = prev;
	for (int &i : v[node]) {
		if (arr[i] == -1)
			DFS(i,node);
	}
}

int main() {
	int N;
	cin >> N;

	v = vector<vector<int>>(N + 1);
	for (int i = 0; i < N -1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	arr = vector<int>(N + 1,-1);

	DFS(1,0);

	for (int i = 2; i <= N; ++i)
		cout << arr[i] << "\n";
}  