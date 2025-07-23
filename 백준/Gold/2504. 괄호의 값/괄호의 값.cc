#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int main() {
	string s;
	cin >> s;

	stack<char> st;

	int tmp = 1;
	int res = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			tmp *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			tmp *= 3;
			st.push(s[i]);
		}
		else {
			if (s[i] == ')') {
				if (!st.empty() && s[i - 1] == '(') {
					res += tmp;
					tmp /= 2;
					st.pop();
				}
				else if (!st.empty() && st.top() == '(') {
					tmp /= 2;
					st.pop();
				}
				else {
					cout << 0 << "\n";
					return 0;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty() && s[i - 1] == '[') {
					res += tmp;
					tmp /= 3;
					st.pop();
				}
				else if (!st.empty() && st.top() == '[') {
					tmp /= 3;
					st.pop();
				}
				else {
					cout << 0 << "\n";
					return 0;
				}
			}
		}
	}
	if (!st.empty())
		cout << 0 << "\n";
	else
		cout << res << "\n";
}