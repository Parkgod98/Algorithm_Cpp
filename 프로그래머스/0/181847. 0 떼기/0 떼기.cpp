#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int sz = n_str.size();
    
    int idx = 0;
    while(n_str[idx] == '0')
        ++idx;
    
    for (int i = idx; i < sz; ++i)
        answer += n_str[i];
    return answer;
}