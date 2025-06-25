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

	while (n_idx < num.size() && op_idx < op.size()) {
		if (op[op_idx] == '-') {
			int tmp = num[n_idx];
			int t_op_idx = op_idx+1;
			int t_n_idx = n_idx + 1;
			while (t_op_idx < op.size() && op[t_op_idx] != '-') {
				tmp += num[t_n_idx];
				t_n_idx++;
				t_op_idx++;
			}
			sum -= tmp;
			n_idx = t_n_idx;
			op_idx = t_op_idx;
		}
		else {
			sum += num[n_idx];
			n_idx++;
			op_idx++;
		}
	}
	cout << sum << "\n";
}  