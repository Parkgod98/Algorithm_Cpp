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
int N, M,cur;
int arr[8];
vector<int> v;
void DFS(int idx) {
	if (cur == M) {
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = -1;
	for (int i = idx; i < N; ++i) {
		if (v[i] != tmp) {
			arr[cur] = v[i];
			cur++;
			tmp = v[i];
			DFS(i);
			cur--;
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