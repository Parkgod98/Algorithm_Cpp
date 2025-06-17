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

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 1; i <= 223; ++i) {
		v.push_back(i*i);
	}

	for (int i = 0; i < v.size(); ++i) {
		if (n == v[i]) {
			cout << 1 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			if (n == v[i] + v[j]) {
				cout << 2 << "\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			for (int k = 0; k < v.size(); ++k) {
				if (n == v[i] + v[j] + v[k]) {
					cout << 3 << "\n";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			for (int k = 0; k < v.size(); ++k) {
				for (int x = 0; x < v.size(); ++x) {
					if (n == v[i] + v[j] + v[k] + v[x]) {
						cout << 4 << "\n";
						return 0;
					}
				}
			}
		}
	}
}  