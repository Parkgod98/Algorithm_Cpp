#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int ans = 0;
    vector<string> s = {"aya","ye","woo","ma"};
    
    for (string &b : babbling){
        
        int cur = 0;
        int prev = -1;
        
        bool f = true;
        int sz = b.size();
        while(cur < sz){
            bool found = false;
            for (int i = 0; i < 4; ++i){
                if(b.substr(cur,s[i].size()) == s[i] && prev != i){
                    cur += (int)s[i].size();
                    prev = i;
                    found = true;
                }
                else if(prev == i){
                    f = false;
                }
            }
            if(!found)
                break;
        }
        if(f && (cur == sz))
            ++ans;
    }
    return ans;
}