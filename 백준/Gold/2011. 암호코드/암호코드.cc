#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MOD 1000000

string s;
int main(void) {
	cin >> s;
	int SZ = s.size();
	vector<int> dp(SZ + 1);
	dp[0] = 1;
	for (int i = 1; i <= SZ; ++i) {
		if (s[i - 1] == '0') {
			if (i - 2 >= 0) {
				if (s[i - 2] == '1' || s[i - 2] == '2') {
					dp[i] += (dp[i - 2]) % MOD;
				}
				else {
					break;
				}
			}
		}
		else {
			if (i - 2 >= 0) {
				if (s[i - 2] == '2' && s[i - 1] <= '6' || (s[i - 2] == '1'))
					dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
				else
					dp[i] = (dp[i - 1]) % MOD;
			}
			else
				dp[i] = 1;

		}
	}

	cout << dp[SZ] << "\n";

}
