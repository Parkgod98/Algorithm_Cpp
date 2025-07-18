#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
vector<int> v;
int UnionFind(int cur) {

	if (cur == v[cur])
		return cur;
	return v[cur] = UnionFind(v[cur]);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = vector<int>(n + 1);

	for (int i = 0; i <= n; ++i) {
		v[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		int com, a, b;
		cin >> com >> a >> b;
		if (a > b)
			swap(a, b);
		if (com == 0) {
			int res1 = UnionFind(a);
			int res2 = UnionFind(b);
			v[res2] = res1;
		}
		else {
			int res1 = UnionFind(a);
			int res2 = UnionFind(b);
			if (res1 == res2) {
				cout << "YES" << "\n";
			}
			else
				cout << "NO" << "\n";
		}
	}

	
}
