#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string my_string) {
    string answer = "";
    int visited[26] = {0};
    
    for (char &c : my_string){
        visited[tolower(c)-'a']++;
    }
    
    for (int i = 0; i < 26; ++i){
        for (int k = 0; k < visited[i]; ++k)
            answer += (i+'a');
    }
    return answer;
}