#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(4);

	int total_sum = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> v[i];
		total_sum += v[i];
	}

	int mn = abs(abs(total_sum - v[0] - v[1]) - abs(v[0] + v[1]));
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (abs(abs(total_sum - v[i] - v[j]) - abs(v[i] + v[j])) < mn) {
				mn = abs(abs(total_sum - v[i] - v[j]) - abs(v[i] + v[j]));
			}
		}
	}
	cout << mn << "\n";
}