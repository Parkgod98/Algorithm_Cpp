#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    int num1[10] = {0};
    int num2[10] = {0};
    
    for (char &c : X)
        num1[c-'0']++;
    for (char &c : Y)
        num2[c-'0']++;
    
    string ans = "";
    for (int i = 9; i >= 0; --i){
        int mn = min(num1[i],num2[i]);
        
        for (int k = 0; k < mn; ++k)
            ans += to_string(i);
    }
    
    if(ans.empty())
        return "-1";
    else if(ans[0] == '0')
        return "0";
    return ans;
}