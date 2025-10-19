#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N, K;
#define INF 99999999
struct Point {
	int loc, num;
};

int main() {
	cin >> N >> K;

	queue<Point> q;
	q.push({ N,0 });
	vector<int> visited(100001, INF);
	visited[N] = 0;

	int cnt = 0;
	int mn = INF;
	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		int cur = it.loc;
		int num = it.num;

		if (cur == K && mn >= cur) {
			if (mn > cur) {
				mn = cur;
				cnt = 0;
			}
			++cnt;
		}
		if (cur + 1 <= 100000 && (visited[cur+1] >= (num + 1))) {
			q.push({ cur + 1,num + 1 });
			visited[cur + 1] = num+1;
		}
		if (cur - 1 >= 0 && (visited[cur-1] >= (num + 1))) {
			q.push({ cur - 1,num + 1 });
			visited[cur - 1] = num+1;
		}
		if (cur * 2 <= 100000 && (visited[cur*2] >= (num + 1))) {
			q.push({ cur * 2,num + 1 });
			visited[cur * 2] = num+1;
		}

	}

	cout << visited[K] << "\n" << cnt << "\n";
}
