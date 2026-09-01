#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    vector<bool> IsPrime(n+1,true);
    IsPrime[0] = IsPrime[1] = false;
    
    for (int i = 2; i * i <= n; ++i){
        for (int j = i*i; j <=n; j+=i)
            IsPrime[j] = false;
    }
    int ans = 0;
    
    for (int i = 1; i <= n; ++i)
        if(IsPrime[i])
            ++ans;
    return ans;
}