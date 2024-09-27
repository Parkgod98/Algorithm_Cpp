#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool compare(string& a, string& b)
{
	int a_len = a.length();
	int b_len = b.length();
	if (a_len != b_len)
		return a_len < b_len;
	return a < b;
}

int main()
{
	int n;
	cin >> n;
	set<string> s;
	for (int i = 0; i < n; ++i) {
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	vector<string> v;
	for (string i : s)
		v.push_back(i);
	sort(v.begin(), v.end(), compare);

	for (string a : v)
		cout << a << "\n";
}
