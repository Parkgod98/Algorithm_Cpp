#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int solution(string dirs) {
    int ans = 0;
    
    
    int y = 5;
    int x = 5;
    vector<vector<vector<int>>> v = vector<vector<vector<int>>>(12,vector<vector<int>>(12,vector<int>(4,0)));
    
    for (char &c : dirs){
        int d = 0;
        if(c == 'U'){
            d = 0;
        }
        else if(c == 'R'){
            d = 1;
        }
        else if(c == 'D'){
            d = 2;
        }
        else{
            d = 3;
        }
        
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if(ny < 0 || ny > 10 || nx < 0 || nx > 10)
            continue;
        
        if(!v[y][x][d] && !v[ny][nx][(d+2)%4])
            ++ans;
        
        v[y][x][d] = v[ny][nx][(d+2)%4] = 1;
        
        y = ny;
        x = nx;
    }
    return ans;
}