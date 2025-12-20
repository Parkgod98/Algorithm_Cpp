#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v;
vector<int> indegree;
vector<vector<int>> sequence;
vector<int> res;

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
			res[i] = v[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();


		for (int &nxt : sequence[cur]) {
			indegree[nxt]--;
			res[nxt] = max(res[nxt], v[nxt] + res[cur]);
			if (indegree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
}
int main(){
	cin >> N;
	v = vector<int>(N + 1);
	indegree = vector<int>(N + 1);
	sequence = vector<vector<int>>(N + 1);
	res = vector<int>(N + 1);
	for (int i = 0; i < N; ++i) {

		int n;
		cin >> n;
		v[i + 1] = n;

		while (1) {
			int k;
			cin >> k;
			if (k == -1)
				break;
			sequence[k].push_back(i+1);
			indegree[i + 1]++;
		}
	}

	topology_sort();
	for (int i = 1; i <= N; ++i)
		cout << res[i] << "\n";
}