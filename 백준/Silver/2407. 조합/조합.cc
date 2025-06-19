#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
#include <list>
using namespace std;

string Comb(string a, string b) {
	string res = "";
	int carry = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() > b.size())
		swap(a, b);

	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); ++i) {
			int sum = (a[i] - '0') + (b[i] - '0') + carry;
			carry = sum / 10;
			res.push_back(sum % 10 +'0');
		}
		if (carry)
			res.push_back(carry+'0');
	}
	else { // b가 무조건 클 것.
		for (int i = 0; i < a.size(); ++i) {
			int sum = (a[i] - '0') + (b[i] - '0') + carry;
			carry = sum / 10;
			res.push_back(sum % 10 + '0');
		}
		for (int i = a.size(); i < b.size(); ++i) {
			int sum = (b[i] - '0') + carry;
			carry = sum / 10;
			res.push_back(sum % 10 + '0');
		}
		if (carry)
			res.push_back(carry +'0');
	}

	reverse(res.begin(), res.end());
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<string>> dp(101, vector<string>(101));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || i == j) {
				dp[i][j] = "1";
			}
			else {
				dp[i][j] = Comb(dp[i - 1][j - 1],dp[i - 1][j]);
			}
		}
	}

	cout << dp[n][m] << "\n";

}  