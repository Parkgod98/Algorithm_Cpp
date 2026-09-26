#include <string>
#include <vector>
#include <stack>
using namespace std;


void Down(vector<string> &board){
    int r = board.size();
    int c = board[0].size();
    
    
    for (int j = 0; j < c; ++j){
        stack<char> st;
        for (int i = 0; i < r; ++i){
            if(board[i][j] != 'X'){
                st.push(board[i][j]);
            }
        }
        
        int start = r - 1;
        while(!st.empty()){
            board[start][j] = st.top();
            st.pop();
            --start;
        }
        while(start >= 0){
            board[start][j] = 'X';
            --start;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int ans = 0;
    
    
    
    vector<vector<int>> visited(m,vector<int>(n,0));
    int visited_token = 1;
    
    while(1){
        bool Find = false;
        for (int i = 0; i < m-1; ++i){
            for (int j = 0; j < n-1; ++j){

                char start = board[i][j];
                if(start == 'X')
                    continue;
                bool f = true;
                for (int y = i; y < i + 2; ++y){
                    for (int x = j; x < j + 2; ++x){
                        if(start != board[y][x]){
                            f = false;
                            break;
                        }
                    }
                    if(!f)
                        break;
                }

                if(f){
                    Find = true;
                    for (int y = i; y < i + 2; ++y){
                        for (int x = j; x < j + 2; ++x){
                            visited[y][x] = visited_token;
                        }
                    }   
                }
            }
        }
        
        if(Find){
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    if(visited[i][j] == visited_token){
                        board[i][j] = 'X';
                        ++ans;
                    }
                }
            }
            ++visited_token;
            Down(board);
        }
        else{
            break;
        }
        
    }
    return ans;
}