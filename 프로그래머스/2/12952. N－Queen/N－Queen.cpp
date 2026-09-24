#include <string>
#include <vector>

using namespace std;
int cnt = 0;

void DFS(int n, vector<vector<int>> &v, int r){
    if(r == n){
        ++cnt;
        return;
    }
    
    
    for (int i = 0; i < n; ++i){
        bool f = false;
        for (int rr = r - 1; rr >= 0; --rr){
            if(v[rr][i] == 1){
                f = true;
                break;
            }
            if(f)
                break;
            for (int j = 0; j < n; ++j){
                if(j != i && v[rr][j] == 1){
                    if(abs(r-rr) == (abs(j-i))){
                        f = true;
                        break;
                    }
                }
            }
            if(f)
                break;
        }
        
        if(f)
            continue;
        v[r][i] = 1;
        DFS(n,v,r+1);
        v[r][i] = 0;
    }
}

int solution(int n) {
    
    vector<vector<int>> v(n,vector<int>(n,0));
    
    DFS(n,v,0);
    
    return cnt;
}