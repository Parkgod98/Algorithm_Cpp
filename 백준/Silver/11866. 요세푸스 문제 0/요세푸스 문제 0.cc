#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N + 1,1);

	cout << "<";

	int idx = K;
	int limit = 0;
	while (limit < N) {
		if (v[idx] == 1) {
			if (limit != N - 1) {
				cout << idx << ", ";
			}
			else {
				cout << idx << ">\n";
			}
			v[idx] = 0;
			limit++;
		}
		else {
			int cnt = 0;
			while (cnt < K) {
				idx++;
				idx %= (N + 1);
				if (!(v[idx] == 0 || idx == 0)) {
					++cnt;
				}
			}
		}
	}
	
}