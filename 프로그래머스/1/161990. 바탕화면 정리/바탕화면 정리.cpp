#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int ly,lx,ry,rx;
    ly = 999;
    lx = 999;
    ry = -1;
    rx = -1;
    
    int r = wallpaper.size();
    int c = wallpaper[0].size();
    
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(wallpaper[i][j] == '#'){
                ly = min(ly,i);
                lx = min(lx,j);
                ry = max(ry,i);
                rx = max(rx,j);
            }
        }
    }
    
    vector<int> ans;
    ans.push_back(ly);
    ans.push_back(lx);
    ans.push_back(ry+1);
    ans.push_back(rx+1);
    
    return ans;
}