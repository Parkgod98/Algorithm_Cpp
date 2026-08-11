#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if(i + j <= k){
                answer += board[i][j];
            }
        }
    }
    return answer;
}