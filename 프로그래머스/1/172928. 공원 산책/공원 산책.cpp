#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int y,x;
    y = x = -1;
    
    int r = park.size();
    int c = park[0].size();
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(park[i][j] == 'S'){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1)
            break;
    }
    
    map<char,int> dd = {{'N',0},{'E',1},{'S',2},{'W',3}};
        
    for (string &s : routes){
        char dir = s[0];
        int shift = s[2] - '0';
        
        bool f = true;
        for (int i = 1; i <= shift; ++i){
            int ny = y + i*dy[dd[dir]];
            int nx = x + i*dx[dd[dir]];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || park[ny][nx] == 'X'){
                f = false;
                break;
            }
        }
        if(!f)
            continue;
        
        y = y + shift*dy[dd[dir]];
        x = x + shift*dx[dd[dir]];
    }
    vector<int> ans = {y,x};
    return ans;
}