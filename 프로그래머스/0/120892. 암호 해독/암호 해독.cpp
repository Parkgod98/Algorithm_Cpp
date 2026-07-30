#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    int sz = cipher.size();
    for (int i = code-1; i < sz; i += code)
        answer += cipher[i];
    return answer;
}