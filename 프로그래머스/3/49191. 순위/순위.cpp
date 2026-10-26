#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win(n+1,vector<int>(n+1,0));
    
    for (vector<int> &v : results){
        win[v[0]][v[1]] = 1;
    }
    
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if(win[i][k] && win[k][j])
                    win[i][j] = 1;
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 1; i <= n; ++i){
        int cnt = 0;
        
        for (int j = 1; j <= n; ++j){
            if(win[i][j] || win[j][i])
                ++cnt;
        }
        
        if(cnt == n-1)
            ++ans;
    }
    
    return ans;
}