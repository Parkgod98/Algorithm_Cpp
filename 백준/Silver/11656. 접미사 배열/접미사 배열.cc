#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	vector<string> res(n);

	for (int i = 0; i < n; ++i) {
		string tmp = s.substr(i);
		res[i] = tmp;
	}

	sort(res.begin(), res.end());
	for (string &i : res)
		cout << i << "\n";
}
