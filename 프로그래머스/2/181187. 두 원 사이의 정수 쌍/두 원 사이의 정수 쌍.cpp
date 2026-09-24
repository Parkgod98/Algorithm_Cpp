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
    for (ll i = 1; i < r2; ++i){
        
        while(!(i*i + j*j <= rr2*rr2))
            --j;
        
        ll start = 1;
        if(i < r1)
            start = (ll)(ceil(sqrt(rr1*rr1 - i*i)));
        
        cnt += (j-start) +1;
    }
    
    cnt*=4;
    cnt += (r2-r1+1)*4 ;
    return cnt;
}