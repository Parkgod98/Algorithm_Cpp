#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> ans;
    
    for (long long &n : numbers){
        if(n%2 == 0)
            ans.push_back(n+1);
        else{
            ll c = n;
            int cnt = 0;
            while((c & 1) == 1){
                c = (c >> 1);
                ++cnt;
            }
            n = (n | (1LL << cnt));
            n = n & ~((1LL << (cnt - 1)));
            ans.push_back(n);
        }
        
    }
    return ans;
}