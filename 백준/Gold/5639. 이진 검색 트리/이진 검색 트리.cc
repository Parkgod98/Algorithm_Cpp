#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
vector<int> v;

void Solve(int s, int e) {
	if (s >= e)
		return;
	int i = s + 1;
	while (i < e) {
		if (v[i] > v[s])
			break;
		++i;
	}
	Solve(s + 1, i);
	Solve(i, e);
	cout << v[s] << "\n";
}
int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	Solve(0, v.size());

}
