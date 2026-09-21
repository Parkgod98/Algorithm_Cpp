#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Point {
    int y, x;
};

bool IsValid(int y, int x, vector<string> &board){
    int r = board.size();
    int c = board[0].size();
    
    if(y < 0 || y >= r || x < 0 || x >= c || board[y][x] == 'D')
        return false;
    return true;
}

int solution(vector<string> board) {
    int r = board.size();
    int c = board[0].size();

    int sy, sx;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'R') {
                sy = i;
                sx = j;
            }
        }
    }
    
    vector<vector<int>> dist = vector<vector<int>>(r,vector<int>(c,-1));
    queue<Point> q;
    q.push({sy,sx});
    dist[sy][sx] = 0;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int y = it.y;
        int x = it.x;
        
        if(board[y][x] == 'G'){
            return dist[y][x];
        }
        
        for (int d = 0; d < 4; ++d){
            int ny = y;
            int nx = x;
            
            while(IsValid(ny,nx,board)){
                ny += dy[d];
                nx += dx[d];
            }
            ny -= dy[d];
            nx -= dx[d];
            
            if(ny ==y && nx == x)
                continue;
            if(dist[ny][nx] != -1)
                continue;
            
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny,nx});
        }
    }
    
    return -1;
}