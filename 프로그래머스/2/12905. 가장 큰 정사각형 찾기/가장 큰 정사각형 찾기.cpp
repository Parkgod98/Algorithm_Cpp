#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int r = board.size();
    int c = board[0].size();
    
    
    vector<vector<int>> dp(r,vector<int>(c,0));
    int mx = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(board[i][j] == 0)
                continue;
            
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else{
                dp[i][j] = min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}) + 1;
            }
            mx = max(dp[i][j],mx);
        }
    }
    
    return mx*mx;
}