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
int N, K;

int main(void){
	cin >> N >> K;

	vector<int> visited(100001);
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	
	while (!q.empty()) {
		int cur = q.front();
		if (cur == K)
			break;
		q.pop();

		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
		if (cur + 1 <= 100000 && !visited[cur + 1]) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;

		}
		if (cur * 2 <= 100000 && !visited[cur * 2]) {
			q.push(cur * 2);
			visited[cur * 2] = visited[cur] + 1;
		}
	}
	cout << visited[K] - 1;
}