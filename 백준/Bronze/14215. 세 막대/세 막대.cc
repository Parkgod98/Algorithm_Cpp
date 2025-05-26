#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(3);
	for (int i = 0; i < 3; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	while (v[0] + v[1] <= v[2]) {
		--v[2];
	}
	cout << v[0] + v[1] + v[2] << "\n";
}