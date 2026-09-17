#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int solution(vector<vector<int> > land)
{
    int sz = land.size();
    vector<vector<int>> dp = vector<vector<int>>(sz,vector<int>(4,0));
    
    for (int i = 0; i < 4; ++i)
        dp[0][i] = land[0][i];
    
    for (int i = 1; i < sz; ++i){
        
        for (int c = 0; c < 4; ++c){
            
            for (int x = 0; x < 4; ++x){
                if(c != x){
                    dp[i][x] = max(dp[i-1][c] + land[i][x], dp[i][x]);
                }
            }
        }
    }
        
    int ans = 0;
    for (int i = 0; i < 4; ++i){
        ans = max(ans,dp[sz-1][i]);
    }
    return ans;
}