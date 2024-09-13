//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);

int main()
{
	int n;
	cin >> n;

	map<char, int> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (m[s[0]])
			m[s[0]] += 1;
		else
			m[s[0]] = 1;
	}

	vector<char> res;
	for (auto it : m) {
		if (it.second >= 5)
			res.push_back(it.first);
	}

	if (res.size() == 0)
		cout << "PREDAJA";
	else {
		for (char c : res)
			cout << c;
	}
}