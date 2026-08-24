#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    bool fail = false;
    bool wrong_pw = false;
    
    for (vector<string> &v : db){
        bool a = (v[0] == id_pw[0]);
        bool b = (v[1] == id_pw[1]);
        if(a&&b)
            return "login";
        else if(a && !b)
            wrong_pw = true;
        else if(!a)
            fail = true;
    }
    
    if(wrong_pw)
        return "wrong pw";
    return "fail";
}