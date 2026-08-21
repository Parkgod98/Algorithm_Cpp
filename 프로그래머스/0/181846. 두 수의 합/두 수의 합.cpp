#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string ans = "";
    
    int aidx = a.size() -1;
    int bidx = b.size() - 1;
    int carry = 0;
    while(aidx >= 0 && bidx >= 0){
        int sum = (a[aidx--] - '0') + (b[bidx--] - '0') + carry;
        carry = sum/10;
        ans += (sum%10 + '0');
    }
    while(aidx >= 0){
        int sum = (a[aidx--] - '0') + carry;
        carry = sum/10;
        ans += (sum%10 + '0');
    }
    while(bidx >= 0){
        int sum = (b[bidx--] - '0') + carry;
        carry = sum/10;
        ans += (sum%10 + '0');
    }
    
    if(carry)
        ans += (carry + '0');
    
    reverse(ans.begin(),ans.end());
    return ans;
}