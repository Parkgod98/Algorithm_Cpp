#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;

	set<int> s;
	for (int i = 0; i < M; ++i) {
		string com;
		cin >> com;
		int x;
		if (com == "add") {
			cin >> x;
			s.insert(x);
		}
		else if (com == "remove") {
			cin >> x;
			s.erase(x);
		}
		else if (com == "check") {
			cin >> x;
			if (s.find(x) != s.end()) {
				cout << 1 << "\n";
			}
			else
				cout << "0\n";
		}
		else if (com == "toggle") {
			cin >> x;
			if (s.find(x) != s.end()) {
				s.erase(x);
			}
			else
				s.insert(x);
		}
		else if (com == "all") {
			s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (com == "empty") {
			s.clear();
		}

	}
}