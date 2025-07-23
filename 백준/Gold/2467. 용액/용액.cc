#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;


int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int s = 0;
	int e = N - 1;

	int mn = 2000000001;
	int a, b;
	while (s < e) {
		int sum = v[s] + v[e];

		if (abs(sum) < mn) {
			mn = abs(sum);
			a = v[s];
			b = v[e];
		}

		if (sum < 0)
			s++;
		else
			e--;
	}

	cout << a << " " << b << "\n";
}