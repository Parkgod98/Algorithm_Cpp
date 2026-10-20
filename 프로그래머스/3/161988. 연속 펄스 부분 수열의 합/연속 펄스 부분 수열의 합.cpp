#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    
    long long mx = 0;
    long long mn = 0;
    int sign = 1;
    
    long long sum = 0;
    for (int &k : sequence){
        sum += k * sign;
        
        mx = max(mx,sum);
        mn = min(mn,sum);
        sign *= -1;
    }
    
    return mx - mn;
}