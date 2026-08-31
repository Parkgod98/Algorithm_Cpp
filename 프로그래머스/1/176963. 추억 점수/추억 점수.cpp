#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string,int> mp;
    for (int i = 0; i < name.size(); ++i){
        mp[name[i]] = yearning[i];
    }
    
    vector<int> ans;
    for (vector<string> &v : photo){
        
        int sum = 0;
        for (string &s : v){
            if(mp.find(s) != mp.end())
                sum += mp[s];
        }
        ans.push_back(sum);
    }
    return ans;
}