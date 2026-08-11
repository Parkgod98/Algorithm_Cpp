#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string word;
    for (char &c : my_string){
        if(c == ' ' && word.size() > 0){
            answer.push_back(word);
            word.clear();
            continue;
        }
        else if(c != ' ')
            word+=c;
    }
    if(word.size() > 0)
        answer.push_back(word);
    return answer;
}