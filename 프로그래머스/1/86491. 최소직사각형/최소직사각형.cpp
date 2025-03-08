#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	for (auto& v : sizes) {
		if (v[0] < v[1]) {
			swap(v[0], v[1]);
		}
	}
	int max1, max2;
	max1 = max2 = 0;
	for (int i = 0; i < sizes.size(); ++i) {
		if (max1 < sizes[i][0])
			max1 = sizes[i][0];
		if (max2 < sizes[i][1])
			max2 = sizes[i][1];
	}

	return max1 * max2;
}