#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int,int> mp;
    map<int,int> mp2;
    for (int &n : topping)
        mp[n]++;
    
    int ans = 0;
    int sz = topping.size();
    for (int i = 0; i < sz; ++i){
        mp2[topping[i]]++;
        
        mp[topping[i]]--;
        if(mp[topping[i]] == 0){
            mp.erase(topping[i]);
        }
        
        if(mp2.size() == mp.size())
            ++ans;
    }
    return ans;
}