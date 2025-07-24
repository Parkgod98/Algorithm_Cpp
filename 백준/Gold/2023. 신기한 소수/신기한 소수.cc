#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

bool IsPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int N;
vector<int> ans;
void DFS(int n, int depth) {
	if (depth == N) {
		if (IsPrime(n)) {
			ans.push_back(n);
		}
		return;
	}

	for (int i = 1; i <= 9; ++i) {
		n *= 10;
		n += i;
		if (IsPrime(n))
			DFS(n, depth + 1);
		n -= i;
		n /= 10;
	}
}
int main() {
	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";
}