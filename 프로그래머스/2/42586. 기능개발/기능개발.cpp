#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int sz = speeds.size();
    vector<int> complete_day(sz,0);
    
    
    vector<int> ans;
    for (int i = 0; i < sz; ++i){
        int remain = 100 - progresses[i];
        if(remain%speeds[i] == 0){
            complete_day[i] = remain/speeds[i];
        }
        else{
            complete_day[i] = remain/speeds[i]+1;
        }
    }
    
    int cnt = 1;
    int anchor = complete_day[0];
    int idx = 1;
    while(idx < sz){
        if(complete_day[idx] <= anchor){
            ++cnt;
        }
        else{
            ans.push_back(cnt);
            cnt = 1;
            anchor = complete_day[idx];
        }
        ++idx;
    }
    ans.push_back(cnt);
    return ans;
}