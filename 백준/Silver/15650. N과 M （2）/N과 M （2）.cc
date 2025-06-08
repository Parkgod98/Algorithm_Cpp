#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int N, M;
vector<int> v;

void DFS(int depth, int idx) {
	if (depth == M) {
		for (int &i : v)
			cout << i << " ";
		cout << "\n";
	}

	for (int i = idx + 1; i <= N; ++i) {
		v.push_back(i);
		DFS(depth + 1, i);
		v.pop_back();
	}
}


int main() {
	cin >> N >> M;
	DFS(0,0);
}