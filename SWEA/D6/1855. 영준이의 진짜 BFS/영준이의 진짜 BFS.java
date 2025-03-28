#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N;

vector<int> graph[100001];
int par[100001][20];
int depth[100001];
bool visited[100001];

void Init() {
	for(int i = 0; i < 100001; ++i)
		graph[i].clear();
	for(int i = 0; i < 100001; ++i) {
		depth[i] = 0;
	}
	for(int i = 0; i < 100001; ++i)
		visited[i] = false;
}

long long LCA(int pre, int cur, int cnt) {
	if(depth[pre] > depth[cur])
		swap(pre, cur);
	if(par[cur][0] == pre)
		return 1;
	for(int i = 19; i >= 0; --i) {
		if(depth[cur] - depth[pre] >= (1 << i)) {
			cur = par[cur][i];
			cnt += (1 << i);
		}
	}
	if(par[pre][0] != par[cur][0]) {
		for(int i = 19; i >= 0; --i) {
			if(par[pre][i] != par[cur][i]) {
				cnt += 2 * (1 << i);
				pre = par[pre][i];
				cur = par[cur][i];
			}
		}
	}
	if(par[pre][0] == par[cur][0])
		return cnt + 2;
}

long long bfs() {
	long long result = 0;
	int pre, cur;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	pre = 1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 0; i < graph[x].size(); ++i) {
			int y = graph[x][i];
			if(visited[y])
				continue;
			q.push(y);
			cur = y;
			visited[y] = true;
			result += LCA(pre, cur, 0);
			pre = cur;
		}
	}
	return result;
}

int main(void) {
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		Init();
		par[1][0] = 0;
		depth[1] = 0;

		int k;
		for(int i = 0; i < N - 1; ++i) {
			cin >> k;
			graph[k].push_back(i + 2);
			depth[i + 2] = depth[k] + 1;
			par[i + 2][0] = k;
		}
		for(int y = 1; y < 20; ++y) { // 모든 노드에 직결된 2^0번째 조상은 알고있으니까 2^1번째 조상부터 2^19번쨰 조상까지 알아내기.
			for(int x = 1; x <= N; ++x) {
				par[x][y] = par[par[x][y - 1]][y - 1];
			}
		}
		cout << "#" << test_case << " " << bfs() << "\n";
	}
}