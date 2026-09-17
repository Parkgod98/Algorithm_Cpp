#include <string>
#include <vector>
#define INF 99999999

using namespace std;

void DFS(int x, int y, int cnt, vector<int> &dp, int n){
    dp[x] = cnt;
    
    if(x%2 == 0 && dp[x/2] > cnt+1){
        DFS(x/2,y,cnt+1,dp,n);
    }
    if(x%3 == 0 && dp[x/3] > cnt+1){
        DFS(x/3,y,cnt+1,dp,n);
    }
    if(x - n >= y && dp[x-n] > cnt+1){
        DFS(x-n,y,cnt+1,dp,n);
    }
}

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(y+1,INF);
    DFS(y,x,0,dp,n);
    
    if(dp[x]== INF)
        return -1;
    return dp[x];
}