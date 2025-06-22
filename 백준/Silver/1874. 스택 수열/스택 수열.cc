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
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;


	int start = 1;
	stack<int> s;
	s.push(0);
	vector<char> res;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		while (start <= n && s.top() != k) {
			s.push(start);
			res.push_back('+');
			start++;
		}
		if (s.top() == k) {
			s.pop();
			res.push_back('-');
		}
	}

	if (s.size() == 1) {
		for (char &c : res)
			cout << c << "\n";
	}
	else
		cout << "NO" << "\n";
}  