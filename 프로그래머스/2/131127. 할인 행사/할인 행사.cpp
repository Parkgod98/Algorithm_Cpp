#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int sz = want.size();
    
    int ans = 0;
    
    map<string,int> mp;
    for (int i = 0; i < 10; ++i)
        mp[discount[i]]++;
    
    int dsz = discount.size();
    for (int i = 0; i <= dsz-10; ++i){
        bool f = true;
        for (int k = 0; k < sz; ++k){
            if(mp[want[k]] < number[k]){
                f = false;
                break;
            }
        }
        if(f)
            ++ans;
        
        if(i == dsz - 10)
            break;
        
        mp[discount[i]]--;
        mp[discount[i+10]]++;
    }
    return ans;
}