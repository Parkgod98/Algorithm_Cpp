#include <string>
#include <vector>

using namespace std;

bool CountYak(int n){
    
    int cnt = 0;
    for (int i = 1; i*i <= n; ++i){
        if(n%i == 0 && i*i != n){
            cnt += 2;
        }
        else if(i*i == n){
            cnt += 1;
        }
    }
    if(cnt >= 3)
        return true;
    return false;
}

int solution(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if(CountYak(i))
            ++cnt;
    }
    return cnt;
}