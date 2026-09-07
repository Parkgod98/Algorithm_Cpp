#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> ans;
    
    map<string,set<string>> mp;
    
    map<string,int> report_num;
    
    vector<string> res;
    for (string &s : report){
        int idx = s.find(' ');
        
        string me = s.substr(0,idx);
        string tar = s.substr(idx+1);
        
        if(mp[me].find(tar) != mp[me].end())
            continue;
        mp[me].insert(tar);
        if(report_num[tar] >= k)
            continue;
        report_num[tar]++;
        if(report_num[tar] >= k){
            res.push_back(tar);
        }
    }
    
        
    for (string &ss : id_list){
        int cnt = 0;
        for (string &s : res){
            if(mp[ss].find(s) != mp[ss].end())
                ++cnt;
        }
        ans.push_back(cnt);
    }
    return ans;
}