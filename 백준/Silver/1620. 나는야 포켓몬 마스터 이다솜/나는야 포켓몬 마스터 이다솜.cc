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

bool IsDigit(string s)
{
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (isdigit(s[i]))
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<int, string> mm;
	map<string, int> mm2;

	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		mm[i] = s;
		mm2[s] = i;
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (IsDigit(s))
			cout << mm[stoi(s)] << "\n";
		else
			cout << mm2[s] << "\n";
	}	
}