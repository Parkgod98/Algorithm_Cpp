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

int HackCount(vector<vector<int>> & v, int n, vector<int> &visited)
{
	visited[n] = 1;
	
	int cnt = 0;
	for (int i : v[n]) {
		if (!visited[i])
			cnt += HackCount(v, i, visited);
	}
	if (v[n].size() == 0)
		return 1;
	return ++cnt;
}

void InitVisit(vector<int>& visited)
{
	for (int i = 0; i < visited.size(); ++i)
		visited[i] = 0;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	vector<int> visited(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	int max_count = 0;
	vector<pair<int, int>> hack;
	for (int i = 1; i < v.size(); ++i) {
		int cnt = HackCount(v, i,visited);
		hack.push_back({ i,cnt });
		InitVisit(visited);
	}

	sort(hack.begin(), hack.end(), compare);
	vector<int> res;
	int max_hack = hack[0].second;
	for (pair<int, int> i : hack) {
		if (i.second == max_hack)
			res.push_back(i.first);
	}
	sort(res.begin(), res.end());
	
	for (int i : res)
		cout << i << " ";
}
