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
	for (int i = 0; i < N; ++i) {
		int cur = v[i];
		int cnt = 0;
		for (int j = i + 1; j < N; ++j) {
			if (v[j] > cur) {
				break;
			}
			else
				++cnt;
		}
		if (mx < cnt)
			mx = cnt;
	}
	cout << mx << "\n";
}