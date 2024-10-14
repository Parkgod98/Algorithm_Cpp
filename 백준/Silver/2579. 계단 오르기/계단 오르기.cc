#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
using namespace std;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//
//cout << fixed;
//cout.precision(2);
// atoi(s.c_str());
// stoi()

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n+1);
	for (int i = 0; i < n; ++i)
		cin >> v[i+1];

	vector<int> dp(n+1);

	dp[1] = v[1]; // 첫번째 계단에 오는 가장 이득 보는값
	dp[2] = v[1] + v[2]; // 두번째 계단에 오는 가장 이득 보는 값
	dp[3] = max(v[1] + v[3], v[2] + v[3]); // 3번째 계단에 오는 가장 이득 보는값은 1,3일지, 2,3일지 판단해줘야함.
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i-3] + v[i-1] + v[i], dp[i-2] + v[i]); // i번째는 내 바로 이전에서 올수도있고, 2번째 이전에서 올수도있음. 
	}
	// 바로 이전에서 온다면 v[i-1] +v[i]를 무조건 밟아야 하므로, v[i-2]는 밟으면 안되니까 dp[i-3]이 가장 이득보면서 걸어왔을 경로고
	// 2번째 이전에서 온다면, 그냥 2칸 퐁 뛰어서올거니까 dp[i-2]에서 v[i]로 바로오면됨.
	cout << dp[n];
}