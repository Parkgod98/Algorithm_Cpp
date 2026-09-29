#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dy[3] = {1,0,-1};
int dx[3] = {-1,1,0};

vector<int> solution(int n) {
    vector<int> ans;
    
    int cnt = n;
    int arr[3000][3000] = {0};
    
    int r,c;
    r = c = 1500;
    
    int dir = 0;
    int num = 1;
    while(cnt != 0){
        for (int i = 0; i < cnt; ++i){
            arr[r][c] = num++;
            if(i != cnt - 1){
                r += dy[dir];
                c += dx[dir];
            }
        }
        dir = (dir+1)%3;
        r += dy[dir];
        c += dx[dir];
        --cnt;
    }
    
    for (int i = 0; i < 3000; ++i){
        for (int j = 0; j < 3000; ++j){
            if(arr[i][j] != 0){
                ans.push_back(arr[i][j]);
            }
        }
    }
    
    return ans;
}