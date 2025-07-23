#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int N, M;
vector<int> skip(101);
vector<int> visited(101, 99999999);
int mn = 99999999;
void DFS(int cur, int cnt) {
	if (visited[cur] > cnt)
		visited[cur] = cnt;
	else
		return;
	if (skip[cur] != 0) {
			DFS(skip[cur],cnt);
			return;
	}
	for (int i = 1; i <= 6; ++i) {
		if(cur + i <= 100)
			DFS(cur + i,cnt+1);
	}
}

int main() {
	cin >> N >> M;

	
	for (int i = 0; i < N + M; ++i) {
		int a, b;
		cin >> a >> b;
		skip[a] = b;
	}

	DFS(1,1);
	cout << visited[100]-1 << "\n";
}