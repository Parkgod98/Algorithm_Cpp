#include <string>
#include <vector>

using namespace std;

bool CountYak(int n){
    for (int i = 2; i*i <= n; ++i){
        if(n%i == 0)
            return true;
    }
    return false;
}

int solution(int n) {
    int cnt = 0;
    for (int i = 4; i <= n; ++i){
        if(CountYak(i))
            ++cnt;
    }
    return cnt;
}