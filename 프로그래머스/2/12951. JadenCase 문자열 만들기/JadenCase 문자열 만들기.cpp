#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {
    
    char prev = ' ';
    for (char &c : s){
        
        if(prev == ' ' && islower(c)){
            c = toupper(c);
        }
        else if(prev != ' ' && isupper(c)){
            c = tolower(c);
        }
        
        prev = c;
    }
    return s;
}