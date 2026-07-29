#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    int sz = strlist.size();
    vector<int> ans(sz);
    
    for (int i = 0; i < sz; ++i){
        ans[i] = strlist[i].size();
    }
    return ans;
}