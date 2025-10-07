#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;

int main() {
	cin >> N;
	// 0 3 
	vector<int> dp(31);
	dp[0] = 1;
	dp[2] = 3;
	if(N % 2 == 1) {
		cout << 0 << "\n";
		return 0;
	}
	
	for(int i = 4; i <= N; i += 2) {
		dp[i] = (dp[i - 2] * dp[2]);
		for(int j = i - 4; j >= 0; j -= 2)
			dp[i] += (dp[j] * 2);
	}

	cout << dp[N] << "\n";
}