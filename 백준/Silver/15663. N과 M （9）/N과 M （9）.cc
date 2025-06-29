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
set<string> s;
vector<int> v, ans;
vector<int> visited;
void Comb() {
	if (ans.size() == M) {
		string n = "";
		for (int i = 0; i < M; ++i) {
			n += ans[i];
		}
		if (s.find(n) == s.end()) {
			s.insert(n);
			for (int &i : ans)
				cout << i << " ";
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			ans.push_back(v[i]);
			visited[i] = 1;
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