#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> ans;
    
    vector<int> arr(26,200);
    for (string &s : keymap){
        
        int sz = s.size();
        for (int i = 0; i < sz; ++i){
            arr[s[i]-'A'] = min(arr[s[i]-'A'],i+1);
        }
    }
    
    for (string &s : targets){
        
        int sz = s.size();
        int sum = 0;
        for (int i = 0; i < sz; ++i){
            if(arr[s[i]-'A'] == 200){
                sum = -1;
                break;
            }
            else
                sum += arr[s[i]-'A'];
        }
        ans.push_back(sum);
    }
    
    
    return ans;
}