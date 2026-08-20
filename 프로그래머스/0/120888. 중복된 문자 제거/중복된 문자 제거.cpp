#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    int visited[26] = {0};
    int visited2[26] = {0};
    bool f = false;
    for (char &c : my_string){
        if(islower(c)){
            if(visited[c-'a'] == 0){
                answer+=c;
                visited[c-'a'] = 1;
            }
        }
        else if(isupper(c)){
            if(visited2[c-'A'] == 0){
                answer+=c;
                visited2[c-'A'] = 1;
            }
        }
        else if(c == ' ' && !f){
            answer += c;
            f = true;
        }

    }
    return answer;
}