#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	vector<int> v(9);
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> v[i];
		sum += v[i];
	}

	int ri, rj;
	ri = rj = -1;
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - (v[i] + v[j]) == 100) {
				ri = i;
				rj = j;
				break;
			}
		}
		if (ri != -1)
			break;
	}
	for (int i = 0; i < 9; ++i) {
		if (i == ri || i == rj)
			continue;
		cout << v[i] << "\n";
	}
}