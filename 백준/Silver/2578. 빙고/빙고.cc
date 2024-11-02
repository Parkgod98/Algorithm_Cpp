#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int GetBingo(vector<vector<int>>& v)
{
	
	int count = 0;
	int dialog_flag = 2;
	for (int i = 0; i < 5; ++i) {
		if (v[i][i] != 0) {
			dialog_flag--;
			break;
		}
	}
	for (int i = 0; i < 5; ++i) {
		if (v[i][4 - i] != 0) {
			dialog_flag--;
			break;
		}
	}

	count += dialog_flag;
	/* 가로, 세로 체크 */
	for (int i = 0; i < 5; ++i) {
		int garo_bingo_flag, sero_bingo_flag;
		garo_bingo_flag = sero_bingo_flag = 1;
		for (int j = 0; j < 5; ++j) {
			if (v[i][j] != 0) {
				garo_bingo_flag = 0;
			}
			if (v[j][i] != 0) {
				sero_bingo_flag = 0;
			}
		}
		count += (garo_bingo_flag + sero_bingo_flag);
		if (count >= 3)
			return count;
	}
	return 0;
}

int main(void)
{
	vector<vector<int>> v(5, vector<int>(5));
	map<int, pair<int, int>> location;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> v[i][j];
			location[v[i][j]] = { i,j };
		}
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int n;
			cin >> n;
			int y = location[n].first;
			int x = location[n].second;
			v[y][x] = 0;
			if (i >= 2 && GetBingo(v) >= 3) {
				cout << i * 5 + (j+1) << "\n";
				return 0;
			}
		}
	}
}
