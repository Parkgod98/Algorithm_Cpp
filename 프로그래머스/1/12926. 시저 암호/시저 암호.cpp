#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); ++i) {
		if (isalpha(s[i])) {
			if (islower(s[i])) {
				if (s[i] + n > 'z')
					s[i] = s[i] + n - 26;
				else
					s[i] = s[i] + n;
			}
			else {
				if (s[i] + n > 'Z')
					s[i] = s[i] + n - 26;
				else
					s[i] = s[i] + n;
			}
		}
	}
	return s;
}