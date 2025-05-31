#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	vector<int> v(11,2);

	int N;
	cin >> N;

	int res = 0;
	for (int i = 0; i < N; ++i) {
		int n,state;
		cin >> n >> state;
		if (v[n] == 2) {
			v[n] = state;
		}
		else {
			if (v[n] != state) {
				v[n] = state;
				++res;
			}
		}
	}
	cout << res << "\n";
}