#include <string>
#include <vector>
#include <iostream>
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
using namespace std;

int solution(int n, int w, int num) {
    // w*0 + 1  ~ w
    // w*1 + 1 ~ 2*w
    // w*2 + 1 ~ 3w

    //
    int mx = n / w + 1;

    vector<vector<int>> ans = vector<vector<int>>(mx, vector<int>(w));

    int start = 1;
    int y = 0;
    int x = 0;
    int dir = 1;
    
    int ty,tx;

    while (start <= n) {
        if(start == num){
            ty = y;
            tx = x;
        }
        ans[y][x] = start++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= mx || nx < 0 || nx >= w) {
            if (dir == 1) {
                dir = 3;
                y += 1;
            }
            else {
                dir = 1;
                y += 1;
            }
            continue;
        }
        y = ny;
        x = nx;
    }

    // for (int i = 0; i < mx; ++i){
    //     for (int j = 0; j < w; ++j)
    //         cout << ans[i][j] << " ";
    //     cout << "\n";
    // }

//     int idx = -1;
//     for (int i = 0; i <= mx; ++i){
//         if(w*i +1 <= num && num <= w*(i+1)){
//             idx = i;
//             break;
//         }
//     }

//     if(n%w != 0){
//         return mx+1 - idx;
//     }
//     else{
//         return mx+1 - idx;
//     }
    
    int cnt = 0;
    for (int y = mx-1; y >= ty; --y){
        if(ans[y][tx] != 0)
            ++cnt;
    }

    return cnt;
}