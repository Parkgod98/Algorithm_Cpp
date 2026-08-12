#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    int sz = numLog.size();
    for (int i = 0; i < sz - 1; ++i){
        int t = numLog[i+1] - numLog[i];
        if(t == 1){
            answer += "w";
        }
        else if(t == -1){
            answer += "s";
        }
        else if(t == 10){
            answer += "d";
        }
        else if(t == -10){
            answer += "a";
        }
    }
    return answer;
}