#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
using namespace std;
vector<int> v;

int main() {
	int n, M;
	cin >> n >> M;
	v = vector<int>(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	int start = 0;
	int end = 0;

	int mn = 2100000000;
	while (start <= end && end < n && start < n) {
		int value = v[end] - v[start];
		if (value < M) {
			++end;
		}
		else {
			++start;
			mn = min(value,mn);
		}
	}

	cout << mn << "\n";
}