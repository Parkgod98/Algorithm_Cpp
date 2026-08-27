#include <string>
#include <vector>

using namespace std;

int GetGCD(int a, int b){
    
    while(a%b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

vector<int> solution(int n, int m) {
    vector<int> ans(2,0);
    
    ans[0] = GetGCD(n,m);
    ans[1] = n*m/ans[0];
    return ans;
}