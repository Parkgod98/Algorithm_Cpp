#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int day = 1;
	for (int i = 0; i < N; ++i) {
		day = max(day, i + v[i] + 1);
	}
	cout << day + 1 << "\n";
} 