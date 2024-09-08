//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	string s = to_string((long long)a * b * c);
	
	vector<int> v(10);
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		v[s[i] - '0'] += 1;
	}
	for (int i = 0; i <= 9; ++i)
		cout << v[i] << "\n";
}