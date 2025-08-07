#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int s, e;
	int len = 0;

	bool operator <(const Edge &other) const {
		return len < other.len;
	}
};

vector<Edge> e_list;

int N, M;
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int parent[7] = { 0 };

void PrintV() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void GetEdge(int i, int j, int val) {

	for (int d = 0; d < 4; ++d) {
		int ny = i + dy[d];
		int nx = j + dx[d];

		int sum = 0;
		while (1) {
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == val)
				break;
			if (v[ny][nx] == 0)
				sum += 1;
			else {
				if (sum >= 2) {
					e_list.push_back({ val,v[ny][nx],sum });
				}
				break;
			}
			ny += dy[d];
			nx += dx[d];
		}
	}
}


void BFS(int i, int j, int num) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = 1;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int y = it.first;
		int x = it.second;
		v[y][x] = num;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
				continue;
			if (v[ny][nx] == 0)
				continue;
			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
}

int find_parent(int cur) {
	if (parent[cur] == cur)
		return cur;
	return parent[cur] = find_parent(parent[cur]);
}

bool union_parent(int a, int b) {
	int ap = find_parent(a);
	int bp = find_parent(b);

	if (ap == bp)
		return false;
	if (ap > bp)
		swap(ap, bp);

	parent[bp] = ap;
	return true;
}

int main() {
	cin >> N >> M;
	v = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<int>>(N, vector<int>(M));
	/* 입력 받기. 섬은 -1로 치환. Why? -> 섬을 1,2,3으로 넘버링 하기 위한 초기 세팅 */
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 1) {
				v[i][j] = -1;
			}
		}
	}

	/* 각 섬 1부터 시작해서 넘버링 해주기 */
	int num = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == -1 && !visited[i][j]) {
				BFS(i, j, num);
				++num;
			}
		}
	}

	//PrintV();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] != 0) {
				GetEdge(i, j, v[i][j]);
			}
		}
	}
	sort(e_list.begin(), e_list.end());

	//for (int i = 0; i < e_list.size(); ++i) {
	//	cout << e_list[i].s << " " << e_list[i].e << " " << e_list[i].len << "\n";
	//}

	// 각자 부모가 누군지 초기화.
	for (int i = 0; i < 7; ++i)
		parent[i] = i;

	int ans = 0;
	for (int i = 0; i < e_list.size(); ++i) {
		Edge e = e_list[i];
		int cur = e.s;
		int nxt = e.e;
		int cost = e.len;

		if (union_parent(cur, nxt)) {
			ans += cost;
		}
	}

	int p = find_parent(1);
	for (int i = 2; i < num; ++i) {
		if (p != find_parent(i)) {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << ans << "\n";

}