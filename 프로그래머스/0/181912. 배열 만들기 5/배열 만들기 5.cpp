#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    int sz = intStrs.size();
    for (int i = 0; i < sz; ++i){
        int n = stoi(intStrs[i].substr(s,l));
        
        if(n> k)
            answer.push_back(n);
    }
    return answer;
}