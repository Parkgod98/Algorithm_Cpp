#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	map<int, bool> mp;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (mp[k])
			continue;
		else
			mp[k] = true;
	}

	int m;
	cin >> m;
	vector<int> v;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		if (mp[k])
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}


}
