#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    
    int sz = parts.size();
    
    for (int i = 0; i < sz; ++i){
        
        int s = parts[i][0];
        int e = parts[i][1];
        
        for (s; s <= e; ++s){
            answer+= my_strings[i][s];
        }
    }
    return answer;
}