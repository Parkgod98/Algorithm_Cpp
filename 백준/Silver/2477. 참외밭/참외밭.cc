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


int main(void)
{
	int k;
	cin >> k;

	vector<pair<int, int>> v;
	for (int i = 0; i < 6; ++i) {
		int direction, len;
		cin >> direction >> len;
		v.push_back({ direction,len });
	}
	
	int max_height, max_width;
	max_height = max_width = 0;
	for (pair<int, int> p : v) {
		if (p.first == 3 || p.first == 4)
			max_height = max(max_height, p.second);
		else
			max_width = max(max_width, p.second);
	}
	int whole_area = max_height * max_width;

	for (int i = 0; i < 6; ++i)
		v.push_back(v[i]);

	int small_area = 0;
	for (int i = 0; i < 9; i++) {
		if (v[i].first == v[i + 2].first && v[i+1].first == v[i+3].first) {
			small_area = v[i + 1].second * v[i + 2].second;
			break;
		}
	}
	cout << (whole_area - small_area) * k;
	return 0;
}		
