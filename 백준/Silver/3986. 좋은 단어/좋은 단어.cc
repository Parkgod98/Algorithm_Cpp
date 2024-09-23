//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);

//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool IsGood(string s)
{
	stack<char> st;
	int len = s.size();
	if (len % 2 == 1)
		return false;
	for (int i = 0; i < len; ++i) {
		if (!st.empty() && st.top() == s[i])
			st.pop();
		else
			st.push(s[i]);
	}
	if (!st.empty())
		return false;
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (IsGood(s))
			count++;
	}

	cout << count;
}