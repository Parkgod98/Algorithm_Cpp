#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<vector<pair<int, int>>> tool =
{
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{0,1},{0,2},{1,2}},
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,0},{0,1},{0,2},{1,0}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{1,0},{2,0},{1,1}},
	{{0,0},{1,0},{2,0},{0,1}},
	{{0,0},{0,1},{0,2},{-1,2}},
	{{0,0},{0,1},{0,2},{-1,1}},
	{{0,0},{0,1},{0,2},{-1,0}},
	{{0,0},{1,0},{2,0},{2,-1}},
	{{0,0},{1,0},{2,0},{1,-1}},
	{{0,0},{1,0},{2,0},{0,-1}},
	{{0,0},{0,1},{1,0},{1,1}},
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,0},{1,0},{1,-1},{2,-1}},
	{{0,0},{0,1},{1,1},{1,2}},
	{{1,0},{1,1},{0,1},{0,2}}
};


int main(void)
{
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	int mx = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < tool.size(); ++k) {
				int y1, x1, y2, x2, y3, x3, y4, x4;
				y1 = i + tool[k][0].first;
				x1 = j + tool[k][0].second;
				y2 = i + tool[k][1].first;
				x2 = j + tool[k][1].second;
				y3 = i + tool[k][2].first;
				x3 = j + tool[k][2].second;
				y4 = i + tool[k][3].first;
				x4 = j + tool[k][3].second;
				if (y1 < 0 || x1 < 0 || y2 < 0 || x2 < 0 || y3 < 0 || x3 < 0 || y4 < 0 || x4 < 0 || y1 >= n || x1 >= m || y2 >= n || x2 >= m || y3 >= n || x3 >= m || y4 >= n || x4 >= m)
					continue;
				mx = max(mx, v[y1][x1] + v[y2][x2] + v[y3][x3] + v[y4][x4]);
			}
		}
	}
	cout << mx << endl;
}