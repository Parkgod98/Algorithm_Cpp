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
vector<int> v,ans;
int n;

void Comb(int idx) {
	if (ans.size() == 6) {
		for (int &i : ans)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < v.size(); ++i) {
		ans.push_back(v[i]);
		Comb(i + 1);
		ans.pop_back();
	}
}

int main() {
	while (1) {
		cin >> n;

		if (n == 0)
			break;
		v = vector<int>(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];

		Comb(0);
		cout << "\n";
	}
}