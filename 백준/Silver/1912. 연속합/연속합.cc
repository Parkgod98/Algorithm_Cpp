#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int mx, cur;
	mx = cur = v[0];
	for (int i = 1; i < n; ++i) {
		cur = max(v[i], cur + v[i]);
		mx = max(mx, cur);
	}
	cout << mx << "\n";
}  