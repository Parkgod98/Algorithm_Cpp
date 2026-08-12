#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int sz = myString.size();   
    
    int idx = 0;
    
    while(idx < sz){
        idx = myString.find(pat,idx);
        if(idx == string::npos)
            break;
        ++answer;
        idx++;
    }
    return answer;
}