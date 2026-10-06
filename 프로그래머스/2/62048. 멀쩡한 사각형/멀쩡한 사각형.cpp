#include <cmath>

using namespace std;

long long GetGCD(long long a, long long b){
    while(a%b != 0){
        long long tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

long long solution(int w,int h) {
    long long total = (long long)w * h;
    
    total -= (w+h - 1);
        
    return total + GetGCD(w,h)-1;
}