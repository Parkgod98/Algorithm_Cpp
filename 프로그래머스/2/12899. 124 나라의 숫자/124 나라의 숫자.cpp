#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char arr[3] = {'1','2','4'};

string solution(int n) {
    
    string ans = "";
    while(n!=0){
        --n;
        ans += arr[(n%3)];
        n/=3;
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}