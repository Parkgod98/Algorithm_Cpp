#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int solution(string s) {
	int answer = 0;
	map<string, char> mp = { {"zero",'0'},{"one",'1'} ,{"two",'2'} ,
		{"three",'3'},{"four",'4'} ,{"five",'5'},{"six",'6'} ,{"seven",'7'},{"eight",'8'} ,{"nine",'9'} };
	string tmp = "";
	string ans = "";
	for (int i = 0; i < s.size(); ++i) {
		if (isdigit(s[i])) {
			ans += s[i];
		}
		else {
			tmp += s[i];
			if (tmp.size() >= 3) {
				if (mp[tmp]) {
					ans += mp[tmp];
					tmp.clear();
				}
			}
		}
	}
	return stoi(ans);
}