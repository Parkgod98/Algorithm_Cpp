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
vector<int> arr;
vector<vector<int>> v;

int main() {
	int N;
	cin >> N;

	v = vector<vector<int>>(N + 1);
	for (int i = 0; i < N -1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	arr = vector<int>(N + 1,-1);

	arr[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int &i : v[cur]) {
			if (arr[i] == -1) {
				arr[i] = cur;
				q.push(i);
			}
		}
	}

	for (int i = 2; i <= N; ++i)
		cout << arr[i] << "\n";
}  