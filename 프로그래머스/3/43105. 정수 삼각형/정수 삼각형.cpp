#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int ans = 0;
    
    int dp[502][502] = {0};
    
    int sz = triangle.size();
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < sz; ++i){
        
        for (int j = 0; j < i + 1; ++j){
            if(j-1 >= 0){
                dp[i][j] = max(dp[i][j],max(dp[i-1][j-1] + triangle[i][j],dp[i-1][j] + triangle[i][j]));
            }
            else{
                dp[i][j] = max(dp[i-1][j] + triangle[i][j],dp[i][j]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}