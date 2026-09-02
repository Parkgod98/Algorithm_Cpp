#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int ans = 0;
    
    while(1){
        int start = 1;
        int not_start = 0;

        char c = s[0];
        int sz = s.size();
        
        bool f = false;
        for (int i = 1; i < sz; ++i){
            if(c == s[i])
                ++start;
            else
                ++not_start;

            if(start == not_start){
                if(i+1 < sz)
                    s = s.substr(i+1);
                else
                    f = true;
                break;
            }
        }
        if(start == not_start){
            ++ans;
            if(f)
                break;
        }
        else{
            ++ans;
            break;
        }
    }
    
    return ans;
}