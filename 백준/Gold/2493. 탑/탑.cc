#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
using namespace std;
int N;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	vector<int> v(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];

	stack<pair<int,int>> st;
	vector<int> res(N + 1);
	for (int i = N; i >= 1; --i) {
		while (!st.empty() && v[i] > st.top().first) {
			res[st.top().second] = i;
			st.pop();
		}
		st.push({ v[i],i });
	}
	while (!st.empty()) {
		res[st.top().second] = 0;
		st.pop();
	}

	for (int i = 1; i <= N; ++i)
		cout << res[i] << " ";
}