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
#define CANT 100000000

int main() {
	cin >> N;

	vector<int> dp(N+1,CANT);
	for (int i = 1; i * i <= N; ++i)
		dp[i*i] = 1;

	for (int i = 2; i <= N; ++i) {
		if (dp[i] == 1)
			continue;
		for (int j = 1; j *j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << "\n";
}