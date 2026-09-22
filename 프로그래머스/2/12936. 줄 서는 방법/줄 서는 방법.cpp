#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    --k;
    vector<int> ans;
    
    vector<int> v;
    for (int i = 1; i <= n; ++i) // 재료 생성.
        v.push_back(i);
    
    long long total = 1;
    for (int i = 1; i <= n; ++i){
        total *= i;
    }
    while(!v.empty()){
        long long step = total/n;
        
        total /= n;
        n--;
        
        long long block = k/step;
        
        ans.push_back(v[block]);
        v.erase(v.begin() + block);
        k %= total;
    }
    
    return ans;
    
}