#include <string>
#include <vector>

using namespace std;

bool SameIncline(vector<vector<int>> &dots, int visited[4]){
    
    int y1,y2,x1,x2;
    y1 = y2 = x1 = x2 = -1;
    
    int ty1,ty2,tx1,tx2;
    ty1 = ty2 = tx1 = tx2 = -1;
    
    for (int i = 0; i < 4; ++i){
        if(visited[i]){
            if(y1 == -1){
                x1 = dots[i][0];
                y1 = dots[i][1];
            }
            else{
                x2 = dots[i][0];
                y2 = dots[i][1];
            }
        }
        else{
            if(ty1 == -1){
                tx1 = dots[i][0];
                ty1 = dots[i][1];
            }
            else{
                tx2 = dots[i][0];
                ty2 = dots[i][1];
            }
        }
    }
    
    if((y2 - y1) * (tx2-tx1) == (x2-x1) *(ty2 - ty1) )
        return true;
    return false;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int visited[4] = {0};
    for (int i = 0; i < 4; ++i){
        visited[i] = 1;
        for (int j = i + 1; j < 4; ++j){
            visited[j] = 1;
            if(SameIncline(dots,visited))
                return 1;
            visited[j] = 0;
        }
        visited[i] = 0;
        break;
    }
    return 0;
}