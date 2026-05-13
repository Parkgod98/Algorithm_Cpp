#include <bits/stdc++.h>
using namespace std;
int n, b;
 
const int MXN = 21;
int a[MXN];
 
const int MXA = 10'005;
int ans = MXN * MXA;
 
void dfs(int k, int tot) {
    if(ans == b) {
        return;
    }
 
    if(tot >= ans) {
        return;
    }
 
    if(tot >= b) {
        ans = min(ans, tot);
        return;
    }
 
    if(k == n) {
        return;
    }
 
    dfs(k+1, tot);
    dfs(k+1, tot+a[k]);
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    // freopen("input.txt", "r", stdin);
 
    int t; cin >> t;
    for(int test_case = 1; test_case <= t; ++test_case)  {
        cin >> n >> b;
        for(int i = 0; i < n; i++) cin >> a[i];
         
        ans = MXN * MXA;
        dfs(0,0);
        cout << "#" << test_case << " " << ans - b << "\n";
    }
}