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

	vector<int> v(26);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		v[char(s[0]) - 'a']++;
	}
	int flag = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] >= 5) {
			cout << char(i + 'a');
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "PREDAJA";
}