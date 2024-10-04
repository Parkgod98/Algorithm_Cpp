#define _CRT_SECURE_NO_WARNINGS
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
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool compare(tuple<int, string, int> a, tuple<int, string, int> b)
{
	if (get<0>(a) == get<0>(b))
		return get<2>(a) < get<2>(b);
	return get<0>(a) < get<0>(b);
}

int main()
{
	int n;
	cin >> n;

	vector<tuple<int, string, int>> v;

	for (int i = 0; i < n; ++i) {
		int a;
		string s;
		cin >> a >> s;
		v.push_back(make_tuple(a, s, i));
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; ++i) {
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n";
	}
}
