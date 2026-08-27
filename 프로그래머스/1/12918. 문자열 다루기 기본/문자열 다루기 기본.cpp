#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool solution(string s) {
    
    if((s.size() == 4 || s.size() == 6)){
        for (char &c : s){
            if(!isdigit(c))
                return false;
        }
        return true;
    }
    
    return false;
}