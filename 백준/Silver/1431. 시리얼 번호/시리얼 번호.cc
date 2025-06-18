#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

int GetSum(string &a) {
	int sum = 0;

	for (int i = 0; i < a.size(); ++i) {
		if (isdigit(a[i]))
			sum += (a[i] - '0');
	}
	return sum;
}

bool compare(string &a, string &b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int a_sum = GetSum(a);
		int b_sum = GetSum(b);

		if (a_sum != b_sum) {
			return a_sum < b_sum;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<string> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (string &s : v)
		cout << s << "\n";
}  