#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    int idx = myString.find(pat);
    
    while(1){
        int k = myString.find(pat,idx+1);
        if(k == string::npos)
            break;
        idx = k;
    }
    
    answer = myString.substr(0,idx+pat.size());
    return answer;
}