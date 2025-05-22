#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {

	for (int tc = 1; tc <= 10; ++tc) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		stack<char> st;
		for (int i = 0; i < s.size(); ++i) {
			if (!st.empty() && st.top() != s[i])
				st.push(s[i]);
			else if (!st.empty() && st.top() == s[i]) {
				st.pop();
			}
			else
				st.push(s[i]);
		}

		string res = "";
		while (!st.empty()) {
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());
		cout << "#" << tc << " " << res << "\n";
	}
}