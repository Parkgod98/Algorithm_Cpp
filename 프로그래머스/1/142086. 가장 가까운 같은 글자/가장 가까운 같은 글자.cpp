#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> ans(26,-1);
    
    vector<int> prev(s.size(),-1);
    int sz = s.size();
    for (int i = 0; i < sz; ++i){
        if(ans[s[i]-'a'] != -1){
            prev[i] = i - ans[s[i] -'a'];
        }
        ans[s[i]-'a'] = i;

    }
    return prev;
}