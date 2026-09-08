#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    set<string> normal_words;
    set<string> spo_words;
    
    int idx = 0;
    int prev = 0;
    int sp_idx = 0;
    bool Stop = false;
    
    while(idx != string::npos){
        idx = message.find(' ',prev);
        
        if(idx == string::npos){
            idx = message.size();
            Stop = true;
        }
        
        string cur = message.substr(prev,idx-prev);
        
        while(sp_idx < (int)spoiler_ranges.size() && spoiler_ranges[sp_idx][1] < prev){
            ++sp_idx;
        }
        
        bool IsSpoiler = false;
        if(sp_idx < (int)spoiler_ranges.size()){
            int spo_start = spoiler_ranges[sp_idx][0];
            int spo_end = spoiler_ranges[sp_idx][1];
            
            if(!(prev > spo_end || idx-1 < spo_start)){
                IsSpoiler = true;
            }
            
        }
        
        if(IsSpoiler){
            spo_words.insert(cur);
        }
        else
            normal_words.insert(cur);
        
        if(Stop)
            break;
        prev = idx+1;
    }
    
    int ans = 0;
    for (const string &s : spo_words){
        if(normal_words.find(s) == normal_words.end())
            ++ans;
    }
    return ans;
}