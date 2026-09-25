#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define UPPER 10000000

long long GetDiv(long long n){
    
    int ans = 1;
    for (long long i = 2; i * i <= n; ++i){
        if(n%i == 0){
            if(n/i <= UPPER)
                return n/i;
            
            ans = i;
        }
    }
    
    return ans;
}
vector<int> solution(long long begin, long long end) {
    vector<int> ans(end - begin +1, 0);
    
    for (int i = end; i >= begin; --i){
        ans[i-begin] = GetDiv(i);
    }
    if(begin == 1)
        ans[0] = 0;

    
    return ans;
}