#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int cnt = 0;
    
    vector<string> available = {"aya", "ye", "woo", "ma"};
    for (string &s : babbling){
        int sz = s.size();
        for (string &a : available){
            int idx = s.find(a);
            if(idx == string::npos)
                continue;
            
            sz -= a.size();
        }
        if(sz == 0)
            ++cnt;
        
        
    }
    return cnt;
}