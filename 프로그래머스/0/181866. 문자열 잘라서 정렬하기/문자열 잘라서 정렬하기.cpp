#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string word = "";
    
    int idx = 0;
    int sz = myString.size();
    while(idx < sz){
        if(myString[idx] == 'x' && word.size() > 0){
            answer.push_back(word);
            word.clear();
        }
        else if(myString[idx] != 'x'){
            word += myString[idx];
        }
        ++idx;
    }
    
    if(word.size() > 0)
        answer.push_back(word);
    
    sort(answer.begin(),answer.end());
    return answer;
}