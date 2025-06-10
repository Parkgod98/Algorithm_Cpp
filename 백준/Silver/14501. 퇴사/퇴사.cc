#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int N;
int mx = 0;
vector<pair<int, int>> v;

void DFS(int day, int money) {
	mx = max(money, mx);
	if (day >= N)
		return;
	else {
		if(day + v[day].first <= N)
			DFS(day + v[day].first, money + v[day].second);
		DFS(day + 1, money);
	}
}

int main() {
	cin >> N;

	v= vector<pair<int, int>>(N);
	for (int i = 0; i < N; ++i) {
		int ti, pi;
		cin >> ti >> pi;
		
		v[i] = { ti,pi };
	}

	DFS(0,0);
	cout << mx << "\n";
}