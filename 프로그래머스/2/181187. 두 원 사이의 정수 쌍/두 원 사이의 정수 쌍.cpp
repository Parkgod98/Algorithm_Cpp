#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

long long solution(int r1, int r2) {
    ll cnt = 0;
    
    ll j = r2+1;
    
    ll rr1 = r1;
    ll rr2 = r2;
    for (ll i = 1; i <= r2; ++i){
        
        ll mx_y = floor(sqrt(rr2*rr2 - i*i));
        
        ll mn_y = 0;
        if(rr1 >= i)
            mn_y = ceil(sqrt(rr1*rr1 - i*i));
        
        cnt += (mx_y - mn_y)+1;
    }
    
    cnt*=4;
    return cnt;
}