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
// atoi(s.c_str());
// stoi()



int main()
{

	string s;
	cin >> s;

	int count[26] = { 0 };
	for (char c : s)
		count[c - 'A']++;

	int flag = 0;
	char mid = ' ';
	string ret = "";
	for (int i = 'Z'; i >= 'A'; --i) {
		if (count[i-'A'] % 2 == 1) {
			mid = (char)i;
			flag++;
			count[i-'A']--;
		}
		if (flag == 2)
			break;
		while (count[i-'A'] > 0) {
			ret += (char)i;
			ret = (char)i + ret;
			count[i-'A'] -= 2;
		}
	}
	if (flag == 1)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo" << "\n";
	else {
		cout << ret << "\n";
	}
}