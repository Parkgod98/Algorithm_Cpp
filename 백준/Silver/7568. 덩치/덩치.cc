#define _crt_secure_no_warnings
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		int kg, h;
		cin >> kg >> h;
		v.push_back({ kg,h });
	}

	for (int i = 0; i < n; ++i) {
		int count = 1;
		for (int j = 0; j < n; ++j) {
			if (j == i)
				continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				count++;
		}
		cout << count << " ";
	}



}
