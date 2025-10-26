#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t, v, e;
	cin >> t;
	vector<int> res;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		res.push_back(2 - v + e);
	}

	for (auto k : res) {
		cout << k << "\n";
	}

}