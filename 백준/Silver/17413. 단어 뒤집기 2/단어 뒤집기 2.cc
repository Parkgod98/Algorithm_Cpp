#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
using namespace std;

int main(void)
{
	string s;
	string result = "";
	getline(cin, s);

	int len = s.length();
	int flag = 0;
	string tmp = "";
	for (int i = 0; i < len; ++i) {
		if (s[i] == '<')
			flag = 1;
		else if (s[i] == '>') {
			flag = 0;
			result += s[i];
			continue;
		}
		if (flag == 1) {
			if (tmp != "") {
				reverse(tmp.begin(), tmp.end());
				result += tmp;
				tmp = "";
			}
			result += s[i];
			continue;
		}
		else {
			if (s[i] != ' ')
				tmp += s[i];
			else {
				reverse(tmp.begin(), tmp.end());
				result += (tmp + s[i]);
				tmp = "";
			}
		}
	}
	reverse(tmp.begin(), tmp.end());
	result += tmp;
	cout << result;


}
