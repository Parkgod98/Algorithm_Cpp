#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string,int> mp;
    
    for (string &s : gems){
        mp[s] = 0;
    }
    
    int s,e;
    s = e = 0;
    
    mp[gems[0]]++;
    
    int kind = 1;
        
    int mx_sz = 200000;
    int as,ae;
    while(s < gems.size() && e < gems.size()){
        if(kind < mp.size()){
            ++e;
            if(e < gems.size()){
                if(mp[gems[e]] == 0){
                    ++kind;
                }
                mp[gems[e]]++;
            }
        }
        else {
            if(e-s < mx_sz){
                mx_sz = e-s;
                as = s;
                ae = e;
            }
            mp[gems[s]]--;
            if(mp[gems[s]] == 0){
                --kind;
            }
            ++s;
        }
    }
    
    vector<int> ans(2,0);
    ans[0] = as+1;
    ans[1] = ae+1;
    return ans;
}