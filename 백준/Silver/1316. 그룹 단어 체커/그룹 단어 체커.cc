#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()



int main()
{
	int n;
	cin >> n;

	
	int count = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		int len = s.length();
		char pc = s[0];
		int flag = 1;
		int arr[26] = { 0 };
		for (int j = 0; j < len; ++j) {
			char cur = s[j];
			if (cur != pc && arr[cur - 'a'] == 1) {
				flag = 0;
				break;
			}
			arr[cur - 'a'] = 1;
			pc = cur;
		}
		if (flag)
			count++;
	}
	cout << count;
}
