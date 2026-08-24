#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int arr[26] = {0};
    int o_cnt = spell.size();
    for (string &s : spell){
        arr[s[0]-'a'] = 1;
    }
    
    for (string &s : dic){
        
        bool f = true;
        int visited[26] = {0};
        int cnt = 0;
        for (char &c : s){
            if(!arr[c-'a']){
                f = false;
                break;
            }
            else{
                visited[c-'a']++;
                ++cnt;
                if(visited[c-'a'] != arr[c-'a']){
                    f = false;
                    break;
                }
            }
        }
        if(f && cnt == o_cnt)
            return 1;
    }
    return 2;
}