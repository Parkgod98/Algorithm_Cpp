#include <string>
#include <vector>
#define INF 999999999

using namespace std;

int ans;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void DFS(int y, int x, vector<vector<int>> &board, vector<vector<int>> &visited, int cost, int prev_dir, vector<vector<vector<int>>> &dp){
    if(cost > dp[y][x][prev_dir]){
        return;
    }
    dp[y][x][prev_dir] = cost;
    if(cost >= ans)
        return;
    if(y == board.size()-1 && x == board.size() -1){
        ans = min(ans,cost);
        return;
    }
    
    for (int d = 0; d < 4; ++d){
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size() || visited[ny][nx])
            continue;
        if(board[ny][nx] == 1)
            continue;
        
        visited[ny][nx] = 1;
        if(prev_dir == -1){
            DFS(ny,nx,board,visited,cost+100,d,dp);
        }
        else{
            if(prev_dir != d){
                DFS(ny,nx,board,visited,cost+600,d,dp);
            }
            else{
                DFS(ny,nx,board,visited,cost+100,d,dp);
            }
        }
        visited[ny][nx] = 0;
    }
}

int solution(vector<vector<int>> board) {
    ans = INF;
    
    vector<vector<int>> visited(board.size(),vector<int>(board.size(),0));
    vector<vector<vector<int>>> dp(board.size(),vector<vector<int>>(board.size(),vector<int>(4,INF)));
    
    DFS(0,0,board,visited,0,-1,dp);
    
    return ans;
}