#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Point{
    int y,x;
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void Bomb(int mode, char tar, vector<vector<char>> &v){
    queue<Point> r_list;
    vector<vector<int>> visited = vector<vector<int>>(v.size(),vector<int>(v[0].size()));
    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v[0].size(); ++j){
            if(!visited[i][j] && v[i][j] == '0'){
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
                        if(ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size() || visited[ny][nx])
                            continue;
                        if(v[ny][nx] == '0' || v[ny][nx] == '1'){
                            q.push({ny,nx});
                            visited[ny][nx] = 1;
                            v[ny][nx] = '0';
                        }
                    }
                }
            }
        }
    }
    
    if(mode == 1){
        for (int i = 0; i < v.size(); ++i){
            for (int j = 0; j < v[0].size(); ++j){
                if(visited[i][j] != 2 && v[i][j] == '0'){
                    queue<Point> q;
                    q.push({i,j});
                    visited[i][j] = 2;
                    
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        
                        int y = it.y;
                        int x = it.x;
                        
                        for (int d = 0; d < 4; ++d){
                            int ny = y + dy[d];
                            int nx = x + dx[d];
                            if(ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size() || visited[ny][nx])
                                continue;
                            if(v[ny][nx] == '0'){
                                q.push({ny,nx});
                                visited[ny][nx] = 2;
                            }
                            else if(v[ny][nx] == tar){
                                r_list.push({ny,nx});
                            }
                        }
                        
                    }
                }
            }
        }
    }
    else{
        for (int i = 0; i < v.size(); ++i){
            for (int j = 0; j < v[0].size(); ++j){
                if(visited[i][j] != 2 && v[i][j] == '0'){
                    queue<Point> q;
                    q.push({i,j});
                    visited[i][j] = 2;
                    
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        
                        int y = it.y;
                        int x = it.x;
                        
                        for (int d = 0; d < 4; ++d){
                            int ny = y + dy[d];
                            int nx = x + dx[d];
                            if(ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size() || visited[ny][nx])
                                continue;
                            if(v[ny][nx] == '0'){
                                q.push({ny,nx});
                                visited[ny][nx] = 1;
                            }
                            else if(v[ny][nx] == tar){
                                r_list.push({ny,nx});
                            }
                        }
                    }
                }
            }
        }
        
        while(!r_list.empty()){
            auto it = r_list.front();
            r_list.pop();
            
            v[it.y][it.x] = '0';
        }
        for (int i = 0; i < v.size(); ++i){
            for (int j = 0; j < v[0].size(); ++j){
                if(v[i][j] == tar){
                    v[i][j] = '1';
                }
            }
        }
        
        
    }
    while(!r_list.empty()){
        auto it = r_list.front();
        r_list.pop();

        v[it.y][it.x] = '0';
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int ans = 0;
    int r = storage.size() + 2;
    int c = storage[0].size() + 2;
    vector<vector<char>> v = vector<vector<char>>(r,vector<char>(c,'0'));
    
    for (int i = 1; i < r - 1; ++i){
        for (int j = 1; j < c- 1; ++j){
            v[i][j] = storage[i-1][j-1];
        }
    }
    
    
    for (string &s : requests){
        Bomb((int)s.size(),s[0],v);
    }
    
    for (vector<char> &vv : v){
        for (char &c : vv){
            if(c != '0' && c != '1')
                ++ans;
        }
    }
    return ans;
}