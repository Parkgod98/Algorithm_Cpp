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

void Solve(vector<vector<int>> &v, int max_block, int m, int n, int b)
{
	long long min_time = m * n * 2 * 256;
	int height = max_block;
	for (int standard = 0; standard <= max_block; ++standard) {
		int block_substract = 0;
		int block_add = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (standard < v[i][j])  // 기준이 v[i][j] 보다 작으면, 블록을 뺀다.
					block_substract += v[i][j] - standard;
				else					// 기준이 v[i][j] 보다 크면, 블록을 추가한다.
					block_add += standard - v[i][j];
			}
		}
		if (block_substract + b < block_add) // 내가 갖고있는 블럭보다, 더해야 할 블럭이 많을땐, 불가능하므로 무시한다.
			break;
		long long time = block_substract * 2 + block_add;
		if (time <= min_time) {
			min_time = time;
			height = standard;
		}
	}

	cout << min_time << " " << height << "\n";
}

int main(void)
{
	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> v(n, vector<int>(m));
	int max_block = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			max_block = max(max_block, v[i][j]);
		}
	}
	
	Solve(v, max_block,m,n,b);
}		