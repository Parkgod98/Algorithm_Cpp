#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

void Solve(string &s, int idx_start, int idx_end) {
	int sz = idx_end - idx_start + 1;
	if (sz < 3)
		return;
	int start = sz / 3;
	int end = sz / 3 * 2;

	for (int i = idx_start+start; i < end+idx_start; ++i)
		s[i] = ' ';

	Solve(s, idx_start, idx_start+start - 1);
	Solve(s, idx_start+end, idx_end);
}

int main() {
	
	int n;
	while (cin >> n) {

		string s(pow(3, n), '-');
		Solve(s,0,pow(3,n)-1);
		cout << s << "\n";
	}
}  