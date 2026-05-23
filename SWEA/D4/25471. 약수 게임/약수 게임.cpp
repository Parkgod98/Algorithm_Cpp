#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    for(long long n; t--; ) {
        cin >> n;
         
        int ans = 0;
        if(n == 1) ans = 0;
        else if(__builtin_popcountll(n) == 1) {
            for(int i = 0; i < 64; ++i) {
                if((1LL << i) & n) {
                    ans = (i & 1 ^ 1);
                    break;
                }
            }
        }
        else ans = (n & 1 ^ 1);
 
        cout << "BA"[ans] << '\n';
    }
 
 
    return 0;
}