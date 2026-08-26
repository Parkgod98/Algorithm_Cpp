#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {

    set<string> s;
    for (string &ss : s1)
        s.insert(ss);
    
    int cnt = 0;
    for (string &ss : s2){
        if(s.find(ss) != s.end())
            ++cnt;
    }
    return cnt;
}