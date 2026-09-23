#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

struct Point{
    int y,x;
};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};


int solution(vector<vector<int>> land) {
    int r = land.size();
    int c = land[0].size();
    
    int color = 1;
    vector<vector<int>> visited = vector<vector<int>>(r,vector<int>(c,0));
    vector<int> c_list(c+1,0);
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(land[i][j] > 0 && !visited[i][j]){
                queue<Point> q;
                q.push({i,j});
                visited[i][j] = color;
                int cnt = 0;
                
                vector<int> used(c,0);
                
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    ++cnt;
                    
                    int y = it.y;
                    int x = it.x;
                    used[x] = 1;
                    for (int d = 0; d < 4; ++d){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] || land[ny][nx] == 0)
                            continue;
                        q.push({ny,nx});
                        visited[ny][nx] = color;
                    }
                }
                for (int k = 0; k < c; ++k)
                    if(used[k])
                        c_list[k]+=cnt;
                ++color;
            }
        }
    }
    
    int mx = 0;
    for (int i = 0; i < c; ++i){
        mx = max(c_list[i],mx);
    }
    
    return mx;
}