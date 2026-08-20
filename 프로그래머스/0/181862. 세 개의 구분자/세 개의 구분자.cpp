#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    
    string word = "";
    
    for (char &c : myStr){
        if((c == 'a' || c == 'b' || c == 'c')){
            if(word.empty())
                continue;
            answer.push_back(word);
            word.clear();
            continue;
        }
        word += c;
    }
    if(!word.empty())
        answer.push_back(word);
    
    if(answer.size() == 0)
        answer.push_back("EMPTY");
    return answer;
}