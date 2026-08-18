#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    
    int sz = my_str.size();
    int cnt = 0;
    string word = "";
    for (int i = 0; i < sz; ++i){
        if(cnt == n){
            cnt = 0;
            answer.push_back(word);
            word.clear();
        }
        ++cnt;
        word += my_str[i];
    }
    answer.push_back(word);
    return answer;
}