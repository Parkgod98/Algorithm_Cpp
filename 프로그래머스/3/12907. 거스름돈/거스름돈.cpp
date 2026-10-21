#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007
using namespace std;

int solution(int n, vector<int> money) {
    
    vector<int> dp(n+1,0);
    
    dp[0] = 1;
    
    for (int &c : money){
        for (int i = c; i <= n; ++i){
            dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }
    
    return dp[n];
    
}