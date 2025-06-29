#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
string s;

int main() {
	cin >> s;

	stack<char> st;

	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			st.push('(');
		}
		else if (s[i] == ')' && s[i - 1] == '(') {
			st.pop();
			cnt += st.size();
		}
		else {
			st.pop();
			cnt += 1;
		}
	}

	cout << cnt << "\n";
}