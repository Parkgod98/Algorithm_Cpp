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
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool VPS(string s)
{
	stack<char> stk;
	int len = s.length();

	for (int i = 0; i < len; ++i) {
		if (stk.empty() && s[i] == ')')
			return false;
		if (s[i] == '(')
			stk.push(s[i]);
		else if (!stk.empty() && stk.top() == '(' && s[i] == ')')
			stk.pop();
	}
	if (stk.empty())
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (VPS(s))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}
