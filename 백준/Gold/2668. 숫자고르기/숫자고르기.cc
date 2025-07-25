#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N;

int main() {
	cin >> N;

	vector<int> v(N + 1);
	set<int> a, b;
	for (int i = 1; i <= N; ++i) {
		cin >> v[i];
		a.insert(i);
		b.insert(v[i]);
	}

	while (1) {
		bool Find = false;
		for (auto it = a.begin(); it != a.end();) {
			if (b.find(*it) == b.end()) {
				it = a.erase(it);
				Find = true;
			}
			else
				++it;
		}
		if (!Find)
			break;
		b.clear();
		for (int n : a) {
			b.insert(v[n]);
		}
	}

	cout << a.size() << "\n";
	vector<int> ans;
	for (int n : a)
		ans.push_back(n);
	sort(ans.begin(), ans.end());
	for (int &i : ans)
		cout << i << "\n";

}