#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    int sum = 0;
    int pow = 1;
    
    for (int i = bin1.size()-1; i >= 0; --i){
        if(bin1[i] == '1'){
            sum += pow;
        }
        pow *=2;
    }
    pow = 1;
    for (int i = bin2.size()-1; i >= 0; --i){
        if(bin2[i] == '1'){
            sum += pow;
        }
        pow *=2;
    }
    if(sum == 0)
        return "0";
    
    string ans = "";
    while(sum != 0){
        ans += (sum%2 + '0');
        sum/=2;
    }
    
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}