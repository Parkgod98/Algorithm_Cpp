#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int mx = 0;
	for (int i = 0; i < N; ++i) {
		if (mx < v[i] * (N - i))
			mx = v[i] * (N - i);
	}
	cout << mx << "\n";
}
