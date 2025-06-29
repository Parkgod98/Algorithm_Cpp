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
int N, M;
vector<int> v, ans;
vector<int> visited;
void Comb() {
	if (ans.size() == M) {
		for (int &i : ans)
			cout << i << " ";
		cout << "\n";
		return;
	}

	int tmp = -1;
	for (int i = 0; i < N; ++i) {
		if (!visited[i] && tmp != v[i]) {
			ans.push_back(v[i]);
			visited[i] = 1;
			tmp = v[i];
			Comb();
			ans.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;

	v = vector<int>(N);
	visited = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	Comb();
}