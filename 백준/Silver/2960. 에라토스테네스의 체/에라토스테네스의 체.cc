#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int cnt = 0;
	vector<bool> v(N + 1, true);
	v[0] = v[1] = false;

	bool finish = false;
	for (int i = 2; i <= N; ++i) {
		if (v[i]) {
			for (int j = 1; j <= N / i; ++j) {
				if (v[j*i]) {
					v[j*i] = false;
					++cnt;
					if (cnt == K) {
						finish = true;
						cout << j * i << "\n";
						break;
					}
				}
			}
		}
		if (finish)
			break;
	}
}
