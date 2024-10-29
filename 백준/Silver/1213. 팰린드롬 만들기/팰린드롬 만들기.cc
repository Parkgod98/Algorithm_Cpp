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

int cnt[26] = { 0 };

bool is_impossible(string s)
{
	int len = s.length();
	for (int i = 0; i < len; ++i)
		cnt[s[i] - 'A']++;

	int flag = 0;
	for (int n : cnt) {
		if (len % 2 == 0 && n % 2 == 1)
			return true;
		else if (len % 2 == 1 && n % 2 == 1) 
			flag++;
		if (flag == 2)
			return true;
	}

	return false;
}


int main(void)
{
	string s;
	cin >> s;

	if (is_impossible(s))
		cout << "I'm Sorry Hansoo" << "\n";
	else {
		int len = s.length();
		string res = "";
		if (len % 2 == 1) {
			for (int i = 0; i < 26; ++i) { // 홀수 알파벳 찾기.
				if (cnt[i] % 2 == 1) {
					res += (char)(i + 'A');
					cnt[i]--;
					break;
				}
			}
		}
		for (int i = 25; i >= 0; --i) {
			while (cnt[i] != 0) {
				res = res + (char)(i + 'A');
				res = (char)(i + 'A') + res;
				cnt[i] -= 2;
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}		