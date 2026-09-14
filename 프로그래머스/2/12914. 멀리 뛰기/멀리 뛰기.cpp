#include <string>
#include <vector>

using namespace std;
/*
1 - > 1 == 1
2 - >  1 + 1 , 2 == 2
3 - > 1 + 1 + 1 , 2 + 1,  1 + 2 == 3
4 -> 1 + 1 + 1 + 1, 2 + 1 + 1 ,1 + 2 + 1, 1 + 1 + 2, 2 + 2 == 5
*/
long long solution(int n) {
    int ans[2001] = {0};
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; ++i)
        ans[i] = (ans[i-1] + ans[i-2])%1234567;
    
    return (long long)ans[n];
}