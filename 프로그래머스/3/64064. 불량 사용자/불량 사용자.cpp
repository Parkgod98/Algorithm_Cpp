#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int ans;
map<string,vector<int>> mp;
int cc[1002] = {0};

void Solve(int depth, vector<string> &banned_id, int mask){
    if(depth == banned_id.size()){
        if(cc[mask] == 0){
            cc[mask] = 1;
            ++ans;
        }
        return;
    }
    
    for (int &idx : mp[banned_id[depth]]){
        if(((1 << idx) & (mask)))
            continue;
        Solve(depth+1,banned_id, mask | ((1 << idx)));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    ans = 0;
    int sz = user_id.size();
    mp.clear();
    
    for (string &s : banned_id){
        if(mp.find(s) != mp.end())
            continue;
        for (int i = 0; i < sz; ++i){
            if(s.size() != user_id[i].size())
                continue;
            
            bool can = true;
            for (int k = 0; k < s.size(); ++k){
                if(s[k] == '*')
                    continue;
                if(user_id[i][k] != s[k]){
                    can = false;
                    break;
                }
            }
            
            if(can)
                mp[s].push_back(i);
        }
    }
    
    Solve(0,banned_id,0);
    
    return ans;
}