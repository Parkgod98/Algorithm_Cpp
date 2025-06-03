#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <set>
using namespace std;

int main() {
	vector<pair<int, int>> v(8);

	for (int i = 0; i < 8; ++i) {
		int n;
		cin >> n;
		v[i] = { n,i + 1 };
	}
	sort(v.begin(), v.end());

	int sum = 0;
	vector<int> res;
	for (int i = 3; i < 8; ++i) {
		sum += v[i].first;
		res.push_back(v[i].second);
	}

	sort(res.begin(), res.end());
	cout << sum << "\n";
	for (int &i : res)
		cout << i << " ";
}