#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool HasThree(int n){
    while(n!=0){
        if(n%10 == 3)
            return true;
        n/=10;
    }
    return false;
}

int solution(int n) {
    int start = 1;
    int second = 1;
    
    while(start < n){
        ++start;
        ++second;
        
        while(second%3 == 0 || HasThree(second))
            ++second;
    }
    return second;
}