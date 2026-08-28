#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    int cur = 0;
    int idx = s.find(' ',cur);
    int prev = 0;
    
    while(idx != string::npos){
        int k = 0;
        for (int i = prev; i < idx; ++i){
            if(k%2==0){
                s[i] = toupper(s[i]);
            }
            else
                s[i] = tolower(s[i]);
            ++k;
        }
        prev = idx+1;
        idx = s.find(' ',prev);
    }
    int k = 0;
    for (int i = prev; i < s.size(); ++i){
        if(k%2==0){
            s[i] = toupper(s[i]);
        }
        else
            s[i] = tolower(s[i]);
        ++k;
    }
    return s;
}