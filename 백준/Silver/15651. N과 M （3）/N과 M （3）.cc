#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int N, M;
vector<int> v;
void DFS(int depth) {
	if (depth == M) {
		for (int &i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i) {
		v.push_back(i);
		DFS(depth + 1);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;

	DFS(0);
}