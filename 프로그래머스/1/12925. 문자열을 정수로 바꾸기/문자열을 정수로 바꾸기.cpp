#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    int n = 0;
    bool mf = false;
    for (char &c : s){
        if(isdigit(c))
            n = n * 10 + (c-'0');
        else if(c == '+')
            mf = false;
        else if(c == '-')
            mf = true;
    }
    if(mf)
        n = -n;
    return n;
}