#include <string>
#include <vector>

using namespace std;

int Cnt(int n){
    
    int cnt = 0;
    for (int i = 1; i * i <= n; ++i){
        if(n%i == 0){
            if(n/i == i)
                cnt+=1;
            else
                cnt+=2;
        }
    }
    return cnt;
}

int solution(int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; ++i){
        if(Cnt(i)%2 == 0)
            sum += i;
        else
            sum -=i;
    }
    return sum;
}