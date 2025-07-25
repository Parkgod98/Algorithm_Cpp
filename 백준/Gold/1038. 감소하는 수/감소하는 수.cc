#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int N;
vector<long long> v;
int cnt = 0;

void DFS(int len, long long n, int depth, int cur) {
	if (len == depth) {
		v.push_back(n);
		++cnt;
		return;
	}

	for (int i = 0; i <= cur-1; ++i) {
		n *= 10;
		n += i;
		DFS(len, n, depth + 1,i);
		n -= i;
		n /= 10;
	}
}
int main() {
	cin >> N;


	for (int i = 1; i <= 10; ++i) { // 1자리 ~ 9자리까지
		for (int j = 0; j <= 9; ++j) { // 1부터 ~ 9까지
			DFS(i, j, 1,j);
		}
	}

	if (N >= v.size())
		cout << -1 << "\n";
	else
		cout << v[N] << "\n";
}