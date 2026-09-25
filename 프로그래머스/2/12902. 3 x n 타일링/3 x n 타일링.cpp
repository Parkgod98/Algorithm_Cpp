#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

int solution(int n) {
    if(n % 2 == 1)
        return 0;

    vector<long long> v(n + 5, 0);

    v[2] = 3;
    v[4] = 11;

    for(int i = 6; i <= n; i += 2){
        v[i] = (4 * v[i-2] - v[i-4] + MOD) % MOD;
    }

    return v[n];
}