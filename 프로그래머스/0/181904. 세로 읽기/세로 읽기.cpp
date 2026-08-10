#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    int sz = my_string.size();
    
    for (int i = c-1; i < sz; i+=m){
        answer += my_string[i];
    }
    return answer;
}