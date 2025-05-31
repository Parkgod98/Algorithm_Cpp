#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int L, N;
	cin >> L >> N;

	vector<int> v(L + 1);

	int mx_expect,expect_value, mx_real,real_value;
	mx_expect = expect_value = mx_real = real_value = 0;

	for (int i = 1; i <= N; ++i) {
		int P, K;
		cin >> P >> K;
		if (K - P + 1 > expect_value) {
			mx_expect = i;
			expect_value = K - P + 1;
		}

		for (int j = P; j <= K; ++j) {
			if (v[j] == 0) {
				v[j] = i;
			}
		}
	}

	vector<int> v2(N + 1);
	for (int i = 1; i <= L; ++i) {
		v2[v[i]]++;
	}

	for (int i = 1; i <= N; ++i) {
		if (real_value < v2[i]) {
			real_value = v2[i];
			mx_real = i;
		}
	}

	cout << mx_expect << "\n" << mx_real << "\n";
}