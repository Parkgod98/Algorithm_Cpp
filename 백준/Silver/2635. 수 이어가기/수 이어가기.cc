#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(void) {
	int n;
	cin >> n;

	int start = n;
	int mx = 1;
	vector<int> res = { n };
	while (start > 0) {

		vector<int> v = { n };
		v.push_back(start);
		int i1, i2;
		i1 = 0;
		i2 = 1;
		int sstart = v[i1] - v[i2];
		while (sstart >= 0) {
			v.push_back(sstart);
			i1++;
			i2++;
			sstart = v[i1] - v[i2];
		}
		if (mx < v.size()) {
			res = v;
			mx = v.size();
		}
		--start;
	}

	cout << mx << "\n";
	for (int &c : res)
		cout << c << " ";
	cout << "\n";
}