#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()


int main()
{
	vector<vector<char>> v;

	for (int i = 0; i < 5; ++i) {
		string s;
		cin >> s;
		
		int len = s.length();
		vector<char> c;
		for (int i = 0; i < len; ++i) {
			c.push_back(s[i]);
		}
		v.push_back(c);
	}
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i < v[j].size())
				cout << v[j][i];
		}
	}
}
