#include <string>
#include <vector>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int solution(vector<vector<string>> board, int h, int w) {
    int ans = 0;
    
    string s = board[h][w];
    
    for (int d = 0; d < 4; ++d){
        int ny = h + dy[d];
        int nx = w + dx[d];
        
        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            continue;
        if(board[ny][nx] == s)
            ++ans;
    }
    return ans;
}