#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int K;
int main(void){
	cin >> K;

	vector<pair<int,int>> v(12);
	for (int i = 0; i < 6; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = v[i + 6] = { a,b };
	}

	int total, mini;
	for (int i = 0; i < 9; ++i) {
		if (v[i].first == v[i + 2].first && v[i + 1].first == v[i + 3].first) {
			mini = v[i + 1].second * v[i + 2].second;
			if (i == 0)
				total = v[i - 1+12].second*v[i + 4].second;
			else if (i == 8)
				total = v[i - 1].second*v[(i + 4)%12].second;
			else
				total = v[i - 1].second*v[i + 4].second;
		}
	}

	long long ans = ((long long)total - mini)*K;
	cout << ans << "\n";

}