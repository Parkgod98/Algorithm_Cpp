#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long right = 2000000000;
    for (int &n : times){
        right = min((long long)n,right);
    }
    
    right *= n;
    long long left = 0;
    long long ans = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long cur = 0;
        for (int i = 0; i < times.size(); ++i){
            cur += mid/times[i];
            if(cur >= n)
                break;
        }
        
        if(cur < n){
            left = mid + 1;
        }
        else{
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}