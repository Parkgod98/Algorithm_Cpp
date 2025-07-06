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
int N;
vector<vector<int>> cost;
int mn;

int main(void){
	cin >> N;
	int r, g, b;
	cin >> r >> g >> b;
	vector<vector<int>> cost(N, vector<int>(3));
	cost[0][0] = r;
	cost[0][1] = g;
	cost[0][2] = b;

	for (int i = 1; i < N; ++i) {
		cin >> r >> g >> b;
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + r;
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + g;
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + b;
	}

	cout << min(cost[N - 1][0], min(cost[N - 1][1], cost[N - 1][2]));
}