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

int LeftCheck(vector<char>& v, int cur)
{
	int min_distance = 104;
	for (int i = 0; i < cur; ++i){
		if (v[i] == 'c') {
			int distance = cur - i;
			if (min_distance > distance)
				min_distance = distance;
		}
	}
	if (min_distance == 104)
		return -1;
	return min_distance;
}

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<char>> v(h);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c;
			cin >> c;
			v[i].push_back(c);
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (v[i][j] == 'c')
				cout << 0 << " ";
			else {
				int idx = LeftCheck(v[i], j);
				if (idx != -1)
					cout << idx << " ";
				else
					cout << -1 << " ";
 			}
		}
		cout << "\n";
	}
}
