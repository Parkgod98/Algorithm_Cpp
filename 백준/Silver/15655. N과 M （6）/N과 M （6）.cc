#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int N, M;
vector<int> v, num;

void DFS(int depth,int idx) {
	if (depth == M) {
		for (int &i : v)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = idx + 1; i < N; ++i) {
		v.push_back(num[i]);
		DFS(depth + 1, i);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;

	num = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> num[i];

	sort(num.begin(), num.end());

	DFS(0, -1);
}  