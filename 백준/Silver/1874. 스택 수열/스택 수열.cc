#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	stack<int> st;
	int s = 1;

	vector<char> ans;
	int i = 0;
	while(i < n && s <= n+1) {
		if(!st.empty() && st.top() == v[i]) {
			st.pop();
			ans.push_back('-');
			++i;
		}
		else {
			st.push(s);
			ans.push_back('+');
			s++;
		}
	}
	if(!st.empty())
		cout << "NO";
	else {
		for(char c : ans)
			cout << c << "\n";
	}

}