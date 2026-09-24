#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
O X O
X O O
X O X
*/

int solution(vector<string> board) {
    int o_cnt = 0;
    int x_cnt = 0;
    
    for (string &s : board){
        for (char &c : s){
            if(c == 'O')
                o_cnt++;
            else if(c == 'X')
                x_cnt++;
        }
    }
    
    bool o_win = false;
    bool x_win = false;
    for (int i = 0; i < 3; ++i){
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
            o_win = true;
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
            x_win = true;
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            o_win = true;
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
            x_win = true;
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            o_win = true;
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            x_win = true;
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            x_win = true;
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            o_win = true;
    }
    
    cout << o_win << " " << x_win << "\n";
    cout << o_cnt << " " << x_cnt << "\n";
    
    if(x_cnt > o_cnt || (o_cnt - x_cnt >= 2) || (o_win && x_win) || (o_win && (o_cnt == x_cnt)) || (x_win && (o_cnt > x_cnt)))
        return 0;
    
    return 1;
}