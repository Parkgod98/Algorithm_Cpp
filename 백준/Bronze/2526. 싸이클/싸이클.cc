#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	int N, P;
	cin >> N >> P;

	vector<int> v(P + 1);

	int value = N;
	while (1) {
		value = (value*N) % P;
		if (v[value] == 2)
			break;
		++v[value];
	}

	int res = 0;
	for (int i = 0; i < P; ++i) {
		if (v[i] == 2)
			++res;
	}
	cout << res << "\n";
}