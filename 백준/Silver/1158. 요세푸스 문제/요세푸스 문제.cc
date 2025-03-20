#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	list<int> ll;

	for(int i = 1; i <= n; ++i)
		ll.push_back(i);

	int i = 0;
	vector<int> ans;
	while(!ll.empty()) {
		int tmp = ll.front();
		ll.pop_front();
		++i;
		if(i == k) {
			ans.push_back(tmp);
			i = 0;
		}
		else {
			ll.push_back(tmp);
		}
	}
	cout << "<";
	for(int i = 0; i < ans.size(); ++i) {
		if(i != ans.size() - 1)
			cout << ans[i] << ", ";
		else
			cout << ans[i] << ">";
		
	}
}