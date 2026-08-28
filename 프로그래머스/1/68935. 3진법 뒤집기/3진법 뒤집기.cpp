#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    
    int num = 0;
    while(n!=0){
        num = num*3 + n%3;
        n/=3;
    }
    
    return num;
}