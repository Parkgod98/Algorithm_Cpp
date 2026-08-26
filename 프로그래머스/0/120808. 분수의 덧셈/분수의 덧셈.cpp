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

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    
    int bottom = denom1 * denom2;
    int upper = numer1 * denom2 + numer2*denom1;
    
    int gcd = GetGCD(bottom,upper);
    bottom /= gcd;
    upper /=gcd;
    
    answer[0] = upper;
    answer[1] = bottom;
    return answer;
}