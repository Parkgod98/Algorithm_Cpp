#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
long long solution(int k, int d) {
    
    ll cnt = 0;
    ll dd = d;
    for (ll i = 0; i <= dd; i += k){
        ll kk = dd*dd - i*i;
        cnt += (long long)sqrt(kk)/(long long)k + 1;
    }
    
    return cnt;
}