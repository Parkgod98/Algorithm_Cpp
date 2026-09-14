#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
    int sz = want.size();
    
    int ans = 0;
    
    map<string,int> mp;
    map<string,int> true_mp;
    for (int i = 0; i < sz; ++i){
        true_mp[want[i]] = number[i];
    }
    
    for (int i = 0; i < 10; ++i)
        mp[discount[i]]++;

    
    int dsz = discount.size();
    for (int i = 1; i <= dsz-10; ++i){
        
        // for (auto &it : mp){
        //     cout << it.first << " " << it.second << "\n";
        // }
        // cout << "\n";
        bool f = true;
        for (int k = 0; k < sz; ++k){
            if(mp[want[k]] < true_mp[want[k]]){
                f = false;
                break;
            }
        }
        if(f)
            ++ans;
        
        mp[discount[i-1]]--;
        mp[discount[i+10 -1]]++;
    }
    bool f = true;
    
    for (int k = 0; k < sz; ++k){
            if(mp[want[k]] < true_mp[want[k]]){
                f = false;
                break;
            }
        }
    if(f)
        ++ans;
    return ans;
}