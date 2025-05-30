#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	int mx = v[N - 1];
	int res = 1;
	for (int i = N - 1; i >= 0; --i) {
		if (mx < v[i]) {
			++res;
			mx = v[i];
		}
	}
	cout << res;
}