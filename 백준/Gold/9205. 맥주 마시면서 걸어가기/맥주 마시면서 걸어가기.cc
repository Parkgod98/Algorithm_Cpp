#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N,K;
vector<pair<int, int>> pyun;
bool Find = false;
pair<int, int> s;
pair<int, int> e;
vector<int> visited;

void bfs(int y, int x) {

	if ((abs(y - s.first) + abs(x - s.second)) <= 1000) {
		Find = true;
		return;
	}

	if (!Find) {
		for (int k = 0; k < pyun.size(); ++k) {
			if (!visited[k] && ((abs(y - pyun[k].first) + abs(x - pyun[k].second)) <= 1000)) {
				visited[k] = 1;
				bfs(pyun[k].first, pyun[k].second);
			}
		}
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		pyun.clear();
		Find = false;
		int y, x;
		cin >> y >> x;
		s = { y,x };
		for (int i = 0; i < N; ++i) {
			cin >> y >> x;
			pyun.push_back({ y,x });
		}
		visited = vector<int>(pyun.size());
		cin >> y >> x;
		e = { y,x };

		bfs(y, x);

		if (Find)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
}
