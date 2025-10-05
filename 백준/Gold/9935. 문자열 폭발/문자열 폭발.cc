#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
string a, b;

int main() {
	cin >> a >> b;

	string tmp = "";

	int a_len = a.size();
	int b_len = b.size();
	for (int i = 0; i < a_len; ++i) {
		tmp += a[i];

		if (tmp.size() >= b_len && (a[i] == b[b_len-1])) {

			bool IsRemove = true;
			int t_len = tmp.length();
			for (int j = 0; j < b_len; ++j) {
				if (tmp[t_len - b_len + j] != b[j]) {
					IsRemove = false;
					break;
				}
			}

			if (IsRemove) {
				for (int j = 0; j < b_len; ++j)
					tmp.pop_back();
			}
		}

	}

	if (tmp.size() == 0)
		cout << "FRULA" << "\n";
	else
		cout << tmp << "\n";
}