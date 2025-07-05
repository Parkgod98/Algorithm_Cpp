#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	list<char> li;

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		li.push_back(s[i]);
	}

	int M;
	cin >> M;

	auto it = li.end();
	for (int i = 0; i < M; ++i) {
		char com;
		cin >> com;
		if (com == 'L') {
			if (it != li.begin())
				it--;
		}
		else if (com == 'D') {
			if (it != li.end())
				++it;
		}
		else if (com == 'B') {
			if (it != li.begin()) {
				--it;
				it = li.erase(it);
			}
		}
		else {
			char c;
			cin >> c;
			li.insert(it,c);
		}
	}

	while (!li.empty()) {
		cout << li.front();
		li.pop_front();
	}
}