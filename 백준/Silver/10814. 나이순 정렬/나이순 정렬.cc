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
typedef long long ll;

//ios_base::sync_with_stdio(false);
//cin.tie(null);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, string>> v;

	for (int i = 0; i < n; ++i) {
		int a;
		string s;
		cin >> a >> s;
		v.push_back({a,s});
	}

	stable_sort(v.begin(), v.end(), compare);
	for (pair<int, string> a : v)
		cout << a.first << " " << a.second << "\n";
}
