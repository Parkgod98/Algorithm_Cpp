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

bool OnlyZero(string s)
{
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (s[i] != '0')
			return false;
	}
	return true;
}

bool FrontZero(string s)
{
	int len = s.length();
	int flag = 0;
	for (int i = 0; i < len; ++i) {
		if ('1' <= s[i] && s[i] <= '9')
			flag = 1;
		if (flag == 0 && s[i] == '0')
			return true;
	}
	return false;
}

bool compare(string a, string b)
{
	int a_len = a.length();
	int b_len = b.length();
	if (a_len != b_len)
		return a_len < b_len;
	
	for (int i = 0; i < a_len; ++i) {
		if (a[i] != b[i])
			return a[i] < b[i];
	}
	return false;
}


int main()
{
	int n;
	cin >> n;
	
	vector<string> v;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		int j = 0;
		int len = s.length();
		string tmp = "";
		while (j < len) {
			if (isdigit(s[j]))
				tmp += s[j];
			else {
				if (!tmp.empty()) {
					v.push_back(tmp);
					tmp = "";
				}
			}
			j++;
		}
		if (!tmp.empty()) {
			v.push_back(tmp);
			tmp = "";
		}
	}
	
	for (int i = 0; i < v.size(); ++i) {
		if (OnlyZero(v[i]))
			v[i] = "0";
		else if (FrontZero(v[i])) {
			string tmp = "";
			int flag = 0;
			for (int j = 0; j < v[i].size(); ++j) {
				if (flag == 0 && v[i][j] != '0') {
					tmp += v[i][j];
					flag = 1;
				}
				else if (flag == 1)
					tmp += v[i][j];
			}
			v[i] = tmp;
		}
	}
	sort(v.begin(), v.end(), compare);
	for (string s : v)
		cout << s << "\n";
}
