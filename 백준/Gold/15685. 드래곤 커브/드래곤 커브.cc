#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std;
int n;
vector<vector<int>> v(120, vector<int>(120));

vector<int> GetDragonCurve(int d, int g) {
	vector<int> dir = { d };


	for (int i = 1; i <= g; ++i) {
		int sz = dir.size();
		for (int j = sz - 1; j >= 0; --j) {
			dir.push_back((dir[j] + 1) % 4);
		}
	}

	return dir;

}
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		v[x][y] = 1;
		vector<int> dir = GetDragonCurve(d, g);
		for (int &d : dir) {
			x += dy[d];
			y += dx[d];
			v[x][y] = 1;
			//cout << "x : " << x << " , y : " << y << "\n";
		}

		/*for (int &d : dir)
			cout << d << " ";
		cout << "\n";*/
	}

	int cnt = 0;
	for (int i = 0; i <= 99; ++i) {
		for (int j = 0; j <= 99; ++j) {
			if (v[i][j] == 1 && v[i][j + 1] == 1 && v[i + 1][j] == 1 && v[i + 1][j + 1] == 1)
				++cnt;
		}
	}

	cout << cnt << "\n";
}


// 0 1 2 1 : 2 3 2 1
// 1 2 3 2
// 2 7 3 4
// 3 0 1 0 1 2 1 0 1 2 3 2 1 2 1 0
// 3 7
// 3 8 
// 2 8 // 0 : 2 9 // 1 : 1 9 // 2 : 1 8 // 1 : 0 8 // 0 :0 9