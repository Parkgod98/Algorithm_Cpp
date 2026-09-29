#include <string>
#include <vector>
using namespace std;

int dy[3] = {1,0,-1};
int dx[3] = {0,1,-1};

vector<int> solution(int n) {
    vector<int> ans;
    vector<vector<int>> arr(n,vector<int>(n,0));

    int cnt = n;
    int r = 0, c = 0;
    int dir = 0;
    int num = 1;

    while(cnt != 0){
        for(int i=0;i<cnt;++i){
            arr[r][c] = num++;

            if(i != cnt-1){
                r += dy[dir];
                c += dx[dir];
            }
        }

        dir = (dir+1)%3;
        r += dy[dir];
        c += dx[dir];
        --cnt;
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            ans.push_back(arr[i][j]);
        }
    }

    return ans;
}