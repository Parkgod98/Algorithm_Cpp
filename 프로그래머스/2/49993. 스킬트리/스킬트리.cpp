#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    
    vector<int> parent(26,-1);
    
    int sz = skill.size();
    for (int i = 1; i < sz; ++i){
        parent[skill[i]-'A'] = skill[i-1] - 'A';
    }
    
    int ans = 0;
    for (string &s : skill_trees){
        int earned[26] = {0};
        
        int s_sz = s.size();
        bool f = true;
        for (int i = 0; i < s_sz; ++i){
            if(parent[s[i]-'A'] == -1){ // 부모가없으면 무조건 배울 수 있음.
                earned[s[i]-'A'] = 1;
            }
            else{ // 부모가있으면
                if(!earned[parent[s[i]-'A']]){ // 부모가 안배웠으면 못배움
                    // cout << "s : " << s << " s[i] : " << s[i] << "\n";
                    f = false;
                    break;
                }
                else // 부모가 배웠으면 나도 배움
                    earned[s[i]-'A'] = 1;
            }
        }
        if(f)
            ++ans;
       }
                          
                        
    return ans;
}