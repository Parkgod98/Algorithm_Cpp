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
	map<int, int> mp;
	for(int i = n - 1; i >= 0; --i) {
		while(!st.empty() && st.top() < v[i]) {
			mp[st.top()] = i + 1;
			st.pop();
		}
		st.push(v[i]);
	}
	while(!st.empty()) {
		mp[st.top()] = 0;
		st.pop();
	}
	for(int i = 0; i < n; ++i)
		cout << mp[v[i]] << " ";
}