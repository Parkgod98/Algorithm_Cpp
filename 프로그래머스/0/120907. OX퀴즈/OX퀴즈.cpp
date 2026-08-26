#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (string &s : quiz){
        vector<string> v;
        
        int prev = 0;
        int cur_idx = s.find(' ');
        v.push_back(s.substr(prev,cur_idx));
        prev = cur_idx;
        while(prev != string::npos){
            cur_idx = s.find(' ', prev+1);
            v.push_back(s.substr(prev+1,cur_idx-prev-1));
            prev = cur_idx;
        }
        
        int sz = v.size();
        int sum = stoi(v[0]);
        sum = stoi(v[0]);
        for (int i = 0; i < sz -1; ++i){
            if(v[i] == "+" || v[i] == "-" || v[i] == "="){
                if(v[i] == "="){
                    if(sum == stoi(v[i+1]))
                        answer.push_back("O");
                    else
                        answer.push_back("X");
                }
                else if(v[i] == "+"){
                    sum += stoi(v[i+1]);
                }
                else
                    sum -= stoi(v[i+1]);
            }
        }
    }
    return answer;
}