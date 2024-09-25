#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
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
	int n;
	cin >> n;
	
	string res = "";
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (res.empty())
			res = s;
		else {
			for (int j = 0; j < res.size(); ++j) {
				if (res[j] != s[j])
					res[j] = '?';
			}
		}
	}
	cout << res;
}
