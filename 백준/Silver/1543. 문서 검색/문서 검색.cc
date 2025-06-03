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
	int start = 0;
	while (idx != string::npos) {
		idx = s.find(mask,start);
		if (idx != string::npos) {
			cnt++;
			start = idx + mask.size();
		}
	}
	cout << cnt << "\n";
}