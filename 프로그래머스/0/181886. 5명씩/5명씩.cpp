#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    
    int sz = names.size();
    for (int i = 0; i < sz; i += 5)
        answer.push_back(names[i]);
    return answer;
}