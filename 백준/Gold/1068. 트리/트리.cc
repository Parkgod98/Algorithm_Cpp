#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
using namespace std;
int N;
vector<int> v;
void DFS(int cur) {
	for (int i = 0; i < N; ++i) {
		if (v[i] == cur) {
			v[i] = -2;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int erase;
	cin >> erase;

	v[erase] = -2;
	DFS(erase);

	int cnt = 0;
	vector<int> visited(N);
	for (int i = 0; i < N; ++i) {
		if (v[i] == -2)
			visited[i] = 1;
		else if (v[i] == -1)
			continue;
		else
			visited[v[i]] = 1;
	}

	for (int i = 0; i < N; ++i)
		if (!visited[i])
			++cnt;
	cout << cnt << "\n";
}