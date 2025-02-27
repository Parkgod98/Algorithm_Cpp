#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int sum = 0;
    for (int i = 0; i < board.size(); ++i) {
        if (i > k)
            continue;
        for (int j = 0; j < board[i].size(); ++j) {
            if (i + j > k)
                continue;
                sum += board[i][j];
        }
    }
    return sum;
}