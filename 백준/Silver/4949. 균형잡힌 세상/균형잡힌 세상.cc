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

bool IsV(string s)
{
	stack<char> stk;
	int len = s.length();

	for (int i = 0; i < len; ++i) {
		if (s[i] != '(' && s[i] != '[' && s[i] != ')' && s[i] != ']')
			continue;
		if (s[i] == '(' || s[i] == '[')
			stk.push(s[i]);
		else {
			if (!stk.empty() && stk.top() == '(' && s[i] == ')')
				stk.pop();
			else if (!stk.empty() && stk.top() == '[' && s[i] == ']')
				stk.pop();
			else
				return false;
		}
	}
	if (stk.empty())
		return true;
	return false;
}

int main()
{
	while(1) {
		string s;
		getline(cin, s);

		if (s == ".")
			break;
		if (IsV(s))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}

	return 0;
}
