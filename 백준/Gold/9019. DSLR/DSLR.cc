#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int a, b;

void BFS() {

	vector<int> visited(10000);

	queue<pair<int, string>> q;
	visited[a] = 1;
	q.push({ a,"" });

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int num = it.first;
		string com = it.second;

		if (num == b) {
			cout << com << "\n";
			return;
		}

		int d, s, l, r;
		d = (num * 2) % 10000;
		s = (num - 1);
		if (s < 0)
			s = 9999;
		l = (num % 1000) * 10 + (num / 1000);
		r = (num / 10) + (num % 10) * 1000;

		if (!visited[d]) {
			visited[d] = 1;
			q.push({ d,com + "D" });
		}
		if (!visited[s]) {
			visited[s] = 1;
			q.push({ s,com + "S" });
		}
		if (!visited[l]) {
			visited[l] = 1;
			q.push({ l,com + "L" });
		}
		if (!visited[r]) {
			visited[r] = 1;
			q.push({ r,com + "R" });
		}

	}
}


int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> a >> b;
		BFS();
	}
}