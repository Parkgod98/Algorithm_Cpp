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
vector<int> v,ans;
void DFS(int idx) {
	if (ans.size() == M) {
		for (int &i : ans) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = -1;
	for (int i = idx; i < N; ++i) {
		if (v[i] != tmp) {
			ans.push_back(v[i]);
			tmp = v[i];
			DFS(i);
			ans.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	DFS(0);
}