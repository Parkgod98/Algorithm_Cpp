#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
    
    vector<bool> IsPrime(3002,true);
    IsPrime[0] = IsPrime[1] = false;
    
    for (int i = 2; i * i <= 3001; ++i){
        if(!IsPrime[i])
            continue;
        for (int j = i*i; j <= 3001; j+=i)
            IsPrime[j] = false;
    }
    
    int sz = nums.size();
    
    int ans = 0;
    for (int i = 0; i < sz; ++i){
        for (int j = i + 1; j < sz; ++j){
            for (int k = j + 1; k < sz; ++k){
                if(IsPrime[nums[i] + nums[j] + nums[k]])
                    ++ans;
            }
        }
    }

    return ans;
}