#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct Point{
    int y,x;
};

int solution(vector<vector<int> > maps)
{
    
    int r = maps.size();
    int c = maps[0].size();
    
    vector<vector<int>> visited(r,vector<int>(c,0));
    
    queue<Point> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int y = it.y;
        int x = it.x;
        
        for (int d = 0; d < 4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] || maps[ny][nx] == 0)
                continue;
            
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    
    return visited[r-1][c-1] == 0 ? -1 : visited[r-1][c-1];
}