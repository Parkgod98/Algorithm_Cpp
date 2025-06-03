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
	int N;
	cin >> N;

	set<int> s;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		s.insert(n);
	}

	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
}