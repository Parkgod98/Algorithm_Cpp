#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long solution(vector<int> sequence) {
    long long dp1 = 0;
    long long dp2 = 0;
    long long ans = LLONG_MIN;

    int sign = 1;

    for(int x : sequence){
        long long a = 1LL*x*sign;
        long long b = -a;

        dp1 = max(a,dp1+a);
        dp2 = max(b,dp2+b);

        ans = max(ans,max(dp1,dp2));

        sign *= -1;
    }

    return ans;
}