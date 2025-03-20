#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n,m;
	cin >> n >> m;
	
	vector<int> v(m);
	for(int i = 0; i < m; ++i)
		cin >> v[i];

	deque<int> dq;
	for(int i = 1; i <= n; ++i)
		dq.push_back(i);

	int cnt = 0;
	int i = 0;
	while(i < m) {
		int loc = find(dq.begin(), dq.end(), v[i]) - dq.begin();
		while(dq.front() != v[i]) {
			if(dq.size() - loc > loc) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			++cnt;
		}
		dq.pop_front();
		++i;
	}
	cout << cnt;
}