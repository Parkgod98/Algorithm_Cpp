#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int mx_len = stoi(video_len.substr(0,2))*60 + stoi(video_len.substr(3,2));
    int cur_m = stoi(pos.substr(0,2));
    int cur_s = stoi(pos.substr(3,2)) + 60*cur_m;
    
    int opsm = stoi(op_start.substr(0,2));
    int opss = stoi(op_start.substr(3,2)) + 60*opsm;
    
    int opem = stoi(op_end.substr(0,2));
    int opes = stoi(op_end.substr(3,2)) + 60*opem;
    
    if(cur_s >= opss && cur_s <= opes)
        cur_s = opes;
    for (string &com : commands){
        if(com == "next"){
            cur_s = min(cur_s+10,mx_len);
        }
        else{
            cur_s = max(cur_s-10,0);
        }
        if(cur_s >= opss && cur_s <= opes)
            cur_s = opes;
    }
    
    int m = cur_s/60;
    int s = cur_s%60;
    
    string ans = "";
    if(m<10)
        ans += "0" + to_string(m);
    else
        ans += to_string(m);
    ans += ":";
    if(s < 10)
        ans += "0" + to_string(s);
    else
        ans += to_string(s);
    return ans;
}