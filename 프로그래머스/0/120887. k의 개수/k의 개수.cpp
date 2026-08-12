#include <string>
#include <vector>

using namespace std;

int Count(int i, int k){
    
    int cnt = 0;
    while(i!=0){
        if(i%10 == k)
            ++cnt;
        i/=10;
    }
    return cnt;
}

int solution(int i, int j, int k) {
    int cnt = 0;
    for (i; i <=j; ++i){
        cnt += Count(i,k);
    }
    return cnt;
}