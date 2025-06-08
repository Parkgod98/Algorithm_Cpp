#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n+1);
	vector<int> res(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	
	if (n == 1)
		cout << v[1];
	else {
		res[0] = 0;
		res[1] = v[1];
		res[2] = v[1] + v[2];
		for (int i = 3; i <= n; ++i) {
			res[i] = max(v[i] + v[i - 1] + res[i - 3], v[i] + res[i - 2]);
		}
		cout << res[n] << "\n";
	}
}