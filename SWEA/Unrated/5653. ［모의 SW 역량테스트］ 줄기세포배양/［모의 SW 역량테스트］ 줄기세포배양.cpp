#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <list>
using namespace std;
int N, M, K, r_SZ, c_SZ;
vector<vector<int>> v;
vector<vector<int>> visited;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void PrintV(vector<vector<int>> &v) {
	for (int i = 0; i < r_SZ; ++i) {
		for (int j = 0; j < c_SZ; ++j)
			cout << v[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}
struct Micro
{
	int y, x;
	int power;
	int left_time;
	bool activate;

	bool operator<(const Micro &other) const {
		return power < other.power;
	}
};

void GoTime(priority_queue<Micro> &pq) {

	priority_queue<Micro, vector<Micro>> new_pq;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		it.left_time--;
		if (it.left_time == 0 && it.activate == true)
			continue;
		else
			new_pq.push(it);
	}
	pq = new_pq;
}

void CheckActivate(priority_queue<Micro> &pq) {

	priority_queue<Micro, vector<Micro>> new_pq;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		if (it.left_time == 0 && it.activate == false) {
			it.activate = true;
			it.left_time = it.power;
		}
		new_pq.push(it);
	}
	pq = new_pq;
}

void Bunsik(priority_queue<Micro> &pq) {
	
	priority_queue<Micro, vector<Micro>> new_pq;
	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();
		it.left_time--;
		if (it.activate == true) {
			/* 사방으로 번식 시키기 */
			for (int i = 0; i < 4; ++i) {
				int ny = it.y + dy[i];
				int nx = it.x + dx[i];
				if (ny < 0 || ny >= r_SZ || nx < 0 || nx >= c_SZ) {
					cout << "나 이거 뭔가 잘못 푸는중이야. 맵을 무한히 잡았어.\n";
					return;
				}
				if (visited[ny][nx]) // 그 칸에 이미 누군가 있다면.
					continue;
				if (!visited[ny][nx]) { // 그 칸에 아무도 없다면.
					visited[ny][nx] = it.power;
					new_pq.push({ ny,nx,it.power,it.power,false });
					v[ny][nx] = it.power;
				}
			}
		}
		if (it.left_time > 0) {
			new_pq.push(it);
		}
		if (it.left_time == 0 && it.activate == false)
			new_pq.push(it);
	}

	pq = new_pq;
}

int main() {
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M >> K;
		r_SZ = N + 2 * K + 10;
		c_SZ = M + 2 * K + 10;
		v = vector<vector<int>>(r_SZ, vector<int>(c_SZ));
		visited = vector<vector<int>>(r_SZ, vector<int>(c_SZ));
		priority_queue<Micro, vector<Micro>> pq;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> v[i + K + 1][j + K + 1];
				visited[i + K + 1][j + K + 1] = v[i + K + 1][j + K + 1];
				pq.push({ i + K + 1,j + K + 1,v[i + K + 1][j + K + 1],v[i + K + 1][j + K + 1],false });
			}
		}

		int time = 0;
		while (1) {
			Bunsik(pq);       // 1시간이 지나면서 번식
			++time;
			if (time == K)
				break;
			CheckActivate(pq); // 활성 대상자들 활성 만들기.
			if (time == K)
				break;
			//PrintV(visited);
			if (time == K)
				break;
		}
		cout << "#" << tc << " " << pq.size() << "\n";
	}

}