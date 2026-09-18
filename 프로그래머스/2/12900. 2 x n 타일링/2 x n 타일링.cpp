#include <string>
#include <vector>

using namespace std;
/*
1 -> 1
2 - > 2
3 -> 3



*/

int solution(int n) {
    int answer = 0;
    
    vector<int> v(n+4,0);
    v[1] = 1;
    v[2] = 2;
    
    for (int i = 3; i <= n; ++i)
        v[i] = (v[i-1] + v[i -2])%1000000007;
    return v[n];
}