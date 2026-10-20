#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    int sign = 1;
    for (int i = 0; i < sequence.size(); ++i){
        sequence[i] *= sign;
        sign *= -1;
    }
    
    vector<long long> p_sum(sequence.size()+1);
    
    for (int i = 1; i < p_sum.size(); ++i){
        p_sum[i] = p_sum[i-1] + sequence[i-1];
    }

    long long mx = -(long long)100000*500000;
    long long mn = (long long)100000*500000;
    
    for (int i = 0; i < p_sum.size(); ++i){
        mn = min(p_sum[i],mn);
        mx = max(p_sum[i],mx);
    }
    long long ans = -(long long)100000*500000;
    ans = max(mx-mn,ans);

    
    return ans;
}