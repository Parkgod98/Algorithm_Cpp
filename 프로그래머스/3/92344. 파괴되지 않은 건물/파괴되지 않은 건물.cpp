#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int r = board.size();
    int c = board[0].size();
    
    vector<vector<int>> p_sum(r+1,vector<int>(c+1,0));
    for (vector<int> &s : skill){
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int d = (type == 1 ? -s[5] : s[5]);
        
        p_sum[r1][c1] += d;
        p_sum[r1][c2+1] -= d;
        p_sum[r2+1][c1] -=d;
        p_sum[r2+1][c2+1] += d;
    }
    
    for (int i = 0; i < r; ++i){
        for (int j = 1; j < c; ++j){
            p_sum[i][j] += p_sum[i][j-1];
        }
    }
    
    for (int i = 1; i < r; ++i){
        for (int j = 0; j < c; ++j){
            p_sum[i][j] += p_sum[i-1][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(board[i][j] + p_sum[i][j] > 0)
                ++ans;
        }
    }
    return ans;
}