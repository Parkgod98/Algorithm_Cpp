#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string ret = "";
    
    int sz = code.size();
    int mode = 0;
    for (int i = 0; i < sz; ++i){
        char c = code[i];
        
        if(!mode){
            if(c != '1' && i%2==0)
                ret += c;
            else if(c == '1')
                mode = !mode;
        }
        else{
            if(c != '1' && i%2 == 1)
                ret += c;
            else if(c == '1')
                mode = !mode;
        }
    }
    if(ret.size() == 0)
        return "EMPTY";
    return ret;
}