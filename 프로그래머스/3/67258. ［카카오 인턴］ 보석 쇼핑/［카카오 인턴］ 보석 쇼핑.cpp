#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string,int> mp;
    
    int id = 0;
    for (string &s : gems){
        if(mp.find(s) == mp.end()){
            mp[s] = id++;
        }
    }
    
    vector<int> cnt(id,0);
    set<string> st;
    int s,e;
    s = e = 0;
    
    st.insert(gems[s]);
    cnt[mp[gems[s]]]++;
        
    int mx_sz = 200000;
    int as,ae;
    while(s < gems.size() && e < gems.size()){
        if(st.size() < mp.size()){
            ++e;
            if(e < gems.size()){
                st.insert(gems[e]);
                cnt[mp[gems[e]]]++;
            }
        }
        else {
            if(e-s < mx_sz){
                mx_sz = e-s;
                as = s;
                ae = e;
            }
            cnt[mp[gems[s]]]--;
            if(cnt[mp[gems[s]]] == 0){
                auto it = st.find(gems[s]);
                st.erase(it);
            }
            ++s;
        }
    }
    
    vector<int> ans(2,0);
    ans[0] = as+1;
    ans[1] = ae+1;
    return ans;
}