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

	int B, C;
	cin >> B >> C;

	long long res = 0;
	for (int i = 0; i < N; ++i) {
		v[i] -= B;
		res += 1;
		if (v[i] <= 0) {
			continue;
		}
		else {
			if (v[i] % C == 0) {
				res += v[i] / C;
			}
			else {
				res += (v[i] / C) + 1;
			}
		}
	}

	cout << res << "\n";

}