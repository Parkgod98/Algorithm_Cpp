#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long ans = -1LL*100000*500000 -1;
    
    
    long long dp1,dp2;
    dp1 = dp2 = 0;
    int sign = 1;
    for (int &k : sequence){
        long long a = 1LL*sign*k;
        long long b = -a;
        
        dp1 = max(a,dp1 +a);
        dp2 = max(b,dp2+b);
        
        ans = max(ans,max(dp1,dp2));
        sign *= -1;
    }
    
    
    return ans;
}