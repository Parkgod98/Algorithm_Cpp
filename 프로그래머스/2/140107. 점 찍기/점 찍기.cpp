#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
long long solution(int k, int d) {
    
    ll cnt = 0;
    ll dd = d;
    ll j = (dd/k)*k;
    for (ll i = 0; i <= dd; i += k){
        while(i*i + j * j > dd*dd)
            j -= k;
        
        cnt += j/k + 1;
    }
    
    return cnt;
}