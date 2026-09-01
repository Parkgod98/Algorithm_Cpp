#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    int skiped[26] = {0};
    for (char &c : skip)
        skiped[c-'a'] = 1;
    
    
    for (char &c : s){
        
        int start = c-'a';
        
        int cnt = 0;
        while(1){
            if(!skiped[start])
                ++cnt;
            start = (start+1)%26;
            while(skiped[start])
                start = (start+1)%26;
            if(cnt == index)
                break;
        }
        c = 'a' + start;
    }
    
    return s;
}