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
// atoi(s.c_str());
// stoi()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		map<string, int> m;
		for (int j = 0; j < n; ++j) {
			string a,kind;
			cin >> a >> kind;
			m[kind] += 1;
		}
		long long res = 1;

		for (auto it : m)
			res *= (it.second + 1);
		res -= 1;
		cout << res << "\n";
	}
}