#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ans = 0;
    
    int start = 1;
    int cur = 0;
    
    int sz = s.size();
    char c = s[0];
    for (int i = 1; i < sz; ++i){
        if(s[i] == c)
            ++start;
        else
            ++cur;
        
        if(start == cur){
            ++ans;
            start = 0;
            cur = 0;
            if(i+1 < sz)
                c = s[i+1];
        }
    }
    if(start > 0)
        ++ans;
    return ans;
}