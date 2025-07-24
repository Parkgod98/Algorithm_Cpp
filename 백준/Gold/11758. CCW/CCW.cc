#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

int cross_product(pair<int, int> &a, pair<int, int> &b) {
	
	return a.first*b.second - a.second*b.first;
}

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	pair<int, int> v1, v2;
	v1 = { x2 - x1,y2 - y1 };
	v2 = { x3 - x2,y3 - y2 };

	if (cross_product(v1, v2) > 0) // 반시계
		cout << 1 << "\n";
	else if (cross_product(v1, v2) < 0) // 시계방향
		cout << -1 << "\n";
	else
		cout << 0 << "\n";
}