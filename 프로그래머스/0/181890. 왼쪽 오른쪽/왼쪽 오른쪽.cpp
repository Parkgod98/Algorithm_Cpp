#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    int sz = str_list.size();
    
    for (int i = 0; i < sz; ++i){
        if(str_list[i] == "l"){
            
            for (int k = 0; k < i; ++k)
                answer.push_back(str_list[k]);
            break;
        }
        else if(str_list[i] == "r"){
            for (int k = i+1; k < sz; ++k)
                answer.push_back(str_list[k]);
            break;
        }
    }
    return answer;
}