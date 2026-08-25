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

int solution(int a, int b) {
    int answer = 0;
    
    int gcd = GetGCD(a,b);
    
    a /= gcd;
    b /= gcd;
    
    while(1){
        bool f = false;
        if(b%2 == 0){
            b /=2;
            f = true;
        }
        if(b%5 == 0){
            b /= 5;
            f = true;
        }
        if(b == 1)
            return 1;
        
        if(!f)
            break;
    }
    return 2;
    return answer;
}