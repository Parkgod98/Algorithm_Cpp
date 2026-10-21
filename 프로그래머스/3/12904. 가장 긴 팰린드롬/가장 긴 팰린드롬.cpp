#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string s)
{
    int n = s.size();
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    int ans = 1;
    
    for (int i = n - 1; i >= 0; --i){
        
        for (int j = i; j < n; ++j){
            if(s[i] != s[j])
                continue;
            
            if(j-i <= 2 || dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                ans = max(ans,j-i+1);
            }
        }
    }
    
    return ans;
}