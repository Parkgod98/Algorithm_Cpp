#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations){
    vector<int> ans(2);
    multiset<int> ms;
    
    for (string &s : operations){
        char com = s[0];
        
        int k = stoi(s.substr(2));
                
        if(com == 'I'){
            ms.insert(k);
        }
        else{
            if(ms.empty())
                continue;
            if(k == 1){
                auto it = ms.end();
                --it;
                ms.erase(it);
            }
            else{
                ms.erase(ms.begin());
            }
        }

       }
    
    if(ms.empty())
        return {0,0};
    
    auto it = ms.end();
    --it;
    ans[0] = *it;
    ans[1] = *ms.begin();
                   
                
    return ans;
}
