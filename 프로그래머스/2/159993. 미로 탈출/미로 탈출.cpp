#include <string>
#include <vector>
#include <queue>
#include <iostream>

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

using namespace std;

struct Point{
    int y,x;
};

int solution(vector<string> maps) {
    
    int r = maps.size();
    int c = maps[0].size();
    vector<vector<char>> v(r,vector<char>(c));
    
    
    int sy,sx;
    int ly,lx;
    int ey,ex;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            v[i][j] = maps[i][j];
            if(v[i][j] == 'S'){
                sy = i;
                sx = j;
            }
            else if(v[i][j] == 'L'){
                ly = i;
                lx = j;
            }
            else if(v[i][j] == 'E'){
                ey = i;
                ex = j;
            }
        }
    }
    
//     cout << sy << " " << sx << "\n";
//     cout << ly << " " << lx << "\n";
//     cout << ey << " " << ex << "\n";
    
    
    queue<Point> q;
    q.push({sy,sx});
    vector<vector<int>> visited(r,vector<int>(c,0));
    visited[sy][sx] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        int y = it.y;
        int x = it.x;
        
        for (int d = 0; d < 4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx])
                continue;
            if(v[ny][nx]=='X')
                continue;
            
            q.push({ny,nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    
    queue<Point> q2;
    q2.push({ly,lx});
    vector<vector<int>> visited2(r,vector<int>(c,0));
    visited2[ly][lx] = 1;
    
    while(!q2.empty()){
        auto it = q2.front();
        q2.pop();
        
        int y = it.y;
        int x = it.x;
        
        for (int d = 0; d < 4; ++d){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited2[ny][nx])
                continue;
            if(v[ny][nx]=='X')
                continue;
            
            q2.push({ny,nx});
            visited2[ny][nx] = visited2[y][x] + 1;
        }
    }
    
    if(visited[ly][lx] == 0 || visited2[ey][ex] == 0)
        return -1;
    
    return visited[ly][lx] + visited2[ey][ex] - 2;
}