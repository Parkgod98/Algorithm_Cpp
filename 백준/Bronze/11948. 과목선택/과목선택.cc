#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(4),v2(2);

	for (int i = 0; i < 4; ++i)
		cin >> v[i];
	for (int i = 0; i < 2; ++i)
		cin >> v2[i];

	sort(v.begin(), v.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());

	cout << v[0] + v[1] + v[2] + v2[0] << "\n";
}