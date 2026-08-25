#include <string>
#include <vector>

using namespace std;

int dy[8] = {-1,-1,-1,0,1,1,1,0};
int dx[8] = {-1,0,1,1,1,0,-1,-1};

int solution(vector<vector<int>> board) {
    int sz = board.size();
    
    vector<vector<int>> visited(sz,vector<int>(sz,0));
    
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            if(board[i][j] == 1){
                visited[i][j] = 2;
                for (int d = 0; d < 8; ++d){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if(ny < 0 || ny >= sz || nx < 0 || nx >= sz)
                        continue;
                    visited[ny][nx] = 2;
                }
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < sz; ++i){
        for (int j = 0; j < sz; ++j){
            if(visited[i][j] == 2)
                ++cnt;
        }
    }
    
    
    return sz*sz - cnt;
}