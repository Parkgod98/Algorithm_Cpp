#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i) {
		int sex, k;
		cin >> sex >> k;

		if (sex == 1) {
			for (int j = k - 1; j < N; j += k)
				v[j] = !v[j];
		}
		else {
			k = k - 1;
			int s = k - 1;
			int e = k + 1;
			while (s >= 0 && e < N) {
				if (v[s] == v[e]) {
					--s;
					++e;
				}
				else {
					break;
				}
			}
			for (int j = s + 1; j <= e - 1; ++j) {
				v[j] = !v[j];
			}
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		cout << v[i-1] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}
}
