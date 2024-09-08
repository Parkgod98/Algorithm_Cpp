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
	vector<int> alpha(26, -1);
	string s;
	cin >> s;

	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (alpha[s[i] - 'a'] == -1)
			alpha[s[i] - 'a'] = i;
	}
	for (int i : alpha)
		cout << i << " ";
}
	
