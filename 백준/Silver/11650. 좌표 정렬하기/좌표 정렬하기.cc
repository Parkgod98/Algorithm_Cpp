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

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

bool compare(pair<int,int> a, pair<int,int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pair<int, int> p = { x,y };
		v.push_back(p);
	}
	sort(v.begin(), v.end(),compare);

	for (pair<int, int> p : v)
		cout << p.first << " " << p.second << "\n";
}
