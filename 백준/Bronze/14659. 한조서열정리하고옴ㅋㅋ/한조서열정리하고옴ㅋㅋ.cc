#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int mx = 0;
	int peak = v[0];
	int cnt = 0;
	for (int i = 1; i < N; ++i) {
		if (v[i] < peak) {
			++cnt;
		}
		else {
			mx = max(cnt, mx);
			cnt = 0;
			peak = v[i];
		}
	}
	mx = max(cnt, mx);
	cout << mx << "\n";
}