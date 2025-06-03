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
	getline(cin, s);

	string mask;
	getline(cin, mask);

	int cnt = 0;
	int idx = 0;
	while (idx < s.size()) {

		bool flag = true;
		if (idx + mask.size() > s.size())
			break;
		for (int i = 0; i < mask.size(); ++i) {
			if (s[i + idx] != mask[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			idx += mask.size();
			++cnt;
		}
		else
			++idx;
	}
	cout << cnt << "\n";
}