#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct Point{
    int y,x;
};

vector<int> solution(vector<string> maps) {
    int r = maps.size();
    int c = maps[0].size();
    int visited[101][101] = {0};
    vector<int> v;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(maps[i][j] != 'X' && !visited[i][j]){
                queue<Point> q;
                q.push({i,j});
                visited[i][j] = 1;
                int sum = 0;
                
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    
                    int y = it.y;
                    int x = it.x;
                    sum += (maps[y][x] - '0');
                    
                    for (int d = 0; d < 4; ++d){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] || maps[ny][nx] == 'X')
                            continue;
                        
                        q.push({ny,nx});
                        visited[ny][nx] = 1;
                    }
                }
                v.push_back(sum);
            }
        }
    }
    
    if(v.empty())
        return vector<int>(1,-1);
    sort(v.begin(),v.end());
    return v;
}