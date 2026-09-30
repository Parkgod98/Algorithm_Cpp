#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct Point{
    int y,x;
};

vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    for (vector<string> &v : places){
        
        
        bool Find = false;
        for (int i = 0; i < 5; ++i){
            if(Find)
                break;
            for (int j = 0; j < 5; ++j){
                if(v[i][j] == 'P'){
                    vector<vector<int>> visited(5,vector<int>(5,0));
                    
                    queue<Point> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        
                        int y = it.y;
                        int x = it.x;
                        
                        for (int d = 0; d < 4; ++d){
                            int ny = y + dy[d];
                            int nx = x + dx[d];
                            
                            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx] || v[ny][nx] == 'X')
                                continue;
                            
                            q.push({ny,nx});
                            visited[ny][nx] = visited[y][x] + 1;
                            
                            if(v[ny][nx] == 'P' && visited[ny][nx] <= 3){
                                Find = true;
                                break;
                            }
                        }
                        if(Find)
                            break;
                    }
                    if(Find)
                        break;
                }
            }
        }
        if(Find)
            ans.push_back(0);
        else
            ans.push_back(1);
    }
    
    return ans;
}