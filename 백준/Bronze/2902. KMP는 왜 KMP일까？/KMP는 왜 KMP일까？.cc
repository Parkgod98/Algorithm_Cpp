#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	string s;
	cin >> s;

	string res = "";
	for (int i = 0; i < s.size(); ++i) {
		if (isupper(s[i])) {
			res += s[i];
		}
	}
	cout << res;
}