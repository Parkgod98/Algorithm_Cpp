#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    
    int sz = seoul.size();
    for (int i = 0; i < sz; ++i){
        if(seoul[i] == "Kim"){
            string ans = "김서방은 " + to_string(i) + "에 있다";
            return ans;
        }
    }
}