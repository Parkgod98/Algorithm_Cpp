#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    int dp[502] = {0};
    
    int sz = triangle.size();
    
    dp[0] = triangle[0][0];
    int ans = dp[0];
    for (int i = 1; i < sz; ++i){
        for (int j = i; j >= 0; --j){
            if(i == j){
                dp[j] = dp[j-1] + triangle[i][j];
            }
            else if(j-1 >= 0){
                dp[j] = max(dp[j-1],dp[j]) + triangle[i][j];
            }
            else{
                dp[j] += triangle[i][j];
            }
            ans = max(ans,dp[j]);
        }
    }
    return ans;
}