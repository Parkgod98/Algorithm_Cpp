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

int main()
{	
	string s;
	cin >> s;
	
	map<string, int> m = { {"ABC",3}, {"DEF",4},{"GHI",5} ,{"JKL",6} ,{"MNO",7} ,{"PQRS",8},{"TUV",9},{"WXYZ",10}};

	int len = s.length();
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		for (auto it : m) {
			int flag = 0;
			for (char c : it.first)
				if (c == s[i]) {
					sum += it.second;
					flag = 1;
					break;
				}
			if (flag == 1)
				break;
		}
	}
	cout << sum << "\n";
}