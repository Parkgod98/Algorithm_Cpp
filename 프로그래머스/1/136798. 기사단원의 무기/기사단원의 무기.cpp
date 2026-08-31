#include <string>
#include <vector>

using namespace std;

int CountYak(int n){
    int cnt = 0;
    
    for (int i = 1; i * i <= n; ++i){
        if(n%i == 0){
            if(n/i == i)
                cnt += 1;
            else
                cnt+=2;
        }
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int ans = 0;
    
    for (int i = 1; i <= number; ++i){
        
        int k = CountYak(i);
        if(limit < k)
            ans += power;
        else
            ans += k;
    }
    return ans;
}