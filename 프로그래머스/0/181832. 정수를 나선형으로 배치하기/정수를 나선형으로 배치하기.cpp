#include <string>
#include <vector>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<vector<int>> solution(int n) {
    vector<vector<int>> ans(n,vector<int>(n,0));
    
    int i = 1;
    
    int sz = n*n;
    
    int y,x;
    y = x = 0;
    int dir = 1;
    while(i <= sz){
        
        ans[y][x] = i++;
        
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || ans[ny][nx] != 0)
            dir = (dir +1)%4;
        
        y = y + dy[dir];
        x = x + dx[dir];
    }
    return ans;
}