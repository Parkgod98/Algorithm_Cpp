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
int N, K;

vector<vector<int>> v;


int main() {
	cin >> N >> K;

	v = vector<vector<int>>(N + 1, vector<int>(N + 1));
	v[0][0] = v[1][0] = v[1][1] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i)
				v[i][j] = 1;
			else {
				v[i][j] = (v[i - 1][j - 1] + v[i - 1][j])%10007;
			}
		}
	}

	cout << v[N][K] << "\n";
}