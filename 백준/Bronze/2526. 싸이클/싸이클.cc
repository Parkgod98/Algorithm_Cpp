#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;

int main() {
	int N, P;
	cin >> N >> P;

	set<int> s;
	int value = N;
	int sz = s.size();
	while (1) {
		s.insert(value);
		value = (value*N) % P;
		if (sz == s.size()) {
			break;
		}
		sz = s.size();
	}

	set<int> s2;
	sz = 0;
	while (1) {
		s2.insert(value);
		value = (value*N) % P;
		if (sz == s2.size())
			break;
		sz = s2.size();
	}
	cout << sz << "\n";
}