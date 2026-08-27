#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    int sz = s.size();
    if(sz%2 == 1)
        return s.substr(sz/2,1);
    
    
    return s.substr(sz/2-1,2);
}