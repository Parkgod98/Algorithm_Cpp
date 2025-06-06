#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int cnt = 0;

	for (int i = N - 1; i > 0; --i) {
		while (v[i] <= v[i - 1]) {
			++cnt;
			v[i-1]--;
		}
	}
	cout << cnt << "\n";
}