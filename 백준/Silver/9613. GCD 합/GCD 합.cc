#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int GetGCD(int a, int b) {
	
	while (a%b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return b;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int n;
		cin >> n;

		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];

		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j)
				sum += GetGCD(v[i], v[j]);
		}
		cout << sum << "\n";
	}
}