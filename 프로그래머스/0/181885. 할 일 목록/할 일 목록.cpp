#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    
    
    int sz = finished.size();
    for(int i = 0; i < sz; ++i){
        if(!finished[i])
            answer.push_back(todo_list[i]);
    }
    return answer;
}