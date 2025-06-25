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

int main() {
	vector<int> num;
	vector<char> op;

	string s;
	cin >> s;

	int prev = -1;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-' || s[i] == '+') {
			num.push_back(stoi(s.substr(prev + 1, i - prev - 1)));
			prev = i;
			op.push_back(s[i]);
		}
	}
	num.push_back(stoi(s.substr(prev + 1)));

	int sum = num[0];

	int n_idx = 1;
	int op_idx = 0;

	bool flag = false;
	for (int i = op_idx; i < op.size(); ++i) {
		if (flag) {
			sum -= num[n_idx];
		}
		else {
			if (op[i] == '-') {
				flag = true;
				sum -= num[n_idx];
			}
			else
				sum += num[n_idx];
		}
		n_idx++;

	}
	cout << sum << "\n";
}  