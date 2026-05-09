#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<string> map(50);
 
int main() {
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
        int n, m;
        cin>>n>>m;
        vector<vector<int> > CNT(n, vector<int>(3, 0));
        int dp[n+1][n+1];
 
        for(int i=0; i<n; i++) {
            int w=0, b=0, r=0;
            cin>>map[i];
            for(int j=0; j<m; j++) {
                if(map[i][j]=='W') w++;
                else if(map[i][j]=='B') b++;
                else r++;
            }
            CNT[i][0]=m-w;
            CNT[i][1]=m-b;
            CNT[i][2]=m-r;
        }
         
        int res=CNT[0][0]+CNT[n-1][2];
        int min_res=2147000000;
 
        for(int i=1; i<n-1; i++) {
            int tmp=0;
            for(int j=1; j<i; j++) {
                tmp+=CNT[j][0];
            }
            tmp+=CNT[i][1];
            for(int j=i+1; j<n-1; j++) {
                tmp+=CNT[j][2];
            }
            dp[i][i]=tmp;
            min_res=min(min_res, dp[i][i]);
        }
 
        for(int i=1; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                dp[i][j]=dp[i][j-1]-CNT[j][2]+CNT[j][1];
                min_res=min(min_res, dp[i][j]);
            }
        }
 
        cout<<"#"<<test_case<<" "<<min_res+res<<"\n";
 
    }
 
    return 0;
}