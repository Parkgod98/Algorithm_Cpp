#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <deque>
#include <set>
using namespace std;


int main() {
	string s;
	cin >> s;

	string mask1 = "XXXX";
	string mask2 = "XX";

	int idx = 0;
	int start = 0;
	do {
		idx = s.find(mask1, start);
		if (idx != string::npos) {
			for (int i = idx; i < idx + mask1.size(); ++i)
				s[i] = 'A';
			start = idx + mask1.size();
		}
	} while (idx != string::npos);

	idx = start = 0;
	do {
		idx = s.find(mask2, start);
		if (idx != string::npos) {
			for (int i = idx; i < idx + mask2.size(); ++i)
				s[i] = 'B';
			start = idx + mask2.size();
		}
	} while (idx != string::npos);

	if (s.find('X') == string::npos)
		cout << s;
	else
		cout << -1;
}