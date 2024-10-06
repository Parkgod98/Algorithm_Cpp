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
#define INF 99999999
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()



struct scv {
	int a, b, c;
};

int solve(int a, int b, int c, vector<vector<vector<int>>> &visited, vector<vector<int>> &v)
{
	visited[a][b][c] = 1;
	queue<scv> q;
	q.push({ a,b,c });
	
	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0])
			break;
		for (int i = 0; i < 6; ++i) {
			int na = max(0, a - v[i][0]);
			int nb = max(0, b - v[i][1]);
			int nc = max(0, c - v[i][2]);
			if (visited[na][nb][nc])
				continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}
	
	return visited[0][0][0] -1;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> k(3);
	for (int i = 0; i < n; ++i){
		cin >> k[i];
	}
	vector<vector<int>> dy = { {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9} };
	vector<vector<vector<int>>> visited(k[0] + 1, vector<vector<int>>(k[1] + 1, vector<int>(k[2] + 1)));
	cout << solve(k[0], k[1], k[2], visited, dy) << "\n";
	

	return 0;
}
