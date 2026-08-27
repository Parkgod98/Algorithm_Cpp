#include <string>
#include <vector>

using namespace std;

string solution(int n) {

    string ans = "";
    
    for (int i = 0; i < n; ++i){
        if(i%2 == 0)
            ans += "수";
        else
            ans += "박";
    }
    return ans;
}