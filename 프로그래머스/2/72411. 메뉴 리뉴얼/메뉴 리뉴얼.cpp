#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void DFS(string &s, int n, map<string,int> &mp, string &ans, int cur){
    if(ans.size() == n){
        mp[ans]++;
        return;
    }
    
    for (int i = cur; i < s.size(); ++i){
        ans += s[i];
        DFS(s,n,mp,ans,i+1);
        ans.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for (string &s : orders){
        sort(s.begin(),s.end());
    }
    
    map<string,int> mp;
    for (int &n : course){
        for (string &s : orders){
            string ans = "";
            DFS(s,n,mp, ans,0);
        }
    }
    
    vector<string> ans;
    for (int &n : course){
        int mx = 0;
        
        for (auto &it : mp){
            if(it.first.size() == n && it.second >= 2 && it.second > mx){
                mx = it.second;
            }
        }
        for (auto &it : mp){
            if(mx == it.second && it.first.size() == n){
                ans.push_back(it.first);
            }
        }
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
}