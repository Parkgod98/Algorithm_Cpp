#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		vector<int> v(10);
		for (int j = 0; j < 10; ++j)
			cin >> v[j];

		sort(v.begin(), v.end(),greater<int>());
		cout << v[2] << "\n";
	}
}