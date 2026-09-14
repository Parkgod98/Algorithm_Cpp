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

int solution(vector<int> arr) {
    
    int s = 1;
    
    for (int &n : arr){
        int gcd = GetGCD(s,n);
        s *= n;
        s/=gcd;
    }
    return s;
}