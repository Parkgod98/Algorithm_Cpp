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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int n, c;
	cin >> n >> c;

	vector<int> num;
	map<int, pair<int,int>> m;
	/*키는 숫자. 1번째는 들어온 순서, 2번쨰는 횟수*/
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		if (k <= c) {
			if (m[k].second == 0) {
				m[k].first = i;
				m[k].second = 1;
			}
			else
				m[k].second++;
			num.push_back(k);
		}
	}
	vector<pair<int, int>> v;
	for (auto it : m) {
		v.push_back(it.second);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i) {
		for (int j = 0; j < v[i].second; ++j)
			cout << num[v[i].first] << " ";
	}
	
}
