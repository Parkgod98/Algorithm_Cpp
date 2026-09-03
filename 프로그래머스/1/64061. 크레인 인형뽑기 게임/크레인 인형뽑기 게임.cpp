#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int cnt = 0;
    stack<int> st[32];
    int sz = board.size();
    
    for (int i = 0; i < sz; ++i){
        for (int j = sz-1; j >= 0; --j){
            if(board[j][i] !=0)
                st[i+1].push(board[j][i]);
        }
    }
        
    stack<int> basket;
    for (int &n : moves){
        if(!st[n].empty()){
            if(!basket.empty()){
                if(st[n].top() == basket.top()){
                    cnt += 2;
                    basket.pop();
                }
                else{
                    basket.push(st[n].top());
                }
                st[n].pop();
            }
            else{
                basket.push(st[n].top());
                st[n].pop();
            }
        }
    }
    cout << basket.size() << "\n";
    return cnt;
}