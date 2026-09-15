#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> mp;
    
    for (vector<string> &v : clothes){
        mp[v[1]]++;
    }
    
    int ans = 1;
    for (auto &it : mp){
        ans *= (it.second+1);
    }
    return ans-1;
}